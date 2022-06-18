#include "Book.h"
#include <fstream>
#include "color.hpp"

using std::fstream;
using std::ios;
using std::cout;
using std::endl;

void Book::pull_book()
{
    fstream fout;
    fout.open("books.txt", ios::in);

    if (fout.good() == true)
    {
        int nr_linii = (id - 1) * 3 + 1;
        string linia;
        int licznik = 1;
        while (getline(fout, linia))
        {
            if (licznik == nr_linii) title = linia;
            if (licznik == nr_linii + 1) author = linia;
            if (licznik == nr_linii + 2) is_borrowed = linia;
            licznik++;
        }
        fout.close();
    }
    else
    {
        cout << "Plik nie istnieje!";
        exit(0);
    }
}
void Book::show_book()
{

    if (is_borrowed == "borrowed")
        cout << "  Author: " + author + "\n" + "  Title: " + title + "\n" + "  State: " + dye::light_red("Borrowed at: ") << dye::light_red(date_time )<< '\n' << endl;
	else if(is_borrowed == "available")
        cout << "  Author: " + author + "\n" + "  Title: " + title + "\n" + "  State: " + dye::light_green("Available")<< '\n' << endl;
}