#pragma once
#include "Book.h"
#include <conio.h>
#include <Windows.h>
#include <fstream>

#define ESCAPE 27
#define ZERO 48
#define ONE 49
#define TWO 50
#define THREE 51
#define FOUR 52
#define FIVE 53
#define SIX 54
#define SEVEN 55
#define EIGHT 56
#define NINE 57
extern int array_length;
using namespace std;
void count_lines();
void all_books();
void available_books();
void borrowed_books();
bool password();
void add_book();
int main();
