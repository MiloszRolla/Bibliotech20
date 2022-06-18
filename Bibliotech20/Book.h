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
	string is_borrowed;
	bool is_borrowed_bool_value;
	char* date_time = ctime(&now);
	int id;
	void show_book();
	void pull_book();
};
