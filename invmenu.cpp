/*
 * Class: CMSC226
 * Instructor:Ms. Eivazi
 * Description: (Give a brief description for each Class) It is a program that acts like an inventory info for a book in a bookstore
 * Due: 2/05/2023
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Ethan Shay
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "invmenu.h"
#include "bookinfo.h"
#include "bookStruct.h"
#include <fstream>
#include <vector>
using namespace std;

const int arraySize = 20;

fstream inventoryFile;

void strUpper(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}


// void Title(BookData& bookDataInfo)
// {
//     bookDataInfo.setTitle()
// }

void setISBN(const char *isbn_num, int index)
{
    strcpy(bookDataInfo[index].isbn, isbn_num);
}

void setAuthor(const char *author_name, int index)
{
    strcpy(bookDataInfo[index].author, author_name);
}

void setPub(const char *publisher_name, int index)
{
    strcpy(bookDataInfo[index].publisher, publisher_name);
}

void setDateAdded(const char *date, int index)
{
    strcpy(bookDataInfo[index].dateAdded, date);
}
// do these need the const??
void setQty(int qty, int index)
{
    bookDataInfo[index].qtyOnHand = qty;
}

void setWholesale(double price, int index)
{
    bookDataInfo[index].wholesale = price;
}

void setRetail(double price, int index)
{
    bookDataInfo[index].retail = price;
}

int isEmpty(int index) {
    if (strcmp(bookDataInfo[index].bookTitle, "") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void removeBook(string bookName)
{   
    inventoryFile.close();
    inventoryFile.open("inventory.dat", ios::in);
    
    if(!inventoryFile.is_open()) {
        cout << "Error: could not open file";
        return;
    }

    vector<string> outputs;
    string data;

    while (getline(inventoryFile, data))
    {
        outputs.push_back(data);
    }

    inventoryFile.close();

    bool bookFound = false;
    for (auto it = outputs.begin(); it != outputs.end(); ++it)
    {
        size_t pos = it->find(bookName);
        if (pos != string::npos)
        {
            it->erase(pos, bookName.length());
            bookFound = true;
            break;
        }
    }

    inventoryFile.open("inventory.dat", ios::out | ios::trunc); 
    if(!inventoryFile.is_open())
    {
        cout << "Error: could not open file";
        return;
    }

    for (const auto& output : outputs) {
        inventoryFile << output << endl;
    }

    inventoryFile.close();

    if(bookFound) {
        cout << "Book deleted.";
    }
    else {
        cout << "Book not found";
    }
    
}

void replaceBook(string bookName, string replacement)
{
    inventoryFile.close(); 
    inventoryFile.open("inventory.dat", ios::in); 
    if (!inventoryFile.is_open()) 
    {
        cout << "Error: could not open file." << endl;
        return;
    }

    vector<string> outputs;
    string data;
    while (getline(inventoryFile, data))
    {
        outputs.push_back(data);
    }

    inventoryFile.close(); 
    bool bookFound = false;
    for (auto it = outputs.begin(); it != outputs.end(); ++it)
    {
        size_t pos = it->find(bookName);
        if (pos != string::npos)
        {
            it->replace(pos, bookName.length(), replacement);
            bookFound = true;
            break;
        }
    }

    inventoryFile.open("inventory.dat", ios::out | ios::trunc); 
    if (!inventoryFile.is_open()) 
    {
        cout << "Error: could not open file." << endl;
        return;
    }

    for (const auto& output : outputs)
    {
        inventoryFile << output << endl;
    }

    inventoryFile.close();
    if (bookFound)
    {
        cout << "Book replaced successfully." << endl;
    }
    else
    {
        cout << "Book not found." << endl;
    }
}

// check why there are emojis for NULL
void addBook(BookData& bookDataInfo)
{
    cout << "\nYou selected Add Book";
    string book_title;
    string isbn_num;
    string author_name;
    string publisher_name;
    string date;
    int qty;
    double wholesale_price;
    double retail_price;

    if (!inventoryFile.is_open()) {
        inventoryFile.open("inventory.dat", ios::binary | ios::app);

        if (inventoryFile.fail())
        {
            cout << "\nError: Failed to open inventory file in add book.\n";
            return;
        }
    }

    for (int i = 0; i < arraySize; i++)
    {
        if (isEmpty(i))
        {
            cout << "\nBook title: ";
            cin.ignore();
            getline(cin, book_title);
            strUpper(&book_title[0]);
            bookDataInfo.setTitle(book_title.c_str(), i);

            cout << "\nIsbn Number: ";
            cin >> isbn_num;
            strUpper(&isbn_num[0]);
            setISBN(isbn_num.c_str(), i);

            cout << "\nAuthor's Name: ";
            cin.ignore();
            getline(cin, author_name);
            strUpper(&author_name[0]);
            setAuthor(author_name.c_str(), i);

            cout << "\nPublisher's Name: ";
            getline(cin, publisher_name);
            strUpper(&publisher_name[0]);
            setPub(publisher_name.c_str(), i);

            cout << "\nThe date the book was added to inventory: ";
            cin >> date;
            setDateAdded(date.c_str(), i);

            cout << "\nThe quantity of the book being added: ";
            cin >> qty;
            setQty(qty, i);

            cout << "\nThe wholesale cost of the book: ";
            cin >> wholesale_price;
            setWholesale(wholesale_price, i);

            cout << "\nThe retail cost of the book: ";
            cin >> retail_price;
            setRetail(retail_price, i);

            // write the structure to the file
            inventoryFile.write(reinterpret_cast<char *>(&bookDataInfo[i]), sizeof(bookDataInfo[i]));
            inventoryFile << endl;

            return;
        }
    }
    cout << "\nNo more books can be added to inventory.";
    inventoryFile.close(); // close the file
}

void lookUpBook()
{
    string bookName;
    bool found = false;

    cout << "\nYou selected Look up Book";
    cout << "\nWhat is the title of the book you are looking for? ";
    cin.ignore();
    getline(cin, bookName);

    for (int i = 0; i < bookName.size(); i++)
    {
        bookName[i] = toupper(bookName[i]);
    }

    if (!inventoryFile.is_open()) {
        inventoryFile.open("inventory.dat", ios::binary | ios::app);

        if (inventoryFile.fail())
        {
            cout << "\nError: Failed to open inventory file in add book.\n";
            return;
        }
    }

    // Search for the book title record by record
    for (int i = 0; i < arraySize; i++)
    {
        inventoryFile.read(reinterpret_cast<char *>(&bookDataInfo[i]), sizeof(bookDataInfo[i]));

        if (strstr(bookDataInfo[i].bookTitle, bookName.c_str()) != nullptr)
        {
            found = true;
            cout << "\nWe found the book you requested! Here is the book information:";
            bookInfo(bookDataInfo[i].isbn, bookDataInfo[i].bookTitle, bookDataInfo[i].author, bookDataInfo[i].publisher, bookDataInfo[i].dateAdded, bookDataInfo[i].qtyOnHand, bookDataInfo[i].wholesale, bookDataInfo[i].retail);
            cout << "\nIs this the book you are looking for? (Y/N) ";
            char choice;
            cin >> choice;

            if (toupper(choice) == 'Y')
            {
                // inventoryFile.close();
                return;
            }
        }
    }

    if (!found)
    {
        cout << "\nWe could not find the book you requested, sorry!";
    }

    inventoryFile.close();
}

void editBook()
{
    string bookName;
    string isbn_num;
    string author_name;
    string publisher_name;
    string date;
    int qty;
    double wholesale_price;
    double retail_price;
    int choice_type;

    int old_qty;
    double old_wholesale_price;
    double old_retail_price;

    cout << "\nYou selected Edit Book";
    cout << "\nEnter part of the book title to search for: ";
    cin.ignore();
    getline(cin, bookName);

    bool found = false;

    for (int i = 0; i < bookName.size(); i++)
    {
        bookName[i] = toupper(bookName[i]);
    }

    for (int i = 0; i < arraySize; i++)
    {
        if (strstr(bookDataInfo[i].bookTitle, bookName.c_str()) != nullptr)
        {   
            isbn_num = bookDataInfo[i].isbn;
            author_name = bookDataInfo[i].author;
            publisher_name = bookDataInfo[i].publisher;
            date = bookDataInfo[i].dateAdded;
            old_qty = bookDataInfo[i].qtyOnHand;
            old_wholesale_price = bookDataInfo[i].wholesale;
            old_retail_price = bookDataInfo[i].retail;

            found = true;
            cout << "\nFound a book with title: " << bookDataInfo[i].bookTitle;
            string currentBook = bookDataInfo[i].bookTitle;
            cout << "\nIs this the book you are looking for? (Y/N) ";
            char choice;
            cin >> choice;

            if (toupper(choice) == 'Y')
            {
                cout << "\n1. Book title";
                cout << "\n2. ISBN Number";
                cout << "\n3. Author's Name";
                cout << "\n4. Publisher's Name";
                cout << "\n5. Date book was added to the inventory";
                cout << "\n6. Quantity of the book";
                cout << "\n7. Wholesale Price";
                cout << "\n8. Retail Price\n";
                cout << "\nWhat fields do you want to change?";
                cin >> choice_type;

                switch (choice_type)
                {
                case 1:
                    cout << "\nEnter the new book title: ";
                    cin.ignore();
                    cin.getline(bookDataInfo[i].bookTitle, 51);
                    strUpper(bookDataInfo[i].bookTitle);

                    replaceBook(currentBook, bookDataInfo[i].bookTitle);
                    break;
                case 2:
                    cout << "\nEnter the new ISBN number: ";
                    cin.ignore();
                    cin.getline(bookDataInfo[i].isbn, 13);
                    strUpper(bookDataInfo[i].isbn);

                    replaceBook(isbn_num, bookDataInfo[i].isbn);
                    break;
                case 3:
                    cout << "\nEnter the new Author's name: ";
                    cin.ignore();
                    cin.getline(bookDataInfo[i].author, 31);
                    strUpper(bookDataInfo[i].author);

                    replaceBook(author_name, bookDataInfo[i].author);
                    break;
                case 4:
                    cout << "\nEnter the new Publisher's name: ";
                    cin.ignore();
                    cin.getline(bookDataInfo[i].publisher, 31);
                    strUpper(bookDataInfo[i].publisher);
                    replaceBook(publisher_name, bookDataInfo[i].publisher);

                    break;
                case 5:
                    cout << "\nEnter the new date: ";
                    cin.ignore();
                    cin.getline(bookDataInfo[i].dateAdded, 12);
                    replaceBook(date, bookDataInfo[i].dateAdded);
                    break;
                case 6:
                    cout << "\nEnter the new quantity: ";
                    cin >> qty;
                    bookDataInfo[i].qtyOnHand = qty;
                    replaceBook(to_string(old_qty), to_string(bookDataInfo[i].qtyOnHand));
                    break;
                case 7:
                    cout << "\nEnter the new wholesale cost: ";
                    cin >> wholesale_price;
                    bookDataInfo[i].wholesale = wholesale_price;
                    replaceBook(to_string(old_wholesale_price), to_string(bookDataInfo[i].wholesale));
                    break;
                case 8:
                    cout << "\nEnter the new retail cost: ";
                    cin >> retail_price;
                    bookDataInfo[i].retail = retail_price;
                    replaceBook(to_string(old_retail_price), to_string(bookDataInfo[i].retail));
                    break;
                default:
                    cout << "\nInvalid choice.";
                    break;
                }

                cout << "\nBook updated:";
                bookInfo(bookDataInfo[i].isbn, bookDataInfo[i].bookTitle, bookDataInfo[i].author, bookDataInfo[i].publisher, bookDataInfo[i].dateAdded, bookDataInfo[i].qtyOnHand, bookDataInfo[i].wholesale, bookDataInfo[i].retail);
                return;
            }
        }
    }

    if (!found)
    {
        cout << "\nNo books found with that title.";
    }
}

// store the book as a string and rewrite it to the text after removing the words

void deleteBook()
{
    string bookName;
    cout << "\nYou selected Delete Book";
    cout << "\nEnter the title of the book you want to delete: ";
    cin.ignore();
    getline(cin, bookName);

    if (!inventoryFile.is_open()) {
        inventoryFile.open("inventory.dat", ios::binary | ios::app);

        if (inventoryFile.fail())
        {
            cout << "\nError: Failed to open inventory file in add book.\n";
            return;
        }
    }

    bool found = false;

    for (int i = 0; i < bookName.size(); i++)
    {
        bookName[i] = toupper(bookName[i]);
    }

    for (int i = 0; i < arraySize; i++)
    {
        inventoryFile.read(reinterpret_cast<char *>(&bookDataInfo[i]), sizeof(bookDataInfo[i]));
        if (strstr(bookDataInfo[i].bookTitle, bookName.c_str()) != nullptr)
        {
            found = true;
            cout << "\nFound a book with title: " << bookDataInfo[i].bookTitle;

            cout << "\nIs this the book you are looking for? (Y/N) ";

            char choice;
            cin >> choice;

            if (toupper(choice) == 'Y')
            {
                removeBook(bookDataInfo[i].bookTitle);
                return;
            }
        }
    }
    if (!found) {
        cout << "\nSorry, we could not find the book you requested";
    }
    inventoryFile.close();
}

int invMenu()
{
    ofstream inventoryFile("inventory.dat", std::ios::trunc);

    int choice;
    do
    {
        cout << "\n\n"
             << setw(44) << "Serendipity Book Sellers" << endl;
        cout << setw(44) << "Inventory Database" << endl
             << endl;

        cout << setw(34) << "1. Look Up a Book" << endl;
        cout << setw(30) << "2. Add a Book" << endl;
        cout << setw(40) << "3. Edit a Book's Record" << endl;
        cout << setw(33) << "4. Delete a Book" << endl;
        cout << setw(39) << "5. Return to Main Menu" << endl
             << endl;

        cout << setw(10) << "\n\nEnter Your Choice: ";
        cin >> choice;

        while (choice < 1 || choice > 5)
        {
            cout << setw(10) << "Please enter a number in the range 1-5: ";
            cin >> choice;
        }

        switch (choice)
        {
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