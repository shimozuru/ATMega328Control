#pragma once
class Demux
{
public:
	Demux();
	~Demux();

public:
	Demux(int S0, int S1, int S2, int S3);

public:
	void readAll(int arrayNum);

private:
	int S0Pin, S1Pin, S2Pin, S3Pin;
};

