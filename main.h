#pragma once
#include <stdio.h>
#include <conio.h>
#include <memory>

constexpr int ESC = 27;

inline void End() {
	printf("\n\n\nESC�ŏI��\n");
	while (!_kbhit() && _getch() != ESC);
}