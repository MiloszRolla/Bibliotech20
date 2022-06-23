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
    name = "username";
    pesel = "0";
    book_id = "0";
}
Book::Book(string a, string b, int d)
{
    author = a;
    title = b;
    is_borrowed = "available";
    book_id_int_value = d;
    name = "username";
    pesel = "pesel";
    date = "date.date";

}




void Book::pull_book()
{
    fstream fout;
    fout.open("books.txt", ios::in);
    if (fout.good() == true)
    {
        int line_number =(id-1)*7+1;
        string line;
        int counter = 1;
        while (getline(fout, line))
        {
            if (counter == line_number)
            {
                book_id = line;
                convert_to_int();
            }
            if (counter == line_number + 1) title= line;
            if (counter == line_number + 2) author = line;
            if (counter == line_number + 3) is_borrowed = line;
            if (counter == line_number + 4) name = line;
            if (counter == line_number + 5) pesel = line;
            if (counter == line_number + 6) date = line;
            counter++;
        }
        fout.close();
    }
    else
    {
        cout << "The file does not exist!";
        exit(0);
    }
}
void Book::add_book()
{
    fstream fout;
    fout.open("books.txt", ios::out);

    if (fout.good() == true)
    {
        fout <<book_id_int_value<<endl<< title << endl << author << endl << is_borrowed<<endl << name << endl << pesel << endl << date << endl;
        fout.close();
    }
    else
    {
        cout << "The file does not exist!";
        exit(0);
    }
}
void Book::add_book2()
{
    fstream fout;
    fout.open("books.txt", ios::app);

    if (fout.good() == true)
    {
        fout << book_id_int_value << endl <<title << endl << author << endl << is_borrowed << endl << name << endl << pesel << endl << date << endl;

        fout.close();
    }
    else
    {
        cout << "The file does not exist!";
        exit(0);
    }
}
void Book::show_book()
{

    if (is_borrowed == "borrowed")
        cout << "  Book Id: " << book_id_int_value << endl << "  Author: " << author << "\n" << "  Title: " << title << "\n" << "  State: " << dye::light_red("Borrowed") << endl
        <<
        +"  Name: " + name + '\n' + "  Pesel: " + pesel + '\n' << endl;
    else show_available();
}
void Book::show_available()
{
    cout << "  Book Id: " << book_id_int_value << '\n' << "  Author: " << author << "\n" << "  Title: " << title << "\n" << "  State: " << dye::light_green("Available \n")<<endl;
}
void Book::convert_to_int()
{
    stringstream ss;
    ss << book_id;
    ss >> book_id_int_value;

}