#include<iostream>
#include<string>

using namespace std;

class Date {
public:
    int day, month, year;

    Date() : day(0), month(0), year(0) {}

    Date(int day, int month, int year) : day(day), month(month), year(year) {}
};

class Node {
public:
    int ISBN;
    string title;
    string author;
    string genre;
    Date publicationDate;
    Node* next;
    Node* previous;

    Node(int ISBN, string title, string author, string genre, Date publicationDate) {
        this->ISBN = ISBN;
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->publicationDate = publicationDate;
        next = NULL;
        previous = NULL;
    }
};

class BookManagementSystem {
private:
    Node* head;

public:
    BookManagementSystem() : head(NULL) {}

    Node* addBook(int ISBN, string title, string author, string genre, Date publicationDate) {
        Node* newNode = new Node(ISBN, title, author, genre, publicationDate);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;

            while (current != NULL && current->publicationDate.year < publicationDate.year) {
                current = current->next;
            }

            if (current != NULL && current->publicationDate.year == publicationDate.year) {
                while (current != NULL && current->publicationDate.month < publicationDate.month) {
                    current = current->next;
                }

                if (current != NULL && current->publicationDate.month == publicationDate.month) {
                    while (current != NULL && current->publicationDate.day < publicationDate.day) {
                        current = current->next;
                    }
                }
            }

            if (current == head) {
                newNode->next = head;
                head->previous = newNode;
                head = newNode;
            } else if (current == NULL) {
                Node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->previous = temp;
            } else {
                newNode->next = current;
                newNode->previous = current->previous;
                current->previous->next = newNode;
                current->previous = newNode;
            }
        }

        return head;
    }

    Node* searchBook(int key, bool byISBN = true) {
        Node* current = head;

        while (current != NULL) {
            if ((byISBN && current->ISBN == key)) {
                return current;
            }
            current = current->next;
        }

        return NULL;
    }

    void displayBooks() {
        Node* current = head;

        cout << "Books In The Library:" << endl;
        while (current != NULL) {
            cout << "ISBN: " << current->ISBN << " | Title: " << current->title << " | Author: " << current->author << " | Genre: " << current->genre << " | Publication Date: " << current->publicationDate.day << "/" << current->publicationDate.month << "/" << current->publicationDate.year << endl;
            current = current->next;
        }
        cout << endl;
    }

    void filterBooks(string author) {
        Node* current = head;
        bool found = false;

        cout << "Books By Author '" << author << "':" << endl;
        while (current != NULL) {
            if (current->author == author) {
                cout << "ISBN: " << current->ISBN << " | Title: " << current->title << " | Genre: " << current->genre << " | Publication Date: " << current->publicationDate.day << "/" << current->publicationDate.month << "/" << current->publicationDate.year << endl;
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            cout << "No Books Found By Author '" << author << "'" << endl;
        }

        cout << endl;
    }

    void recommendBooks(string bookTitle) {
        Node* current = head;
        bool found = false;

        while (current != NULL) {
            if (current->title == bookTitle) {
                found = true;
                break;
            }
            current = current->next;
        }

        if (found) {
            current = head;
            int count = 0;

            cout << "Recommended Books Based on Genre:" << endl;
            while (current != NULL && count < 3) {
                if (current->genre == current->genre && current->title != bookTitle) {
                    cout << "ISBN: " << current->ISBN << " | Title: " << current->title << " | Author: " << current->author << " | Genre: " << current->genre << " | Publication Date: " << current->publicationDate.day << "/" << current->publicationDate.month << "/" << current->publicationDate.year << endl;
                    count++;
                }
                current = current->next;
            }

            if (count == 0) {
                cout << "No recommendations available." << endl;
            }
        } else {
            cout << "Book Not Found." << endl;
        }

        cout << endl;
    }

    void deleteBook(int ISBN) {
        Node* current = head;

        while (current != NULL) {
            if (current->ISBN == ISBN) {
                if (current->previous != NULL) {
                    current->previous->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next != NULL) {
                    current->next->previous = current->previous;
                }

                delete current;
                cout << "Book with ISBN " << ISBN << " Deleted Successfully." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Book with ISBN " << ISBN << " Not Found." << endl;
    }
};

int main() {
    BookManagementSystem library;

    int choice;
    do {
        cout<<endl<<"| The FAST Library |"<<endl<<endl;
        cout<<"1. Add a New Book"<<endl;
        cout<<"2. Search for a Book"<<endl;
        cout<<"3. Display Books"<<endl;
        cout<<"4. Filter Books by Author"<<endl;
        cout<<"5. Recommend Related Books"<<endl;
        cout<<"6. Delete a Book"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1: {
                int ISBN;
                string title, author, genre;
                Date publicationDate;

                cout << "Enter ISBN: ";
                cin >> ISBN;
                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Genre: ";
                getline(cin, genre);
                cout << "Enter Publication Date (Day/Month/Year): ";
                cin >> publicationDate.day >> publicationDate.month >> publicationDate.year;

                library.addBook(ISBN, title, author, genre, publicationDate);
                cout << "Book Added Successfully!" << endl;
                break;
            }
            case 2: {
                int searchKey;
                cout<<"Enter Book ISBN to Search: ";
                cin >> searchKey;

                Node* result = library.searchBook(searchKey, choice == 1);
                if (result != NULL) {
                    cout << "Book Found:" << endl;
                    cout << "ISBN: " << result->ISBN << " | Title: " << result->title << " | Author: " << result->author << " | Genre: " << result->genre << " | Publication Date: " << result->publicationDate.day << "/" << result->publicationDate.month << "/" << result->publicationDate.year << endl;
                } else {
                    cout << "Book Not Found." << endl;
                }

                break;
            }
            case 3: {
                library.displayBooks();
                break;
            }
            case 4: {
                string author;
                cout << "Enter Author Name: ";
                cin.ignore();
                getline(cin, author);
                library.filterBooks(author);
                break;
            }
            case 5: {
                string bookTitle;
                cout << "Enter The Title Of The Book: ";
                cin.ignore();
                getline(cin, bookTitle);
                library.recommendBooks(bookTitle);
                break;
            }
            case 6: {
                int ISBN;
                cout << "Enter the ISBN of The Book To Delete: ";
                cin >> ISBN;
                library.deleteBook(ISBN);
                break;
            }
            case 7: {
                cout << "Exiting The Program. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

    } while (choice != 0);

    return 0;
}
