#pragma once
#include "Functions.h"

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

void all_books()
{
	int a;
	cout << "To exit press ESCAPE\n";
	Book* b = new Book[array_length];
	for (int i = 0; i < array_length; i++)
	{
		b[i].id = i + 1;
		b[i].pull_book();
		if ((b[i].is_borrowed == "borrowed" || b[i].is_borrowed == "available"))b[i].show_book();
	}
	switch (a = _getch())
	{
	case ESCAPE:
	{
		system("cls");
		main(); break;

	}
	default:
	{
		system("cls");
		cout << "You cannot do that :c\n";
		all_books();
		break;
	}
	}
}
void available_books()
{
	int a;
	cout << "To borrow a book press one;\n"
		<< "To go back to main menu press ESCAPE\n";
	Book* b = new Book[array_length];
	for (int i = 0; i < array_length; i++)
	{
		b[i].id = i + 1;
		b[i].pull_book();
		if (b[i].is_borrowed == "available") {
			b[i].show_book();
		}

	}
	switch (a = _getch())
	{
	case ESCAPE:
	{
		system("cls");
		main(); break;
	}
	case ONE:
	{
		int a;
		cout << "What's the ID of the book you'd like to borrow?\n";
		cin >> a;
		for (int i = 0; i < array_length; i++)
		{
			if (b[i].book_id_int_value == a)
			{
				if (b[i].is_borrowed == "available")
				{
					b[i].is_borrowed = "borrowed";
					cout << "Thank you for choosing our library.\n";
					for (int i = 0; i < array_length; i++)
					{
						if (i == 0)
							b[i].add_book();
						else
							b[i].add_book2();
					}
				}
				else cout << "That book has already been borrowed\n";
			}

		}

		Sleep(3);
		system("cls");
		available_books();
		break;
	}
	default:
	{
		system("cls");
		cout << "You cannot do that :c\n";
		available_books();
		break;
	}
	}
}
void borrowed_books()
{
	int a;
	setlocale(LC_CTYPE, "Polish");
	cout << "This is the list of all the borrowed books\n"
		<< "ATo navigate to main menu press ESCAPE\n";
	Book* b = new Book[array_length];
	for (int i = 0; i < array_length; i++)
	{
		b[i].id = i + 1;
		b[i].pull_book();
		if (b[i].is_borrowed == "borrowed") {
			b[i].show_book();
		}

	}
	switch (a = _getch())
	{
	case ESCAPE:
	{
		system("cls");
		main(); break;
	}
	default:
	{
		system("cls");
		cout << "You cannot do that :c\n";
		borrowed_books();
		break;
	}
	}
}
bool password()
{
	string password;
	cout << "Password:\n";
	cin >> password;
	if (password == "Dupa123")
	{
		system("cls");
		return true;
	}
	else
	{
		system("cls");
		return false;
	}

}
void add_delete_book()
{
	int a;
	cout << "To add a book press 1, to delete one press 2, to go navigate to main menu press ESCAPE\n";
	switch (a = _getch())
	{
	case ONE:
	{
		string name, author;
		int id{}, ida, idb, idc;
		cout << "Type the name: ";
		cin >> name;
		cout << "Type the author: ";
		cin >> author;
		cout << "Type the first number of the ID (it represents category of the book): ";
		cin >> ida;
		if (ida > 9 || ida > 1)
		{
			system("cls");
			cout << "Use a number smaller than 10, but larger than 1\n";
			add_delete_book();
		}
		cout << "Type the second number of the ID (it represents the row that the book is located in): ";
		cin >> idb;
		if (idb > 9 || idb < 1)
		{
			system("cls");
			cout << "Use a number smaller than 10, but larger than 1\n";
			add_delete_book();
		}
		cout << "Type the last two numbers of the ID: ";
		cin >> idc;
		if (idc > 99 || idc < 10)
		{
			system("cls");
			cout << "Use a number smaller than 100, but larger than 10\n";
			add_delete_book();
		}
		id = ida * 1000 + idb * 100 + idc;
		Book new_book(name, author, id);
		new_book.add_book2();
		system("cls");
		add_delete_book();
		break;
	}
	case TWO:
	{


		break;
	}
	case ESCAPE:
	{
		system("cls");
		main(); break;
	}
	default:
	{
		system("cls");
		cout << "You cannot do that :c\n";
		add_delete_book();
		break;
	}
	}
}
void count_lines() {
	fstream fout;
	fout.open("books.txt", ios::in);
	string line;
	int linesCounter = 0;
	while (getline(fout, line))
	{
		linesCounter++;
	}
	array_length = linesCounter / 7;
}