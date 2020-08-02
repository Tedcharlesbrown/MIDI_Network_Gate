MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

#define USE_SERIAL_PORT Serial1

extern bool midiThru, midiRead, sdRead;
extern String midiMessageSend;

int cueLengthCheck = 2;
int cueCounter;
float cueNumber, lastCue;

void midiDecode() {
  if (MIDI.getType() == 0xF0) { //IF ITS A SYS EXCLUSIVE
    midiMessageSend = "[SYSX]";
    byte printMe[MIDI.getSysExArrayLength()];
    for (int i = 0; i < MIDI.getSysExArrayLength(); i++) { //GET AND STORE THAT ARRAY
      printMe[i] = MIDI.getSysExArray()[i];
      midiMessageSend += " " + String(printMe[i], HEX);
    }
    midiMessageSend.toUpperCase();
    //    if (midiMessageSend.substring(7, 12) == "F0 7F" || midiMessageSend.substring(8, 13) == "F0 7F") {
    if (midiMessageSend.substring(14, 19) == "2 1 1" || midiMessageSend.substring(15, 20) == "2 1 1") { //NEEDS TO IGNORE BOTH F0 7F (01) 02 (01) AS THESE CAN BE DIFFERENT
      if (MIDI.getSysExArrayLength() == 7) { //IF ITS JUST A GENERIC GO
        midiMessageSend = "[MIDI] - [ GO ]";
      } else if (MIDI.getSysExArrayLength() > 7) { //IF IT HAS CUE INFORMATION
        Serial.println();
        String midiMessageSubstring = midiMessageSend.substring(20, midiMessageSend.length() - 8); // TAKE JUST THAT CUE INFORMATION
        if (midiMessageSubstring.substring(0, 1) != " ") { //EXCEPTION IF MESSAGE CONTAINS 7F
          midiMessageSubstring = midiMessageSubstring.substring(1, midiMessageSend.length());
        }
        midiMessageSubstring.trim();
        while (MIDI.getSysExArrayLength() > cueLengthCheck) { //SETTING UP TO GET RID OF MIDI INFORMATION
          cueLengthCheck += 3;
          cueCounter++;
        }
        for (int i = 0; i < cueCounter; i++) { //REMOVES EXTRANIOUS MIDI INFORMATION - 0,1 - 1,2 - 2,2....
          int removeAmount;
          if (i < 1) {
            removeAmount = 1;
          } else {
            removeAmount = 2;
          }
          midiMessageSubstring.remove(i, removeAmount);
        }
        for (int i = 0; i < midiMessageSubstring.length(); i++) { //IF CONTAINS DECIMAL POINT (E) - REPLACE WITH (.)
          if (midiMessageSubstring.charAt(i) == 'E') {
            midiMessageSubstring.setCharAt(i, '.');
          }
          if (midiMessageSubstring.charAt(i) == ' ') { //IF ODD NUMBER, DELETE EMPTY SPACE AND DELIMINATOR
            midiMessageSubstring.remove(i, 2);
          }
        }
        cueNumber = midiMessageSubstring.toFloat();
        midiMessageSend = "[MIDI] - [ GO ] CUE [ ";
        midiMessageSend += midiMessageSubstring + " ]"; // <------- HERE IS WHERE NUMBER IS STORED
      }
    } else if (midiMessageSend.substring(14, 19) == "2 1 2" || midiMessageSend.substring(15, 20) == "2 1 2") { //IF CONTAINS "PAUSE"
      midiMessageSend = "[MIDI] - [STOP]";
    }
    return;
  } else if (MIDI.getType() == 0x80) { // IF ITS A NOTE OFF
    midiMessageSend = "[MIDI] - [NTOF]";
  } else if (MIDI.getType() == 0x90) { // IF ITS A NOTE ON
    midiMessageSend = "[MIDI] - [NTON]";
  }
  midiMessageSend += " CH [ " + String(MIDI.getChannel()) + " ] NOTE [ " + String(MIDI.getData1()) + " ]";
  midiMessageSend.toUpperCase();
}

void midiForwardOnly() {
  Serial.print("CURRENT");
  Serial.println(cueNumber);
  Serial.print("LAST");
  Serial.println(lastCue);
  if (cueNumber <= lastCue) {
    Serial.println("DO NOT SEND");
  }
  lastCue = cueNumber;
}

void midiIN() {
  if (MIDI.read()) {
    midiRead = true;
    midiDecode();
    //    midiForwardOnly(); // <------------ SEND FORWARD MESSAGES ONLY

  } else {
    midiRead = false;
  }
}

void midiThruIO() {
  if (midiThru) {
    MIDI.turnThruOn();
  } else if (!midiThru) {
    MIDI.turnThruOff();
  }
}

void noteSend(int noteIO, int note, int velocity) {
  Serial1.write(noteIO);//send note on or note off command
  Serial1.write(note);//send pitch data
  Serial1.write(velocity);//send velocity data
}

void controlSend(int device, int format, int command) {
  Serial1.write(byte(0xF0));
  Serial1.write(byte(0x7F));
  Serial1.write(byte(device));
  Serial1.write(byte(0x02));
  Serial1.write(byte(format));
  Serial1.write(byte(command));
  Serial1.write(byte(0xF7));
}

void controlSend(int device, int format, int command, int cueNumber, int cueList) {
  Serial1.write(byte(0xF0));
  Serial1.write(byte(0x7F));
  Serial1.write(byte(device));
  Serial1.write(byte(0x02));
  Serial1.write(byte(format));
  Serial1.write(byte(command));
  Serial1.write(byte(cueNumber));
  Serial1.write(byte(0x00));
  Serial1.write(byte(cueList));
  Serial1.write(byte(0xF7));
}
