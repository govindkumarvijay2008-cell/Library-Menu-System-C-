#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

struct Book { string title; bool issued = false; };
int main() {
    vector<Book> books;
    int choice;
    cout << "Library Menu System\nCreated by Govind Kumar Vijay\n";
    do {
        cout << "\nLibrary Menu\n1. Add book\n2. Show books\n3. Issue book\n4. Return book\n0. Exit\nChoice: ";
        if (!(cin >> choice)) { cerr << "Please enter a number.\n"; return 1; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 1) {
            string title; cout << "Book title: "; getline(cin, title);
            if (title.empty()) cout << "Title cannot be empty.\n";
            else { books.push_back({title, false}); cout << "Book added.\n"; }
        } else if (choice == 2) {
            if (books.empty()) cout << "No books in the library.\n";
            for (size_t i = 0; i < books.size(); ++i)
                cout << i + 1 << ". " << books[i].title << " — " << (books[i].issued ? "Issued" : "Available") << '\n';
        } else if (choice == 3 || choice == 4) {
            if (books.empty()) { cout << "No books to select.\n"; continue; }
            int number; cout << "Book number (1-" << books.size() << "): ";
            if (!(cin >> number)) { cerr << "Please enter a number.\n"; return 1; }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (number < 1 || static_cast<size_t>(number) > books.size()) cout << "Invalid book number.\n";
            else {
                Book& book = books[number - 1];
                if (choice == 3 && book.issued) cout << "That book is already issued.\n";
                else if (choice == 4 && !book.issued) cout << "That book is already available.\n";
                else { book.issued = choice == 3; cout << (book.issued ? "Book issued.\n" : "Book returned.\n"); }
            }
        } else if (choice != 0) cout << "Choose an option from the menu.\n";
    } while (choice != 0);
    cout << "Goodbye.\n";
}
