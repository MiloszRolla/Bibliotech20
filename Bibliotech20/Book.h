#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <String>
#include <time.h>

using namespace std;
class Book
{
	time_t now = time(0);
	char* date_time = ctime(&now);
public:

	string title, author;
	string is_borrowed;
	string name;
	double PESEL;
	string category;

	bool is_borrowed_bool_value;

	int id;
	void show_book();
	void pull_book();
	void add_book();
	void add_book2();
	Book();
	Book(string a, string b, string c);
	void delete_book(int ID);
};
