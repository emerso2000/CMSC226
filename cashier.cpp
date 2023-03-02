/*
 * Class: CMSC226
 * Instructor: Ms.Eivazi
 * Description: (Give a brief description for each Class) It's a program that works as a cashier for a bookstore.
 * Due: 2/5/2023
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Ethan Shay
*/

#include <iostream>
#include <iomanip>
#include "cashier.h"
using namespace std;

const double TAX = 0.06;

int cashier() {
    string date;
    int quantity = 0;
    string ibsn;
    string title;
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

        cout << "IBSN:\n";
        cin >> ibsn;

        cout << "Title:\n";
        cin.ignore();
        getline(cin, title);

        cout << "Price:\n";
        cin >> unitPrice;

        totalBeforeTax = quantity * unitPrice;
        tax = totalBeforeTax * TAX;
        total = totalBeforeTax + tax;

        cout << "\nQty\tISBN\t\t\tTitle\t\t\t\t\tPrice\t\tTotal";
        cout << "\n---------------------------------------------------------------------------------------------\n";
        cout << quantity << setw(11);
        cout << ibsn << setw(28);
        cout << title << setw(35);
        cout << "$" << unitPrice << setw(10);
        cout << "$" << total;
        cout << "\n\n\nSubtotal: $" << fixed << setprecision(2) << totalBeforeTax;
        cout << "\nTax: $" << fixed << setprecision(2) << tax;
        cout << "\nTotal: $" << fixed << setprecision(2) << total;
        cout << "\n\n\nThank You for Shopping at Serendipity!";
        cout << "\nDo you want another transaction? Enter y for yes and n for no: ";
        cin >> choice;
    } while (choice != 'n');

    return 0;
}