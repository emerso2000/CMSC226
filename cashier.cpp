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
#include "cashier.h"
#include "bookStruct.h"
using namespace std;

const double TAX = 0.06;
const int arraySize = 20;

int cashier() {
    string date;
    int quantity = 0;
    double price;
    string bookisbn;
    string bookTitle = "";
    double unitPrice = 0.0;
    double totalBeforeTax = 0.0;
    double tax = 0.0;
    double total = 0.0;
    char choice;

    do {
        cout << "\nSerendipity Book Sellers\n";
        cout <<"Cashier Module\n";

        cout << "\nDate:\n";
        cin >> date;

        cout << "Quantity:\n";
        cin >> quantity;

        cout << "Price: ";
        cin >> price;

        do {
            cout << "isbn:\n";
            cin >> bookisbn;
            int index = -1;
            for (int i = 0; i < arraySize; i++) {
                if (bookDataInfo[i].isbn == bookisbn) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                cout << "Book not found. Do you want to re-enter the ISBN? Enter y for yes and n for no: ";
                cin >> choice;
            } 
            else {
                bookTitle = bookDataInfo[index].bookTitle;
                unitPrice = bookDataInfo[index].retail;
                choice = 'n'; // exit loop
                if (bookDataInfo[index].qtyOnHand < quantity) {
                    cout << "Not enough copies in stock. Returning to main menu.";
                    return 0;
                } 
                else {
                    bookDataInfo[index].qtyOnHand -= quantity;
                }
            }
        } while (choice == 'y');
    } while (choice != 'n');

        totalBeforeTax = quantity * unitPrice;
        tax = totalBeforeTax * TAX;
        total = totalBeforeTax + tax;

        cout << "\nQty\tISBN\t\t\tTitle\t\t\t\t\tPrice\t\tTotal";
        cout << "\n---------------------------------------------------------------------------------------------\n";
        cout << quantity << setw(11);
        cout << bookisbn << setw(28);
        cout << bookTitle << setw(35);
        cout << "$" << unitPrice << setw(10);
        cout << "$" << total;
        cout << "\n\n\nSubtotal: $" << fixed << setprecision(2) << totalBeforeTax;
        cout << "\nTax: $" << fixed << setprecision(2) << tax;
        cout << "\nTotal: $" << fixed << setprecision(2) << total;
        cout << "\n\n\nThank You for Shopping at Serendipity!";
        cout << "\nDo you want another transaction? Enter y for yes and n for no: ";
        cin >> choice;

    return 0;
}

