//UDP READ
// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];  // buffer to hold incoming packet,
// An EthernetUDP instance to let us send and receive packets over UDP
extern EthernetUDP Udp;

void oscRead() {
  int packetSize = Udp.parsePacket();
  String oscMessage;
  if (packetSize) {
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    oscMessage = String(packetBuffer);
    oscMessage.toUpperCase();
    //    Serial.println(oscMessage);
  }
  if (oscMessage == "/MIDI/ON") {
    LED_state[1] = 1;
    midiThru = true;
    fromDeck = true;
  } else if (oscMessage == "/MIDI/OFF") {
    LED_state[1] = 0;
    midiThru = false;
    fromDeck = true;
  }
}
