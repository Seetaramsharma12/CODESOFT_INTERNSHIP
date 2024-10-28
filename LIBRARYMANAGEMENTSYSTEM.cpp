#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    bool isAvailable;

    Book(std::string t, std::string a) : title(t), author(a), isAvailable(true) {}
};

class User {
public:
    std::string name;
    std::vector<std::string> borrowedBooks;

    User(std::string n) : name(n) {}
};

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook(const std::string& title, const std::string& author) {
        books.push_back(Book(title, author));
        std::cout << "Book added: " << title << " by " << author << "\n";
    }

    void displayBooks() {
        std::cout << "\nAvailable Books:\n";
        for (const auto& book : books) {
            std::cout << (book.isAvailable ? "[Available] " : "[Borrowed] ") 
                      << "Title: " << book.title << ", Author: " << book.author << "\n";
        }
    }

    void borrowBook(const std::string& title, const std::string& userName) {
        for (auto& book : books) {
            if (book.title == title) {
                if (book.isAvailable) {
                    book.isAvailable = false;
                    for (auto& user : users) {
                        if (user.name == userName) {
                            user.borrowedBooks.push_back(title);
                            std::cout << userName << " borrowed: " << title << "\n";
                            return;
                        }
                    }
                } else {
                    std::cout << "Sorry, the book is currently borrowed.\n";
                }
                return;
            }
        }
        std::cout << "Book not found.\n";
    }

    void returnBook(const std::string& title, const std::string& userName) {
        for (auto& book : books) {
            if (book.title == title) {
                if (!book.isAvailable) {
                    book.isAvailable = true;
                    for (auto& user : users) {
                        if (user.name == userName) {
                            auto it = std::remove(user.borrowedBooks.begin(), user.borrowedBooks.end(), title);
                            user.borrowedBooks.erase(it, user.borrowedBooks.end());
                            std::cout << userName << " returned: " << title << "\n";
                            return;
                        }
                    }
                } else {
                    std::cout << "This book was not borrowed.\n";
                }
                return;
            }
        }
        std::cout << "Book not found.\n";
    }

    void registerUser(const std::string& name) {
        users.push_back(User(name));
        std::cout << "User registered: " << name << "\n";
    }

    void displayUsers() {
        std::cout << "\nRegistered Users:\n";
        for (const auto& user : users) {
            std::cout << "Name: " << user.name << ", Borrowed Books: ";
            for (const auto& book : user.borrowedBooks) {
                std::cout << book << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Library library;
    int choice;
    std::string title, author, userName;

    while (true) {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display Books\n";
        std::cout << "3. Borrow Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. Register User\n";
        std::cout << "6. Display Users\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter book title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter author name: ";
                std::getline(std::cin, author);
                library.addBook(title, author);
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                std::cout << "Enter book title to borrow: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter your name: ";
                std::getline(std::cin, userName);
                library.borrowBook(title, userName);
                break;
            case 4:
                std::cout << "Enter book title to return: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter your name: ";
                std::getline(std::cin, userName);
                library.returnBook(title, userName);
                break;
            case 5:
                std::cout << "Enter your name: ";
                std::cin.ignore();
                std::getline(std::cin, userName);
                library.registerUser(userName);
                break;
            case 6:
                library.displayUsers();
                break;
            case 7:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
}