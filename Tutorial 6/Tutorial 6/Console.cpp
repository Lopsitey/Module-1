#include "Console.h"

void SetCursor(int x, int y)
{
	std::cout << "\x1b[" << y << ";" << x << "H";
}
void ClearRows(int rows)
{
	std::cout << "\x1b[" << rows << "M";
}
void SetColour(int hex, int hex2, int hex3)
{
	std::cout << "\x1b]4;0;rgb:" << hex << "/" << hex2 << "/" << hex3 << "\x1b\\";
}