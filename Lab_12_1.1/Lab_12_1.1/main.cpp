#include "Number.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Number makeNumber(double first, int second)
{
	Number n;
	if (!n.Init(first, second))
		cout << "ƒробна частина в≥д'Їмна(second)";
	return n;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Number n1;
	n1.Init(14.0, 2);
	n1.Display();
	n1.multiply(10);
	n1.Display();

	Number n2;
	n2.Read();
	n2.Display();
	n2.multiply(2.5);
	n2.Display();

	Number n3;
	int first, second;
	cout << "¬вед≥ть ц≥лу частину: ";
	cin >> first;
	cout << "¬вед≥ть дробову частину: ";
	cin >> second;

	n3 = makeNumber(first, second);
	n3.Display();

    return 0;
}