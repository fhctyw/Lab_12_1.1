#include "Number.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

unsigned int countNumber(unsigned int value) {
	unsigned int n = 1;
	while ((value /= 10) > 0) n++;
	return n;
}

unsigned int stabilize(unsigned int value) {
	for (int i = countNumber(value); i > 0; i--)
		if (value % (int)pow(10, i) == 0)
			return value / (int)pow(10, i);
	return value;
}

double getFractionalPart(double value)
{
	auto v = abs(value);
	return v - trunc(v);
}

int countNumberFractionalPart(double value) {
	unsigned int count = 0;
	value = abs(value);
	auto c = value - trunc(value);
	double factor = 10;
	double eps = DBL_EPSILON * c;
	while ((c > eps && c < (1 - eps)) && count < 17)
	{
		c = value * factor;
		c -= trunc(c);
		factor *= 10;
		eps = DBL_EPSILON * value * factor;
		count++;
	}
	return count;
}

bool Number::Init(double first, int second)
{
	this->first = trunc(first);
	if (second > 0) {
		this->second = stabilize(second);
		return true;
	}
	else {
		this->first = -NAN;
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
	double mult = abs(first) + second / pow(10, countNumber(second));
	mult *= abs(value);
	first = sign * trunc(mult);
	second = stabilize(getFractionalPart(mult) * pow(10, countNumberFractionalPart(mult)));
}
