#include "Book.h"
using namespace std;
void all_books();
void available_books();
void borrowed_books();
int main()
{
	Book b1, b2;
	int selector;
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
	cin >> selector;
	switch (selector)
	{
	case 1:
	{
		system("cls");
		all_books();
	}
	case 2:
	{
		system("cls");
		available_books();
	}
	case 3:
		system("cls");
		borrowed_books();
	}


	return 0;

}
void all_books()
{
	cout << "Z pliku sciaga liste ksiazek i wyswietla tytul, autora i stan, w kolorze zielonym lub czerwonym\n";
}
void available_books()
{
	cout << "Z pliku sciaga liste ksiazek o is_borrowed = 0, to je wyswietla\n";
}
void borrowed_books()
{
	cout << "Z pliku sciaga liste ksiazek o is_borrowed = 1, to je wyswietla\n";
}