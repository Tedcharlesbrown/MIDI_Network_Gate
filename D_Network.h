#include <Ethernet.h>

//HTML TEST
#define REQ_BUF_SZ   60
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 70); // IP address, may need to change depending on network
IPAddress gateway(192, 168, 0, 255);
IPAddress subnet(255, 255, 255, 0);
EthernetServer server(80);  // create a server at port 80
File webFile;               // the web page file on the SD card
char HTTP_req[REQ_BUF_SZ] = {0}; // buffered HTTP request stored as null terminated string
char req_index = 0;              // index into HTTP_req buffer
boolean LED_state[2] = {0}; // stores the states of the LEDs
boolean webChange;

extern String midiMessageSend;
extern int oscMidiThru;
extern bool fromDeck;

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind) {
  char found = 0;
  char index = 0;
  char len;

  len = strlen(str);

  if (strlen(sfind) > len) {
    return 0;
  }
  while (index < len) {
    if (str[index] == sfind[found]) {
      found++;
      if (strlen(sfind) == found) {
        return 1;
      }
    } else {
      found = 0;
    }
    index++;
  }
  return 0;
}

// checks if received HTTP request is switching on/off LEDs
// also saves the state of the LEDs
void SetLEDs(void) {
  String strSource;
  if (fromDeck) {
    strSource = "[DECK] ";
  } else if (!fromDeck) {
    strSource = "[HTML] ";
  }
  if (StrContains(HTTP_req, "MIDI=1") || oscMidiThru > 0) {
    LED_state[1] = 1;  // save LED state
    midiMessageSend = strSource + "- [THRU] [ ON ]";
    midiThru = true;
    webChange = true;
  } else if (StrContains(HTTP_req, "MIDI=0") || oscMidiThru < 0) {
    midiMessageSend = strSource + "- [THRU] [ OFF ]";
    LED_state[1] = 0;  // save LED state
    midiThru = false;
    webChange = true;
  }
  if (StrContains(HTTP_req, "SEND=GO")) {
    controlSend(devALL, form1, GO);
    midiMessageSend = "[HTML] - [ GO ]";
    webChange = true;
  } else if (StrContains(HTTP_req, "SEND=PAUSE")) {
    controlSend(devALL, form1, STOP);
    midiMessageSend = "[HTML] - [STOP]";
    webChange = true;
  } else if (StrContains(HTTP_req, "SEND=NOTE")) {
    midiMessageSend = "[HTML] - NOTE 1";
    webChange = true;
    noteSend(ch1ON, num0, 127);
    delay(100);
    noteSend(ch1OFF, num0, 127);
  }
  if (webChange || fromDeck) {
    for (int i = 0; i < 10000; i++) {
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED, LOW);
    }
    for (int i = 0; i < 10000; i++) {
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_RED, HIGH);
    }
    for (int i = 0; i < 10000; i++) {
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED, LOW);
    }
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, HIGH);
  }
  webChange = false;
  oscMidiThru = 0;
  fromDeck = false;
}


// send the XML file with analog values, switch status
//  and LED status
void XML_response(EthernetClient cl) {
  int analog_val;            // stores value read from analog inputs
  int count;                 // used by 'for' loops
  cl.print("<?xml version = \"1.0\" ?>");
  cl.print("<inputs>");
  cl.print("<midiThru>");
  if (LED_state[1]) {
    cl.print("on");
  } else {
    cl.print("off");
  }
  cl.print("</midiThru>"); //ln

  cl.print("<midiMessage>");
  if (midiMessageSend != "empty") {
    Serial.println(midiMessageSend);
  }
  cl.print(midiMessageSend);
  midiMessageSend = "empty";
  cl.print("</midiMessage>");

  cl.print("</inputs>");
}

// sets every element of str to 0 (clears array)
void StrClear(char *str, char length) {
  for (int i = 0; i < length; i++) {
    str[i] = 0;
  }
}

void webPage() {
  EthernetClient client = server.available();  // try to get client

  if (client) {  // got client?
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {   // client data available to read
        char c = client.read(); // read 1 byte (character) from client
        // limit the size of the stored received HTTP request
        // buffer first part of HTTP request in HTTP_req array (string)
        // leave last element in array as 0 to null terminate string (REQ_BUF_SZ - 1)
        if (req_index < (REQ_BUF_SZ - 1)) {
          HTTP_req[req_index] = c;          // save HTTP request character
          req_index++;
        }
        // last line of client request is blank and ends with \n
        // respond to client only after last line received
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          // remainder of header follows below, depending on if
          // web page or XML page is requested
          // Ajax request - send XML file
          if (StrContains(HTTP_req, "ajax_inputs")) {
            // send rest of HTTP header
            client.println("Content-Type: text/xml");
            client.println("Connection: keep-alive");
            client.println();
            SetLEDs();
            // send XML file containing input states
            XML_response(client);
          }
          else {  // web page request
            // send rest of HTTP header
            client.println("Content-Type: text/html");
            client.println("Connection: keep-alive");
            client.println();
            // send web page
            webFile = SD.open("index.htm");        // open web page file
            if (webFile) {
              while (webFile.available()) {
                client.write(webFile.read()); // send web page to client
              }
              webFile.close();
            }
          }
          // display received HTTP request on serial port
          // Serial.print(HTTP_req);
          // reset buffer index and all buffer elements to 0
          req_index = 0;
          StrClear(HTTP_req, REQ_BUF_SZ);
          break;
        }
        // every line of text received from the client ends with \r\n
        if (c == '\n') {
          // last character on line of received text
          // starting new line with next character read
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // a text character was received from client
          currentLineIsBlank = false;
        }
      } // end if (client.available())
    } // end while (client.connected())
    delay(1);      // give the web browser time to receive the data
    client.stop(); // close the connection
  } // end if (client)
}
