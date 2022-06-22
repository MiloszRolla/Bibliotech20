#include "Book.h"
#include <fstream>
#include "color.hpp"
#include <sstream>

using std::fstream;
using std::ios;
using std::cout;
using std::endl;
Book::Book()
{
    author = "0";
    title = "0";
    is_borrowed = "0";
    name = "0";
    pesel = "0";
    book_id = "0";
}
Book::Book(string a, string b, string c, int d)
{
    author = a;
    title = b;
    is_borrowed = "available";
    book_id_int_value = d;
    name = "-";
    pesel = "0";
    date = "01.01.01";
}
void Book::delete_book(int ID)
{

}
void Book::give_id()
{
    fstream fout;
    fout.open("books.txt", ios::in);

    if (fout.good() == true)
    {

        string linia;
        int counter = 0;
        while (getline(fout, linia))
        {
            counter++;
        }
        fout.close();
        for (int i = 0; i < counter - 5; i++)
        {
            getline(fout, linia);
            if (i = counter - 6)
                cout << linia;
        }
    }
    else
    {
        cout << "Plik nie istnieje!";
        exit(0);
    }
}
void Book::pull_book()
{
    fstream fout;
    fout.open("books.txt", ios::in);

    if (fout.good() == true)
    {
        int nr_linii = (id - 1) * 7 + 1;
        string linia;
        int licznik = 1;
        while (getline(fout, linia))
        {
            if (licznik == nr_linii)
            {
                book_id = linia;
                convert_to_int();
            }
            if (licznik == nr_linii + 1) title= linia;
            if (licznik == nr_linii + 2) author = linia;
            if (licznik == nr_linii + 3) is_borrowed = linia;
            if (licznik == nr_linii + 4) name = linia;
            if (licznik == nr_linii + 5) pesel = linia;
            if (licznik == nr_linii + 6) date = linia;
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
void Book::add_book()
{
    fstream fout;
    fout.open("books.txt", ios::out);

    if (fout.good() == true)
    {
        fout <<book_id_int_value<<endl<< author << endl << title << endl << is_borrowed<<endl << name << endl << pesel << endl << date << endl;
        fout.close();
    }
    else
    {
        cout << "Plik nie istnieje!";
        exit(0);
    }
}
void Book::add_book2()
{
    fstream fout;
    fout.open("books.txt", ios::app);

    if (fout.good() == true)
    {
        fout << book_id_int_value << endl <<author << endl << title << endl << is_borrowed << endl << name << endl << pesel << endl << date << endl;

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
        cout << "  Book Id: " << book_id_int_value << endl<< "  Author: " <<author << "\n" <<"  Title: " << title << "\n" << "  State: " << dye::light_red("Borrowed at: ")
        << dye::light_red(date_time) <<
        +"  Name: " + name + '\n' + "  Pesel: " + pesel + '\n' + "  Data: " + date + '\n' << endl;
    else if (is_borrowed == "available")
        cout << "  Book Id: " << book_id_int_value << '\n' << "  Author: " << author << "\n" << "  Title: " << title << "\n" << "  State: " <<dye::light_green("Available \n")<< "  Name: " << name << '\n' << "  Pesel: " << pesel << '\n' << "  Data: " << date << '\n' << endl;
}
void Book::convert_to_int()
{
    stringstream ss;
    ss << book_id;
    ss >> book_id_int_value;

}