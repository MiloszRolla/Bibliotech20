#include "Book.h"

void Book::show_book()
{
	if (is_borrowed == true)
		cout << author << " - " << title << endl << "Borrowed\n";
	else
		cout << author << " - " << title << endl << "Available\n";
}