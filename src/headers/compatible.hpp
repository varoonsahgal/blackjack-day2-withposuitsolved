#ifndef COMPATIBLE_H
#define COMPATIBLE_H

#ifdef _WIN32
#include <conio.h>

void clearscr();
#else
#include <termios.h>
#include <unistd.h>

void clearscr();
char __getch();
#endif

#endif