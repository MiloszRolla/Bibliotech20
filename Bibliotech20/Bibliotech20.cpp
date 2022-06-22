#include "Functions.h"


int array_length;


int main()
{
	count_lines();
	cout << array_length;
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
				add_book();
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
