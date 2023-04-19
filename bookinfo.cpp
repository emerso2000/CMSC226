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
#include <string>
#include "bookinfo.h"
using namespace std;

const int arraySize = 20;

extern char bookTitle[arraySize][51];
extern char isbn[arraySize][14];
extern char author[arraySize][31];
extern char publisher[arraySize][31];
extern char dateAdded[arraySize][11];
extern int qtyOnHand[arraySize];
extern double wholesale[arraySize];
extern double retail[arraySize];

int bookInfo(char isbn[14], char title[51], char author[31], char publisher[31], char date[11], int qty, double wholesale, double retail) {
    cout << "\n\t\t\t\tSerendipity Book Sellers\n";
    cout << "\t\t\t\tBook Information\n";

    cout << "\n\tISBN: " << isbn << endl;
    cout << "\tTitle: " << title << endl;
    cout << "\tAuthor: " << author << endl;
    cout << "\tPublisher: " << publisher << endl;
    cout << "\tDate Added: " << date << endl;
    cout << "\n\tQuantity-On-Hand: " << qty;
    cout << "\n\tWholesale Cost: " << wholesale;
    cout << "\n\tRetail Price: " << retail;

    return 0;
}