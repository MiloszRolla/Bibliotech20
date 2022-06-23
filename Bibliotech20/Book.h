#pragma once
extern int arrayLength;
#include <iostream>
#include <String>
#include <sstream>

using namespace std;
class Book
{
	public:
	string title, author, name, pesel, book_id,date;
	string is_borrowed;
	bool is_borrowed_bool_value;
	int id,book_id_int_value;
	int sizeOfData;
	void convert_to_int();
	void show_book();
	void show_available();
	void pull_book();
	void add_book();
	void add_book2();
	Book();
	Book(string a, string b, int d);
};
