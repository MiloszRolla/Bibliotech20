#include "Book.h"
using namespace std;
int main()
{
	Book b1, b2;
	b1.title = "Przygody Toma Sawyera";
	b1.author = "Pizdus Pan";
	b1.is_borrowed=false;
	b2.title = "Akademia Pana Kleksa";
	b2.author = "Kapitan Ameryka";
	b2.is_borrowed = true;
	b1.show_book();
	b2.show_book();
}
