/*
 * Class: CMSC226
 * Instructor: Ms. Eivazi
 * Description: (Give a brief description for each Class): It is a program that acts like a report for inventory for a bookstore
 * Due: 2/05/2023
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Ethan Shay
*/
#include <iostream>
#include <iomanip>
#include "reports.h"
using namespace std;

void repListing() {
    cout << "\nYou selected Inventory Listing";
}

void repWholsale() {
    cout << "\nYou selected Inventory Wholesale Value";
}

void repRetail() {
    cout << "\nYou selected Inventory Retail Value";
}

void repQty() {
    cout << "\nYou selected Listing by Quantity";
}

void repCost() {
    cout << "\nYou selected Listing by Cost";
}

void repAge() {
    cout << "\nYou selected Listing by Age";
}

int reports()
{
    int choice;
    do {

        cout << "\n\n" << setw(44) << "Serendipity Book Sellers" << endl;
        cout << setw(35) << "Reports\n";

        cout << setw(35) << "\n1.\tInventory Listing";
        cout << setw(35) << "\n2.\tInventory Wholesale Value";
        cout << setw(35) << "\n3.\tInventory Retail Value";
        cout << setw(35) << "\n4.\tListing by Quantity";
        cout << setw(35) << "\n5.\tListing by Cost";
        cout << setw(35) << "\n6.\tListing by Age";
        cout << setw(35) << "\n7.\tReturn to Main Menu";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        while (choice < 1 || choice > 7)
        {
            cout << "Please enter a number in the range 1-7: \n";
            cin >> choice;
        }
        switch(choice) {
            case 1:
                repListing();
                break;
            case 2:
                repWholsale();
                break;
            case 3:
                repRetail();
                break;
            case 4:
                repQty();
                break;
            case 5:
                repCost();
                break;
            case 6:
                repAge();
                break;
            case 7:
                break;
        }
    } while (choice != 7);


    return 0;
}
