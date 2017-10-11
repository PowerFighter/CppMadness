#include "conio.h"

//Calculate the FibDigit(th) fibonacci number
int Fib(int FibDigit)
{
	int count = 2;
	int n1 = 1;
	int n2 = 1;
	int fib = 1;

	while (count < FibDigit)
	{
		fib = n1 + n2;
		n1 = n2;
		n2 = fib;
		count++;
	}

	return fib;
}

void Print(const char* s)
{
	for (; *s != 0; s++)
		_putch(*s);
}

void Read(char* buffer,int size)
{
	const char* const pEnd = buffer + size;
	for (char c = _getch(); c != 13 && buffer + 1 < pEnd; c = _getch(), buffer++)
	{
		_putch(c);
		*buffer = c;
	}

	*buffer = 0;
}

int LengthInt(int intVal)
{
	int valLength = 0;
	int div = intVal;
	while (div != 0)
	{
		div = div / 10;
		valLength++;
	}

	return valLength;
}

char* Int2Str(int intVal)
{
	int valLength = LengthInt(intVal);

	char* out = new char[valLength + 1];
	out[valLength] = 0;

	int currPos = valLength - 1;
	int div = intVal;

	while (div != 0)
	{
		out[currPos] = div % 10 + 48;
		currPos--;
		div = div / 10;
	}
	
	return out;
}

int Str2Int(const char* str)
{
	const char* bIter = str;

	for (; *bIter != 0; bIter++);
	bIter--;

	int currPlace = 1;
	int outVal = 0;
	for (; bIter >= str; bIter--)
	{
		outVal += (*bIter - 48) * currPlace;
		currPlace *= 10;
	}

	return outVal;
}

int main()
{
	char buffer[69];

	Read(buffer,3);
	Print(buffer);
	
	//Get the int val
	int intVal = Str2Int(buffer);
	int fibVal = Fib(intVal);

	Print(buffer);

	Print("\n");
	Print(Int2Str(fibVal));
	
	while(!_kbhit()) { }

	return 0;
}