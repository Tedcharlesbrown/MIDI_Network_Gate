//MIDI LIBRARIES
#include <MsTimer2.h>
#include <MIDI.h>
//ETHERNET LIBRARIES
#include <Ethernet.h>
#include <EthernetUdp.h>
//SD LIBRARIES
#include <SD.h>
#include <SPI.h>
//LCD LIBRARY
#include <LiquidCrystal.h>
//MY FILES
#include "A_MidiNumberConvert.h"
#include "B_MidiSend.h"
#include "C_Hardware.h"
#include "D_Network.h"
#include "E_OSC.h"
#include "F_LCD.h"

#define DEVICE_POWER 53

EthernetUDP Udp;

//VARIABLES
String midiMessageSend = "empty";
bool button1State, button2State, button3State;
bool midiThru, fromDeck;
bool midiRead, sdRead;
int oscMidiThru = 0;

void setup() {
  Serial.begin(9600);
  Serial1.begin(31250);

  pinMode(DEVICE_POWER, OUTPUT); // FOR MIDI THRU - IF DEVICE HAS NO POWER

  Ethernet.begin(mac, ip, gateway, subnet);  // initialize Ethernet device
  server.begin();           // start to listen for clients
  Udp.begin(8888);

  sdCardTest();
  hardwareInit();

  MIDI.begin(MIDI_CHANNEL_OMNI);
  midiThru = true;
  LED_state[1] = 1;

  lcdInit();
}

void loop() {
  midiThruIO();

  ledIndicator();
  midiIN();

  oscRead();
  webPage();
  
  lcdStatus();

  digitalWrite(DEVICE_POWER, HIGH); // FOR MIDI THRU - IF DEVICE HAS NO POWER
}
