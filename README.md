Certainly! Here's the revised README file without bold formatting:

---

# Library Management System

## Overview
The Library Management System is a software application that allows users to manage a library's book collection efficiently. It provides functionalities such as adding new books, removing existing books, searching for books by ISBN, and viewing all available books in the library.

## Features
- **Add Book**: Allows users to add a new book to the library by entering details such as title, author, and ISBN.
- **Remove Book**: Enables users to remove a book from the library by specifying its ISBN.
- **Search Book**: Allows users to search for a book in the library using its ISBN and displays detailed information if found.
- **View All Books**: Displays a list of all available books in the library, including their titles, authors, ISBNs, and availability status.
- **Dynamic Storage**: Utilizes a dynamic array to store up to 100 books, ensuring efficient management and scalability.

## Class: Book
The `Book` class represents a book in the library with the following attributes and methods:

### Attributes
- title: Title of the book.
- author: Author of the book.
- isbn: ISBN (International Standard Book Number) of the book.
- available: Boolean flag indicating whether the book is available (`true`) or checked out (`false`).

### Methods
- setTitle(string bookTitle): Sets the title of the book.
- setAuthor(string bookAuthor): Sets the author of the book.
- setISBN(string bookISBN): Sets the ISBN of the book.
- setAvailable(bool bookAvailable): Sets the availability status of the book.
- getTitle(): Returns the title of the book.
- getAuthor(): Returns the author of the book.
- getISBN(): Returns the ISBN of the book.
- getAvailable(): Returns a string indicating the availability status of the book.
- borrowBook(bool check): Updates the availability status of the book when borrowed.
- returnBook(bool check): Updates the availability status of the book when returned.
- markAsDeleted(): Marks the book as unavailable.

### Sorting and Searching
- Operator Overload (`<`): Enables comparison of books based on their ISBN for sorting purposes.
- Binary Search: Implements a binary search algorithm to efficiently search for books by ISBN.

## Usage
1. Adding a Book: Enter the book's title, author, and ISBN when prompted. The system will confirm if the book has been added successfully.
2. Removing a Book: Enter the ISBN of the book to be removed. If found, the book will be marked as deleted.
3. Searching for a Book: Enter the ISBN of the book to search for detailed information such as title, author, and availability status.
4. Viewing All Books: Choose the option to view all books currently available in the library.

## Installation
Clone the repository and compile the source code using a C++ compiler that supports C++11 or later standards.

```bash
git clone <repository-url>
cd library-management-system
g++ -std=c++11 main.cpp -o library
```
## Author
Swati Bhat

## References
codedamn course: From Novice to Expert: Mastering C++ Programming
https://codedamn.com/learn/cpp-language
