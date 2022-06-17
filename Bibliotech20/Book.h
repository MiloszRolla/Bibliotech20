#pragma once
#include <iostream>
#include <String>
#include <time.h>

using namespace std;
class Book
{
public:
	time_t now = time(0);
	string title, author;
	bool is_borrowed;
	char* date_time = ctime(&now);
	void show_book();
};
