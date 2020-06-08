LiquidCrystal lcd(31, 33, 35, 37, 39, 41);
extern bool midiThru;
extern IPAddress ip;
int errorNumber = 21;
extern float cueNumber;
String strcueNumber;
 
void lcdInit() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Midi Gate v.1.2");
  lcd.setCursor(0,1);
  lcd.print(ip);
  delay(5000);
  lcd.clear();
}

void lcdStatus() {
  if (errorNumber == 11) {
     lcd.setCursor(0,0);
    lcd.print("SD CARD ERROR");
    lcd.setCursor(0,1);
    lcd.print("NO SD CARD READ");
    return;
  }
  if (errorNumber == 12) {
    lcd.setCursor(0,0);
    lcd.print("SD CARD ERROR");
    lcd.setCursor(0,1);
    lcd.print("CANNOT READ CARD");
    return;
  }
  if (midiThru) {
    lcd.setCursor(0,0);
    lcd.print("Midi Thru: ON ");
  } else {
    lcd.setCursor(0,0);
    lcd.print("Midi Thru: OFF");
  }
  lcd.setCursor(0,1);
  lcd.print("LAST:");
  lcd.setCursor(6,1);
  strcueNumber = String(cueNumber);
  lcd.print(strcueNumber);
  lcd.setCursor(6 + strcueNumber.length(),1);
  for (int i = 0; i < strcueNumber.length(); i++) { //CLEAR REST OF LCD
    lcd.print(" "); 
  }
}
