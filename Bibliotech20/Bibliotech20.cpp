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




int main()
{
	count_lines();
	int selector = 0;
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