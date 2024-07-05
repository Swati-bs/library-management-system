// Library Management System - Swati Bhat
#include <iostream>
using namespace std;
#include <string>

class Book
{
    string title, author, isbn;
    bool available;

public:
    Book()
    {
    }
    Book(string bookTitle, string bookAuthor, string bookISBN)
    {
        setTitle(bookTitle);
        setAuthor(bookAuthor);
        setISBN(bookISBN);
        setAvailable(true);
    }
    void setTitle(string bookTitle)
    {
        title = bookTitle;
    }
    void setAuthor(string bookAuthor)
    {
        author = bookAuthor;
    }
    void setISBN(string bookISBN)
    {
        isbn = bookISBN;
    }
    void setAvailable(bool bookAvailable)
    {
        if (bookAvailable)
            available = true;
        else
            false;
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getISBN()
    {
        return isbn;
    }
    string getAvailable()
    {
        string rtrn;
        if (this->available == 1)
        {
            rtrn = "The book is available!";
            this->borrowBook(available);
        }
        else
        {
            rtrn = "Sorry! The book is not available.";
        }
        return rtrn;
    }
    void borrowBook(bool check)
    {
        if (check == 1)
        {
            available = false;
        }
        else
        {
            "The book you're looking for is checked out";
        }
    }
    void returnBook(bool check)
    {
        if (check == 1)
        {
            cout << "You have to return book in 30 days!";
        }
        else
        {
            available = true;
        }
    }
    void markAsDeleted()
    {
        available = false;
    }
};
int main()
{
    Book b[100];
    int bookCount = 0;
    char ch;
    string bookTitle, bookAuthor, bookISBN;
    bool bookAvailable, bookFound = false;
    ;
    cout << "Welcome to the library management system!" << endl;
    while (1)
    {
        cout << "Menu: \n1. Add book \n2. Remove book \n3. Search for book \n4.Exit\n";
        cout << "Enter your choice!" << endl;
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
        case '1':
            if (bookCount < 100)
            {
                string bookTitle, bookAuthor, bookISBN;
                cout << "Enter book title: " << endl;
                getline(cin, bookTitle);
                cout << "Enter book author: " << endl;
                getline(cin, bookAuthor);
                cout << "Enter book ISBN: " << endl;
                getline(cin, bookISBN);
                b[bookCount] = Book(bookTitle, bookAuthor, bookISBN);
                bookCount++;
                cout << "Book added successfully!" << endl;
            }
            else
            {
                cout << "Library is full. Cannot add more books." << endl;
            }
            break;
        case '2':
            cout << "Enter the book ISBN: ";
            getline(cin, bookISBN);
            bookFound = false;
            for (int i = 0; i < bookCount; i++)
            {
                if (b[i].getISBN() == bookISBN)
                {
                    bookFound = true;
                    cout << "The book has been removed" << endl;
                    b[i].markAsDeleted();
                    break;
                }
            }
            if (bookFound == false)
            {
                cout << "Book not found in the library." << endl;
            }
            break;
        case '3':
            cout << "Enter the book ISBN: ";
            getline(cin, bookISBN);
            bookFound = false;
            for (int i = 0; i < bookCount; i++)
            {
                if (b[i].getISBN() == bookISBN)
                {
                    bookFound = true;
                    cout << "BOOK INFORMATION:" << endl;
                    cout << "Title: " + b[i].getTitle() << endl;
                    cout << "Author: " + b[i].getAuthor() << endl;
                    cout << "ISBN: " + b[i].getISBN() << endl;
                    cout << "Availability: " + b[i].getAvailable() << endl;
                }
            }
            if (bookFound == false)
            {
                cout << "Book not found in the library." << endl;
            }
            break;
        case '4':
            cout << "Thank you for using the Library Management System!" << endl;
            exit(0);
            break;
        default:
            cout << "Choose appropriate option!";
            break;
        }
    }
    return 0;
}