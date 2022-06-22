#pragma once
#define _CRT_SECURE_NO_WARNINGS
extern int arrayLength;
#include <iostream>
#include <String>
#include <time.h>
#include <sstream>

using namespace std;
class Book
{
	public:

	time_t now = time(0);
	char* date_time = ctime(&now);
	string title, author, name, pesel, date, book_id;
	string is_borrowed;
	bool is_borrowed_bool_value;
	int id,book_id_int_value;
	int sizeOfData;
	void convert_to_int();
	void show_book();
	void pull_book();
	void add_book();
	void add_book2();
	void give_id();
	Book();
	Book(string a, string b, string c, int d);
	void delete_book(int ID);
};
