#include "ShiftRegister.h"
#include "Demux.h"

const int BLEModule_TX = 0;
const int BLEMocule_RX = 1;
ShiftRegister upside_IRreceive = ShiftRegister(2, 3, 4);
ShiftRegister bottomside_IRreceive = ShiftRegister(5, 6, 7);
ShiftRegister upside_IRsend = ShiftRegister(8, 9, 10);
const int ICSP_MOSI = 11;
const int ICSP_MISO = 12;
const int ICSP_SCK = 13;
ShiftRegister bottomside_IRsend = ShiftRegister(14, 15, 16);
Demux demux = Demux(17, 18, 19);

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(BLEModule_TX, OUTPUT);
	pinMode(BLEModule_TX, OUTPUT);
	pinMode(ICSP_MOSI, OUTPUT);
	pinMode(ICSP_MISO, OUTPUT);
	pinMode(ICSP_SCK, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
