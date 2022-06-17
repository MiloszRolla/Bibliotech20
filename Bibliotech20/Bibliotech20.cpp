#include "Book.h"
#include <conio.h>
using namespace std;
void all_books();
void available_books();
void borrowed_books();


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
	Book b1, b2;
	int selector=0;
	b1.title = "Przygody Toma Sawyera";
	b1.author = "Pizdus Pan";
	b1.is_borrowed = false;
	b2.title = "Akademia Pana Kleksa";
	b2.author = "Kapitan Ameryka";
	b2.is_borrowed = true;
	cout << "Welcome to our online library. To select a particular option type the coresponding number and press ENTER\n" << endl << endl
		<< "1. The list of all the books\n"
		<< "2. The list of available books\n"
		<< "3. The list of borrowed books\n"
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
	setlocale(LC_CTYPE, "Polish");
	cout << "Z pliku sciaga liste ksiazek i wyswietla tytul, autora i stan, w kolorze zielonym lub czerwonym\n"
		 <<"Aby wrocic wcisnij ESCAPE\n";
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
	cout << "Z pliku sciaga liste ksiazek o is_borrowed = 0, to je wyswietla\n"
		 << "Aby wrocic wcisnij ESCAPE\n";
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
void borrowed_books()
{
	int a;
	setlocale(LC_CTYPE, "Polish");
	cout << "Z pliku œci¹ga liste ksiazek o is_borrowed = 1, to je wyswietla\n"
	 	 << "Aby wrocic wcisnij ESCAPE\n";
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