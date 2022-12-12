#pragma once
#include <stdio.h>
#include <conio.h>
#include <memory>

constexpr int ESC = 27;

inline void End() {
	printf("\n\n\nESCÇ≈èIóπ\n");
	while (!_kbhit() && _getch() != ESC);
}