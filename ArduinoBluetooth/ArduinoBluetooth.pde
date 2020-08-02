import processing.serial.*;

Serial btserial; 

PShape l, r, flecha;
float varin;
boolean over;
boolean click;
float pos0=2, pos1=2, pos2=2, pos3=2, pos4=2, pos5=2, pos6=2, pos7=2, pos8=2;
float datain, senIn, datasen;
String bufferin, ID="uno", ID2="dos", data, data2;

void setup() {
  btserial=new Serial(this, Serial.list()[1], 9600);

  printArray(Serial.list());
}

void draw() {
  
  if (btserial.available()>0)
  {
    bufferin=null;
    bufferin=btserial.readStringUntil('\n');
    if (bufferin!=null) {
      println("ID= "+ID+" ID2= "+ID2);
      if (bufferin.substring(0, 1).equals("S")) { //S180 D29
        ID="S";
        data=bufferin.substring(1);
        float indata=float(data);
        datain=indata;
        btserial.clear();
      }
      if (bufferin.substring(0, 1).equals("D")) {
        ID2="D";
        data2=bufferin.substring(1);
        float indata2=float(data2);
        senIn=indata2;
        println(datain);
        btserial.clear();
      }
    }
  }
}  
