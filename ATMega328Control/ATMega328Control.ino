#include "ShiftRegister.h"
#include "Demux.h"
#include "stl_list.h"

//�f�W�^���s��
const int BLEModule_TX = 0;
const int BLEModule_RX = 1;
const int ICSP_MOSI = 11;
const int ICSP_MISO = 12;
const int ICSP_SCK = 13;
ShiftRegister IRreceive_upside = ShiftRegister(2, 3, 4);
ShiftRegister IRreceive_bottomside = ShiftRegister(5, 6, 7);
ShiftRegister IRsend_upside = ShiftRegister(8, 9, 10);
ShiftRegister IRsend_bottomside = ShiftRegister(14, 15, 16);
Demux demux = Demux(17, 18, 19);
//�A�i���O�s��
const int readPin = 7;

//�O���[�o���ϐ�
int dataArray[12];
list<int> sensorValueList;

void setup() {
	pinMode(BLEModule_TX, INPUT);
	pinMode(BLEModule_RX, OUTPUT);
	pinMode(ICSP_MOSI, OUTPUT);
	pinMode(ICSP_MISO, OUTPUT);
	pinMode(ICSP_SCK, OUTPUT);

	//�����l�̐ݒ�
	for (int i = 0; i < 13; i++) {
		dataArray[i] = 2 ^ i;
	}
}

void loop() {
	readAll();
}

void readAll(){
	//�Ǝˑ��̏㕔�̃V�t�g���W�X�^��ݒ�
	for (int i = 0; i < 13; i++) {
		int upperData = dataArray[i];
		IRsend_upside.Begin();
		IRsend_upside.Output16(MSBFIRST, upperData);
		IRsend_upside.End();

		//�Ǝˑ��̉����̃V�t�g���W�X�^��ݒ�
		for (int j = 0; j < 8; j++) {
			int bottomData = ~dataArray[j];
			IRsend_bottomside.Begin();
			IRsend_bottomside.Output(MSBFIRST, bottomData);
			IRsend_bottomside.End();
			
			//������̏㕔�̃V�t�g���W�X�^��ݒ�
			for (int i = 0; i < 13; i++) {
				int upperData = dataArray[i];
				IRreceive_upside.Begin();
				IRreceive_upside.Output16(MSBFIRST, upperData);
				IRreceive_upside.End();

				//������̉����̃V�t�g���W�X�^��ݒ�
				for (int j = 0; j < 8; j++) {
					int bottomData = ~dataArray[j];
					IRreceive_bottomside.Begin();
					IRreceive_bottomside.Output(MSBFIRST, bottomData);
					IRreceive_bottomside.End();

					//�Z���T�l���擾���C���X�g�ɒǉ�
					int sensorValue = analogRead(readPin);
					sensorValueList.push_back(sensorValue);
				}
			}
		}
	}
}