// Number.h
#pragma once

unsigned int countNumber(unsigned int value);
unsigned int stabilize(unsigned int value);
double getFractionalPart(double value);
int countNumberFractionalPart(double value);


class Number
{
	double first;
	unsigned int second;
public:
	bool Init(double first, int second);
	double getFirst() const;
	unsigned int getSecond() const;
	void setFirst(double value);
	void setSecond(unsigned int value);

	void Display() const;
	void Read();
	void multiply(double value);
};

