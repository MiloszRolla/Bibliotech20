#include "Functions.h"




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
	delete[] b;
	switch (a = _getch())
	{
	case ESCAPE:
	{
		system("cls");
		main();

		break;

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
					cout << "Type in your name: ";
					cin.ignore();
					getline(cin, b[i].name);
					cout << "Type in your PESEL number: ";
					cin >> b[i].pesel;
					cout << "Thank you for choosing our library.\n";
					for (int i = 0; i < array_length; i++)
					{
						if (i == 0)
							b[i].add_book();
						else
							b[i].add_book2();
					}
				}
				else
				{
					system("cls");
					cout << "that book is already borrowed\n";
					available_books();
				}
			}
			else
			{
				system("cls");
				cout << "That book does not exist\n";
				available_books();
			}

		}
		delete[] b;
		Sleep(3);
		system("cls");
		available_books();
		break;
	}
	default:
	{
		delete[] b;
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
	cout << "This is the list of all the borrowed books\n"
		<<"To return a book press one\n"
		<< "To navigate to main menu press ESCAPE\n";
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
		case ONE:
		{
			int a;
			cout << "Which book would you like to return?\n";
			cin >> a;
			for (int i = 0; i < array_length; i++)
			{
				if (b[i].book_id_int_value == a)
				{
					if (b[i].is_borrowed == "borrowed")
					{
						b[i].is_borrowed = "available";
						b[i].name = "0";
						b[i].pesel = "0";
						cout << "Thank you for choosing our library.\n";
						for (int i = 0; i < array_length; i++)
						{
							if (i == 0)
								b[i].add_book();
							else
								b[i].add_book2();
						}
					}
					else if (b[i].is_borrowed == "available")
					{
						system("cls");
						cout << "That book has already been returned or it was not borrowed\n";
						borrowed_books();
					}

				}
			}
		}
		case ESCAPE:
		{
			delete[] b;
			system("cls");
			main();
			break;
		}
		default:
		{
			delete[] b;
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
void add_book()
{
	
	int a;
	cout << "To add a book press 1, to go navigate to main menu press ESCAPE\n";
	switch (a = _getch())
	{
	case ONE:
	{
		string a, x, c;
		int id{}, ida, idb, idc;
		cout << "Type the name: \n";
		cin.ignore();
		getline(cin, a);
		cout << "Type the author: ";
		cin.ignore();
		getline(cin, x);
		cout << "Type the first number of the ID (it represents category of the book): ";
		cin >> ida;
		if (ida > 9 || ida < 1)
		{
			system("cls");
			cout << "Use a number smaller than 10, but larger than 1\n";
			add_book();
		}
		cout << "Type the second number of the ID (it represents the row that the book is located in): ";
		cin >> idb;
		if (idb > 9 || idb < 1)
		{
			system("cls");
			cout << "Use a number smaller than 10, but larger than 1\n";
			add_book();
		}
		cout << "Type the last two numbers of the ID: ";
		cin >> idc;
		if (idc > 99 || idc < 10)
		{
			system("cls");
			cout << "Use a number smaller than 100, but larger than 10\n";
			add_book();
		}
		id = ida * 1000 + idb * 100 + idc;
		Book* b = new Book[array_length];
		for (int i = 0; i < array_length; i++)
		{
			b[i].id = i + 1;
			b[i].pull_book();
			if (b[i].book_id_int_value == id)
			{
				system("cls");
				cout << "This number is already taken\n";
				add_book();
			}

		}
		Book new_book(a, x, id);
		new_book.add_book2();
		system("cls");
		add_book();
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
		add_book();
		break;
	}
	}
}
void count_lines()
{
	fstream fout;
	fout.open("books.txt", ios::in);
	string linia;
	int linesCounter = 0;
	while (getline(fout, linia))
	{
		linesCounter++;
	}
	array_length = linesCounter / 7;
}