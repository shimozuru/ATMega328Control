#include "ShiftRegister.h"
#include "Demux.h"

const int BLEModule_TX = 0;
const int BLEModule_RX = 1;
ShiftRegister IRreceive_upside = ShiftRegister(2, 3, 4);
ShiftRegister IRreceive_bottomside = ShiftRegister(5, 6, 7);
ShiftRegister IRsend_upside = ShiftRegister(8, 9, 10);
ShiftRegister IRsend_bottomside = ShiftRegister(14, 15, 16);
const int ICSP_MOSI = 11;
const int ICSP_MISO = 12;
const int ICSP_SCK = 13;
Demux demux = Demux(17, 18, 19);
const int readPin = 7;

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(BLEModule_TX, INPUT);
	pinMode(BLEModule_RX, OUTPUT);
	pinMode(ICSP_MOSI, OUTPUT);
	pinMode(ICSP_MISO, OUTPUT);
	pinMode(ICSP_SCK, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
