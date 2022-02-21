// Number.cpp
#include "Number.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

unsigned int getCountNumber(unsigned int value) {
	unsigned int n = 1;
	while ((value /= 10) > 0) n++;
	return n;
}

unsigned int stabilize(unsigned int value) {
	for (int i = getCountNumber(value); i > 0; i--)
		if (value % (int)pow(10, i) == 0)
			return value / (int)pow(10, i);
	return value;
}

double getFractionalPart(double value)
{
	auto v = abs(value);
	return v - trunc(v);
}

bool Number::Init(double first, int second)
{
	this->first = trunc(first);
	if (second >= 0) {
		this->second = stabilize(second);
		return true;
	}
	else {
		this->second = 0;
		return false;
	}
}

double Number::getFirst() const
{
	return first;
}

unsigned int Number::getSecond() const
{
	return second;
}

void Number::setFirst(double value)
{
	first = value;
}

void Number::setSecond(unsigned int value)
{
	second = value;
}

void Number::Display() const
{
	cout << fixed << setprecision(0)  << first << "." << second << endl;
}

void Number::Read()
{
	cout << "¬вед≥ть ц≥лу частину: ";
	cin >> first;
	do {
		cout << "¬вед≥ть дробову частину: ";
		cin >> second;
	} while (!Init(first, second));
}

void Number::multiply(double value)
{
	double sign = first * value > 0 ? 1.0 : -1.0;

	value = abs(value);

	double first = abs(this->first);
	double second = this->second;

	int n = getCountNumber(this->second);
	second /= pow(10, n);

	double mult = first + second;
	mult *= value;

	this->first = sign * trunc(mult);
	this->second = pow(10, n) * getFractionalPart(mult);
}
