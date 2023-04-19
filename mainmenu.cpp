/*
 * Class: CMSC226
 * Instructor: Ms. Eivazi
 * Description: (Give a brief description for each Class) It's a program that acts as a main menu for a bookstore.
 * Due: 2/5/2023
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Ethan Shay
*/
#include <iostream>
#include "cashier.h"
#include "bookinfo.h"
#include "invmenu.h"
#include "reports.h"
#include "bookStruct.h"

using namespace std;


const int arraySize = 20;

int main()
{
    BookData bookDataInfo[20];

    int choice = 0;
    do {
        cout << "\n\n\tSerendipity Booksellers!\n";
        cout << "\t\tMain Menu\n";
        cout << "\n1.\tCashier Module\n";
        cout << "2.\tInventory Database Module\n";
        cout << "3.\tReport Module\n";
        cout << "4.\tExit\n";

        cout << "Enter your choice: ";
        cin >> choice;
    
        while (choice < 1 || choice > 4)
        {
            cout << "Please enter a number in the range 1-4: ";
            cin >> choice;
        }
        switch(choice) {
            case 1:
                cashier();
                break;
            case 2:
                invMenu();
                break;
            case 3:
                //reports();
                break;
            case 4:
                break;
        }
    } while (choice != 4);


    return 0;
}