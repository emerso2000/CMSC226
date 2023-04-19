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
#include <string>
#include "reports.h"
using namespace std;

const double TAX = 0.06;
const int arraySize = 20;

extern char bookTitle[arraySize][51];
extern char isbn[arraySize][14];
extern char author[arraySize][31];
extern char publisher[arraySize][31];
extern char dateAdded[arraySize][11];
extern int qtyOnHand[arraySize];
extern double wholesale[arraySize];
extern double retail[arraySize];

void repListing()
{
    cout << "\nYou selected Inventory Listing";
    cout << "\nDate: 3/24/2023";
    cout << "\nReport: ";

    for (int i = 0; i < arraySize; i++)
    {
        if (bookTitle[i] == "")
            continue;
        cout << "\nBook name: " << bookTitle[i];
        cout << "\nisbn: " << isbn[i];
        cout << "\nAuthor: " << author[i];
        cout << "\nPublisher: " << publisher[i];
        cout << "\nDate added: " << dateAdded[i];
        cout << "\nQuantity: " << qtyOnHand[i];
        cout << "\nWholesale cost: " << wholesale[i];
        cout << "\nRetail Cost: " << retail[i];
    }

    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
}

void repWholsale()
{
    double total = 0.0;
    cout << "\nYou selected Inventory Wholesale Value";
    cout << "\nDate: 3/24/2023";
    cout << "\nReport: ";

    for (int i = 0; i < arraySize; i++)
    {
        if (bookTitle[i] == "")
            continue;
        cout << "\nBook name: " << bookTitle[i];
        cout << "\nisbn: " << isbn[i];
        cout << "\nQuantity: " << qtyOnHand[i];
        cout << "\nWholesale cost: " << wholesale[i];
        double bookTotal = wholesale[i] * qtyOnHand[i];
        total += bookTotal;
        cout << "\nTotal wholesale cost: " << bookTotal;
    }

    cout << "\nTotal wholesale value of inventory: " << total;

    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
}

void repRetail()
{
    cout << "\nYou selected Inventory Retail Value";
    double total = 0.0;
    cout << "\nDate: 3/24/2023";
    cout << "\nReport: ";

    for (int i = 0; i < arraySize; i++)
    {
        if (bookTitle[i] == "")
            continue;
        cout << "\nBook name: " << bookTitle[i];
        cout << "\nisbn: " << isbn[i];
        cout << "\nQuantity: " << qtyOnHand[i];
        cout << "\nRetail cost: " << retail[i];
        double bookTotal = wholesale[i] * qtyOnHand[i];
        total += bookTotal;
        cout << "\nTotal retail cost: " << bookTotal;
    }
    cout << "\nTotal wholesale value of inventory: " << total;

    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
}

void repQty()
{
    cout << "\nYou selected Listing by Quantity";
    cout << "\nDate: 3/24/2023";
    cout << "\nReport: ";

    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = 0; j < arraySize - i - 1; j++)
        {
            if (qtyOnHand[j] < qtyOnHand[j + 1])
            {
                swap(bookTitle[j], bookTitle[j + 1]);
                swap(isbn[j], isbn[j + 1]);
                swap(qtyOnHand[j], qtyOnHand[j + 1]);
            }
        }
    }

    for (int i = 0; i < arraySize; i++)
    {
        if (bookTitle[i] == "")
            continue;
        cout << "\nBook name: " << bookTitle[i];
        cout << "\nisbn: " << isbn[i];
        cout << "\nQuantity: " << qtyOnHand[i];
    }

    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
}

void repCost()
{
    cout << "\nYou selected Listing by Cost";
    cout << "\nDate: 3/24/2023";
    cout << "\nReport: ";

    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = i + 1; j < arraySize; j++)
        {
            if (wholesale[i] < wholesale[j])
            {
                swap(bookTitle[i], bookTitle[j]);
                swap(isbn[i], isbn[j]);
                swap(qtyOnHand[i], qtyOnHand[j]);
                swap(retail[i], retail[j]);
                swap(wholesale[i], wholesale[j]);
            }
        }
    }

    for (int i = 0; i < arraySize; i++)
    {
        if (bookTitle[i] == "")
            continue;
        cout << "\nBook name: " << bookTitle[i];
        cout << "\nisbn: " << isbn[i];
        cout << "\nWholesale Cost: " << wholesale[i];
    }

    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
}

void repAge()
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = 0; j < arraySize - i - 1; j++)
        {
            string date1 = dateAdded[j];
            string date2 = dateAdded[j + 1];

            int pos1 = -1, pos2 = -1;
            for (int k = 0; k < date1.size(); k++)
            {
                if (date1[k] == '/')
                {
                    pos1 = k;
                    break;
                }
            }
            for (int k = 0; k < date2.size(); k++)
            {
                if (date2[k] == '/')
                {
                    pos2 = k;
                    break;
                }
            }

            if (pos1 == -1 || pos2 == -1)
            {
                continue;
            }

            int day1 = stoi(date1.substr(0, pos1));
            int day2 = stoi(date2.substr(0, pos2));
            int month1 = stoi(date1.substr(pos1 + 1, 2));
            int month2 = stoi(date2.substr(pos2 + 1, 2));
            int year1 = stoi(date1.substr(pos1 + 4, 4));
            int year2 = stoi(date2.substr(pos2 + 4, 4));

            // Compare the dates using the year, month, and day
            if (year1 < year2 || (year1 == year2 && month1 < month2) ||
                (year1 == year2 && month1 == month2 && day1 < day2))
            {
                swap(dateAdded[j], dateAdded[j + 1]);
            }
        }
    }
    for (int i = 0; i < arraySize; i++)
    {
        if (bookTitle[i] == "")
            continue;
        cout << "\nBook name: " << bookTitle[i];
        cout << "\nisbn: " << isbn[i];
        cout << "\nDate Added: " << dateAdded[i];
    }

    // Ask user to press any key to continue
    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int reports()
{
    int choice;
    do
    {

        cout << "\n\n"
             << setw(44) << "Serendipity Book Sellers" << endl;
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
        switch (choice)
        {
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
