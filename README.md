# library-management-system
 A library system lets users manage books. The Book class has private variables for title, author, serial number, and availability, with public functions to set and get these values. borrowBook &amp; returnBook are used to display the availability of books. The library uses a dynamic array for up to 100 books, validating user input to manage actions.


Detailed Description : 
It is a library management system that lets users search for, add, and remove books from the collection. To represent each book in the software, a class called Book is used. It has public member functions and private member variables for the title, author, book serial member, and availability of the books by borrowBook and returnBook and more.

Setting the relevant member variable with a string argument is what the setTitle, setAuthor, and setISBN functions should do. When a boolean input is passed to the setAvailable function, the available member variable is set to true if the book is available or false if it is checked out. Returning the appropriate member variable is the function of getTitle, getAuthor, and getISBN.

If the book is available or checked out, a string representing its availability is returned by the getAvailable function. If the book is available, the borrowBook function should produce an error message; if the book is checked out, it should set the available member variable to false. If the book is available but checked out, the returnBook method produces an error notice and set the available member variable to true.


The library is represented by the program using a dynamic array of Book objects, with a capacity of up to 100 books. The application asks the user if they want to add, remove, or search for books before carrying out the appropriate action. The program also validates the user's input and ensure that the library does not exceed its maximum capacity.
