//*************************************************************************
// DTMF_DECODER.ino
// Read DTMF codes frome MT8870 module  Chamal Liyange 08/29/2019/ Thank you Geroge Thomas
//*************************************************************************

byte DTMFdata;    // Data read from DTMF module
int STQ = 3;     //  DTMF Module STQ Pin connects to Arduino Digital Pin 3
int Q4 = 4;      //  DTMF Module Q4  Pin connects to Arduino Digital Pin  4
int Q3 = 5;      //  DTMF Module Q3  Pin connects to Arduino Digital Pin  5
int Q2 = 6;      //  DTMF Module Q2  Pin connects to Arduino Digital Pin  6
int Q1 = 7;      //  DTMF Module Q3  Pin connects to Arduino Digital Pin  7

void setup() {

  //set Digital I/o pin functions
  pinMode(STQ, INPUT);
  pinMode(Q4, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q2, INPUT);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

void loop() {
  DTMFdata = 0;

  // IF STQ is High a DTMF tone is present.check 4-bit code.
  if (digitalRead(STQ) == HIGH) {
    if (digitalRead(Q1) == HIGH) {  // if Q1 HIGH add 1 to DTMFdata
      DTMFdata = DTMFdata + 1;
    }
    if (digitalRead(Q2) == HIGH) {  // if Q2 HIGH add 2 to DTMFdata
      DTMFdata = DTMFdata + 2;
    }
    if (digitalRead(Q3) == HIGH) {  // if Q3 HIGH add 4 to DTMFdata
      DTMFdata = DTMFdata + 4;
    }
    if (digitalRead(Q4) == HIGH) {  // if Q4 HIGH add 8 to DTMFdata
      DTMFdata = DTMFdata + 8;
    }


    Serial.println(DTMFdata); // print DTMFdata


  }
}
