#include "Book.h"
#include <conio.h>
#include <Windows.h>
using namespace std;
void all_books();
void available_books();
void borrowed_books();
bool password();
void add_delete_book();


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


int main()
{
	setlocale(LC_CTYPE, "Polish");
	int selector=0;
	cout << "Welcome to our online library. To select a particular option type the coresponding number and press ENTER\n" << endl << endl
		<< "1. The list of all the books\n"
		<< "2. The list of available books\n"
		<< "3. The list of borrowed books\n"
		<< "4. Add or delete a book\n"
		<< "To borrow a book please isit the list of available books and follow further instructions\n";
		switch (selector = _getch())
		{
			case ONE:
			{
				system("cls");
				all_books();
				break;
			}
			case TWO:
			{
				system("cls");
				available_books();
				break;
			}
			case THREE:
			{
				system("cls");
				borrowed_books();
				break;
			}
			case FOUR:
			{
				system("cls");
				while (password() == 0)
				{
					system("cls");
					cout << "Type in a proper password\n";
				}
				add_delete_book();
				break;
			}
			default:
			{
				system("cls");
				cout << "You cannot do that\n";
				main();
			}
		}
	return 0;
}
void all_books()
{
	int a;
	cout << "Z pliku sciaga liste ksiazek i wyswietla tytul, autora i stan, w kolorze zielonym lub czerwonym\n"
		 <<"Aby wrocic wcisnij ESCAPE\n";
	Book b[100];
	for (int i = 0; i < 100; i++)
	{
		b[i].id = i + 1;
		b[i].pull_book();
		b[i].show_book();
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
	setlocale(LC_CTYPE, "Polish");
	cout << "To borrow a book press one;\n"
		 << "Aby wrocic wcisnij ESCAPE\n";
	Book b[100];
	for (int i = 0; i < 100; i++)
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
			if (b[a-1].is_borrowed == "available")
			{
				b[a-1].is_borrowed = "borrowed";
				cout << "Thank you for choosing our library.\n";
				for (int i = 0; i < 100; i++)
				{
					if (i == 0)
						b[i].add_book();
					else
						b[i].add_book2();
				}
			}
			else cout << "That book has already been borrowed\n";
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
	cout << "Z pliku œci¹ga liste ksiazek o is_borrowed = 1, to je wyswietla\n"
	 	 << "Aby wrocic wcisnij ESCAPE\n";
	Book b[100];
	for (int i = 0; i < 100; i++)
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
	if (password == "Bibliotech20")
		return true;
	else
		return false;
}
void add_delete_book()
{
	int a;
	cout << "To add a book press 1, to delete one press 2, to go navigate to main menu press ESCAPE\n";
	switch (a = _getch())
	{
	case ONE:
	{
		string a, b, c;
		cout << "Type the name of the author, the title and the category of the book\n";
		cin >> a >> b >> c;
		Book new_book(a, b, c);
		new_book.add_book2();

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