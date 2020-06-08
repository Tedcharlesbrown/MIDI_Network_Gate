//DEFINITIONS
#define LED_GREEN 28 //D6
#define LED_RED 30 //D7

extern bool button1State, button2State, button3State, midiThru, midiRead, sdRead;
extern String midiMessageSend;

void hardwareInit() {
  // LED outputs
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, HIGH);
}

void sdCardTest() {
  // initialize SD card
  if (!SD.begin(4)) {
    sdRead = false;
    return;
  }
  // check for index.htm file
  if (!SD.exists("index.htm")) {
    sdRead = false;
    return;
  }
  sdRead = true;
}

void ledIndicator() {
  // WHEN MIDI IS READ
  if (sdRead) {
    if (midiRead) {
      for (int i = 0; i < 5000; i++) {
        digitalWrite(LED_RED, LOW);
      }
    }
    digitalWrite(LED_RED, HIGH);
    // STATUS INDICATION
    int blinkStatusTime;
    if (midiThru) {
      blinkStatusTime = 250;
    } else if (!midiThru) {
      blinkStatusTime = 2000;
    }
    if (millis() % blinkStatusTime <= blinkStatusTime / 2) {
      digitalWrite(LED_GREEN, LOW);
    } else {
      digitalWrite(LED_GREEN, HIGH);
    }
    // IF SD CARD IS NOT READ
  } else {
    for(int i = 0; i < 2; i++) {
      digitalWrite(LED_RED, LOW);
      delay(200);
      digitalWrite(LED_RED, HIGH);
      delay(200);
    }
    delay(1000);
  }
}
