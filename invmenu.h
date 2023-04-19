#include <iostream>
#include <string>
#include <cstring>
using namespace std;


struct BookData;

void strUpper(char *str);

void setTitle(const char *title, int index);

void setISBN(const char *isbn_num, int index);

void setAuthor(const char *author_name, int index);

void setPub(const char *publisher_name, int index);

void setDateAdded(const char *date, int index);

int invMenu();

void lookUpBook();

void addBook();

void editBook();

void deleteBook();

void replaceBook(string bookName, string replacement);

void removeBook(string bookName);

int isEmpty(int index);

void setRetail(double price, int index);

void setWholesale(double price, int index);

void setQty(int qty, int index);
