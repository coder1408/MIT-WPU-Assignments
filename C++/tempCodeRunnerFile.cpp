#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 20;

// Define the Book structure
struct Book {
    string title;
    string author;
    string isbn;
    bool checkedOut;
};

// Define the Library class
class Library {
    private:
        Book books[MAX_BOOKS];
        int numBooks;
    public:
        Library() {
            numBooks = 0;
        }
        void addBook(string title, string author, string isbn) {
            if (numBooks >= MAX_BOOKS) {
                cout << "The library is full." << endl;
            } else {
                Book newBook = {title, author, isbn, false};
                books[numBooks] = newBook;
                numBooks++;
            }
        }
        void displayBooks() {
            cout << "Library Books:" << endl;
            for (int i = 0; i < numBooks; i++) {
                cout << i + 1 << ". " << books[i].title << " by " << books[i].author << " (" << books[i].isbn << ")";
                if (books[i].checkedOut) {
                    cout << " - Checked Out" << endl;
                } else {
                    cout << " - Available" << endl;
                }
            }
        }
        void checkOutBook(int bookIndex) {
            if (bookIndex < 1 || bookIndex > numBooks) {
                cout << "Invalid book index." << endl;
            } else if (books[bookIndex - 1].checkedOut) {
                cout << "The book is already checked out." << endl;
            } else {
                books[bookIndex - 1].checkedOut = true;
                cout << "You have checked out \"" << books[bookIndex - 1].title << "\" by " << books[bookIndex - 1].author << "." << endl;
            }
        }
        void returnBook(int bookIndex) {
            if (bookIndex < 1 || bookIndex > numBooks) {
                cout << "Invalid book index." << endl;
            } else if (!books[bookIndex - 1].checkedOut) {
                cout << "The book is already returned." << endl;
            } else {
                books[bookIndex - 1].checkedOut = false;
                cout << "You have returned \"" << books[bookIndex - 1].title << "\" by " << books[bookIndex - 1].author << "." << endl;
            }
        }
};

int main() {
    // Create a library object
    Library library;

    // Add 20 books to the library
    library.addBook("To Kill a Mockingbird", "Harper Lee", "978-0060935467");
    library.addBook("1984", "George Orwell", "978-0451524935");
    library.addBook("The Catcher in the Rye", "J.D. Salinger", "978-0316769488");
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565");
    library.addBook("One Hundred Years of Solitude", "Gabriel Garcia Marquez", "978-0060883287");
    library.addBook("Moby-Dick", "Herman Melville", "978-0142437247");
    library.addBook("The Adventures of Huckleberry Finn", "Mark Twain", "978-0486280615");
library.addBook("Pride and Prejudice", "Jane Austen", "978-0486280615");
library.addBook("Jane Eyre", "Charlotte Bronte", "978-0141441146");
library.addBook("The Picture of Dorian Gray", "Oscar Wilde", "978-0141442464");
library.addBook("The Lord of the Rings", "J.R.R. Tolkien", "978-0544003415");
library.addBook("The Hobbit", "J.R.R. Tolkien", "978-0547928227");
library.addBook("The Da Vinci Code", "Dan Brown", "978-0307474278");
library.addBook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
library.addBook("The Diary of a Young Girl", "Anne Frank", "978-0553577129");
library.addBook("The Girl with the Dragon Tattoo", "Stieg Larsson", "978-0307949486");
library.addBook("The Hunger Games", "Suzanne Collins", "978-0439023528");
library.addBook("The Book Thief", "Markus Zusak", "978-0375831003");
library.addBook("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "978-0747532743");
library.addBook("The Cat in the Hat", "Dr. Seuss", "978-0394800011");
library.addBook("Charlotte's Web", "E.B. White", "978-0064410939");
library.addBook("The Giving Tree", "Shel Silverstein", "978-0060256654");
library.addBook("Where the Wild Things Are", "Maurice Sendak", "978-0060254926");

// Display all the books in the library
library.displayBooks();

// Check out a book
int bookIndex = 0;
cout << "Enter the index of the book you want to check out: ";
cin >> bookIndex;
library.checkOutBook(bookIndex);

// Return a book
cout << "Enter the index of the book you want to return: ";
cin >> bookIndex;
library.returnBook(bookIndex);

// Display all the books in the library again
library.displayBooks();

return 0;
}