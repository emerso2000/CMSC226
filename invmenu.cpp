#include <iostream>
#include <iomanip>
#include "invmenu.h"
#include "bookinfo.h"
using namespace std;

extern const int arrraySize = 15;
extern string bookTitle[arrraySize];
extern string ibsn[arrraySize];
extern string author[arrraySize];
extern string publisher[arrraySize];
extern string dateAdded[arrraySize];
extern int qtyOnHand[arrraySize];
extern double wholesale[arrraySize];
extern double retail[arrraySize];
//extern

//Ask teacher if i can change to int because of return 0;
void lookUpBook() {
    string bookName;

    cout << "\nYou selected Look up Book";
    cout << "\nWhat is the title of the book you are looking for? ";
    cin.ignore();
    getline(cin, bookName);

    for (int i = 0; i < arrraySize; i++) {
        if (bookTitle[i] == bookName) {
            bookInfo(ibsn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);            
            break;
        }
        else {
            cout << "\nWe could not find the book you requested, sorry!";
            break;
        }
    }
}

void addBook() {
    cout << "\nYou selected Add Book";
    string book_title;
    string ibsn_num;
    string author_name;
    string publisher_name;
    string date;
    int qty;
    double wholesale_price;
    double retail_price;

    for (int i = 0; i < arrraySize; i++) {
        if (bookTitle[i].length() == 0) {
            cout << "\nBook title: ";
            cin.ignore();
            getline(cin, book_title);
            bookTitle[i] = book_title;

            cout << "\nIBSN Number: ";
            cin >> ibsn_num;
            ibsn[i] = ibsn_num;

            cout << "\nAuthor's Name: ";
            cin >> author_name;
            author[i] = author_name;

            cout << "\nPublisher's Name: ";
            cin >> publisher_name;
            publisher[i] = publisher_name;

            cout << "\nThe date the book was added to inventory: ";
            cin >> date;
            dateAdded[i] = date;

            cout << "\nThe quantity of the book being added: ";
            cin >> qty;
            qtyOnHand[i] = qty;

            cout << "\nThe wholesale cost of the book: ";
            cin >> wholesale_price;
            wholesale[i] = wholesale_price;

            cout << "\nThe retail cost of the book: ";
            cin >> retail_price;
            retail[i] = retail_price;

            break;
        }

        else {
            cout << "\nNo more books can be added to inventory.";
            break;
        }
    }
}

void editBook() {
    string bookName;
    string ibsn_num;
    string author_name;
    string publisher_name;
    string date;
    int qty;
    double wholesale_price;
    double retail_price;
    int choice;

    cout << "\nYou selected Edit Book";
    cout << "\nEnter the title of the book you want to edit: ";
    cin.ignore();
    getline(cin, bookName);

    for (int i = 0; i < arrraySize; i++) {
        if (bookName == bookTitle[i]) {
            cout << "\nWhat fields do you want to change?";
            cout << "\n1. Book title";
            cout << "\n2. IBSN Number";
            cout << "\n3. Author's Name";
            cout << "\n4. Publisher's Name";
            cout << "\n5. Date book was added to the inventory";
            cout << "\n6. Quantity of the book";
            cout << "\n7. Wholesale Price";
            cout << "\n8. Retail Price\n";

            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "\nEnter the new book title: ";
                    cin.ignore();
                    getline(cin, bookName);
                    bookTitle[i] = bookName;
                    cout << bookTitle[i];
                    break;
                case 2:
                    cout << "\nEnter the new IBSN number: ";
                    cin.ignore();
                    getline(cin, ibsn_num);
                    ibsn[i] = ibsn_num;
                    break;  
                case 3:
                    cout << "\nEnter the new Author's name: ";
                    cin.ignore();
                    getline(cin, author_name);
                    author[i] = author_name;
                    break;
                case 4:
                    cout << "\nEnter the new Publisher's name: ";
                    cin.ignore();
                    getline(cin, publisher_name);
                    publisher[i] = publisher_name;
                    break;
                case 5:
                    cout << "\nEnter the new date: ";
                    cin >> date;
                    dateAdded[i] = date;
                    break;
                case 6:
                    cout << "\nEnter the new quantity: ";
                    cin >> qty;
                    qtyOnHand[i] = qty;
                    break;
                case 7:
                    cout << "\nEnter the new wholesale cost: ";
                    cin >> wholesale_price;
                    wholesale[i] = wholesale_price;
                    break;
                case 8:
                    cout << "\nEnter the new retail cost: ";
                    cin >> retail_price;
                    retail[i] = retail_price;
                    break;
            }
            bookInfo(ibsn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
            break;            
        }

        else {
            cout << "\nSorry, we could not find the book you requested";
            break;
        }
    }
}

void deleteBook() {
    string bookName;
    cout << "\nYou selected Delete Book";
    cout << "\nEnter the title of the book you want to delete: ";
    cin.ignore();
    getline(cin, bookName);

    for (int i = 0; i < arrraySize; i++) {
        if (bookName == bookTitle[i]) {
            bookTitle[i] = "";
            ibsn[i] = "";
            break;
        }
        else {
            cout << "\nSorry, we could not find the book you requested";

            break;
        }
    }
}

int invMenu()
{
    int choice;
    do {
        cout << "\n\n" << setw(44) << "Serendipity Book Sellers" << endl;
        cout << setw(44) << "Inventory Database" << endl << endl;

        cout << setw(34) << "1. Look Up a Book" << endl;
        cout << setw(30) << "2. Add a Book" << endl;
        cout << setw(40) << "3. Edit a Book's Record" << endl;
        cout << setw(33) << "4. Delete a Book" << endl;
        cout << setw(39) << "5. Return to Main Menu" << endl << endl;


        cout << setw(10) << "\n\nEnter Your Choice: ";
        cin >> choice;

        while (choice < 1 || choice > 5)
        {
            cout << setw(10) << "Please enter a number in the range 1-5: ";
            cin >> choice;
        }

        switch(choice) {
            case 1:
                lookUpBook();
                break;
            case 2:
                addBook();
                break;
            case 3:
                editBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                break;
        }

    } while (choice != 5);

    return 0;
}

