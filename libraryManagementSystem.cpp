#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Book
{
    string title, author, isbn;
    bool available;

public:
    Book() {}
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
        available = bookAvailable;
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getISBN() const
    {
        return isbn;
    }
    string getAvailable()
    {
        return available ? "The book is available!" : "Sorry! The book is not available.";
    }
    void borrowBook(bool check)
    {
        if (check == true)
        {
            available = false;
        }
        else
        {
            cout << "The book you're looking for is checked out";
        }
    }
    void returnBook(bool check)
    {
        if (check == true)
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
    bool operator<(const Book &other) const
    {
        return isbn < other.isbn;
    }
};

int binarySearch(Book *b, int low, int high, string isbn)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (b[mid].getISBN() == isbn)
        {
            return mid;
        }
        if (b[mid].getISBN() < isbn)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void viewAllBooks(Book *b, int bookCount)
{
    if (bookCount == 0)
    {
        cout << "No books available in the library." << endl;
        return;
    }

    for (int i = 0; i < bookCount; i++)
    {
        if (b[i].getAvailable() == "The book is available!")
        {
            cout << "BOOK INFORMATION:" << endl;
            cout << "Title: " + b[i].getTitle() << endl;
            cout << "Author: " + b[i].getAuthor() << endl;
            cout << "ISBN: " + b[i].getISBN() << endl;
            cout << "Availability: " + b[i].getAvailable() << endl;
            cout << "---------------------------" << endl;
        }
    }
}

int main()
{
    Book *b = new Book[100];
    int bookCount = 0;
    char ch;
    string bookTitle, bookAuthor, bookISBN;
    bool bookFound = false;

    cout << "Welcome to the library management system!" << endl;
    while (1)
    {
        cout << "Menu: \n1. Add book \n2. Remove book \n3. Search for book \n4. View all books \n5. Exit\n";
        cout << "Enter your choice!" << endl;
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
        case '1':
            if (bookCount < 100)
            {
                cout << "Enter book title: " << endl;
                getline(cin, bookTitle);
                cout << "Enter book author: " << endl;
                getline(cin, bookAuthor);
                cout << "Enter book ISBN: " << endl;
                getline(cin, bookISBN);
                b[bookCount] = Book(bookTitle, bookAuthor, bookISBN);
                bookCount++;
                sort(b, b + bookCount);
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
            int index;
            index = binarySearch(b, 0, bookCount - 1, bookISBN);
            if (index != -1)
            {
                cout << "The book has been removed" << endl;
                b[index].markAsDeleted();
            }
            else
            {
                cout << "Book not found in the library." << endl;
            }
            break;
        case '3':
            cout << "Enter the book ISBN: ";
            getline(cin, bookISBN);
            index = binarySearch(b, 0, bookCount - 1, bookISBN);
            if (index != -1)
            {
                cout << "BOOK INFORMATION:" << endl;
                cout << "Title: " + b[index].getTitle() << endl;
                cout << "Author: " + b[index].getAuthor() << endl;
                cout << "ISBN: " + b[index].getISBN() << endl;
                cout << "Availability: " + b[index].getAvailable() << endl;
            }
            else
            {
                cout << "Book not found in the library." << endl;
            }
            break;
        case '4':
            viewAllBooks(b, bookCount);
            break;
        case '5':
            cout << "Thank you for using the Library Management System!" << endl;
            delete[] b; // Deallocate memory
            exit(0);
            break;
        default:
            cout << "Choose appropriate option!";
            break;
        }
    }
    return 0;
}
