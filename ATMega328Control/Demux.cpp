#include "Demux.h"


Demux::Demux(int S0, int S1, int S2) : S0Pin(S0), S1Pin(S1), S2Pin(S2)
{
	pinMode(S0Pin, OUTPUT);
	pinMode(S1Pin, OUTPUT);
	pinMode(S2Pin, OUTPUT);
}

//ìdåπÇàÛâ¡Ç∑ÇÈÉZÉìÉTóÒÇêÿÇËë÷Ç¶ÇÈ
void Demux::readAll(int arrayNum)
{
	switch (arrayNum){
	case 0:
		digitalWrite(S0Pin, LOW);
		digitalWrite(S1Pin, LOW);
		digitalWrite(S2Pin, LOW);
		break;
	case 1:
		digitalWrite(S0Pin, HIGH);
		digitalWrite(S1Pin, LOW);
		digitalWrite(S2Pin, LOW);
		break;
	case 2:
		digitalWrite(S0Pin, LOW);
		digitalWrite(S1Pin, HIGH);
		digitalWrite(S2Pin, LOW);
		break;
	case 3:
		digitalWrite(S0Pin, HIGH);
		digitalWrite(S1Pin, HIGH);
		digitalWrite(S2Pin, LOW);
		break;
	case 4:
		digitalWrite(S0Pin, LOW);
		digitalWrite(S1Pin, LOW);
		digitalWrite(S2Pin, HIGH);
		break;
	case 5:
		digitalWrite(S0Pin, HIGH);
		digitalWrite(S1Pin, LOW);
		digitalWrite(S2Pin, HIGH);
		break;
	case 6:
		digitalWrite(S0Pin, LOW);
		digitalWrite(S1Pin, HIGH);
		digitalWrite(S2Pin, HIGH);
		break;
	case 7:
		digitalWrite(S0Pin, HIGH);
		digitalWrite(S1Pin, HIGH);
		digitalWrite(S2Pin, HIGH);
		break;
	case 8:
		digitalWrite(S0Pin, LOW);
		digitalWrite(S1Pin, LOW);
		digitalWrite(S2Pin, LOW);
		break;
	case 9:
		digitalWrite(S0Pin, HIGH);
		digitalWrite(S1Pin, LOW);
		digitalWrite(S2Pin, LOW);
		break;
	case 10:
		digitalWrite(S0Pin, LOW);
		digitalWrite(S1Pin, HIGH);
		digitalWrite(S2Pin, LOW);
		break;
	case 11:
		digitalWrite(S0Pin, HIGH);
		digitalWrite(S1Pin, HIGH);
		digitalWrite(S2Pin, LOW);
		break;
	case 12:
		digitalWrite(S0Pin, LOW);
		digitalWrite(S1Pin, LOW);
		digitalWrite(S2Pin, HIGH);
		break;
	}
}

Demux::~Demux()
{
}
