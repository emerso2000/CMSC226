#include <iostream>
#include <cstring>

class BookData {
    private:
        char bookTitle[51];
        char isbn[14];
        char author[31];
        char publisher[31];
        char dateAdded[11];
        int qtyOnHand;
        double wholesale;
        double retail;
    public:
        // Accessor functions
        const char* getTitle() const {
            return bookTitle;
        }
        const char* getISBN() const {
            return isbn;
        }
        const char* getAuthor() const {
            return author;
        }
        const char* getPub() const {
            return publisher;
        }
        const char* getDateAdded() const {
            return dateAdded;
        }
        int getQty() const {
            return qtyOnHand;
        }
        double getWholesale() const {
            return wholesale;
        }
        double getRetail() const {
            return retail;
        }
        void setTitle(const char* title, int index) {
            strcpy(bookTitle, title);
        }
        void setISBN(const char* isbn_num, int index) {
            strcpy(isbn, isbn_num);
        }
        void setAuthor(const char* author_name, int index) {
            strcpy(author, author_name);
        }
        void setPub(const char* publisher_name, int index) {
            strcpy(publisher, publisher_name);
        }
        void setDateAdded(const char* date, int index) {
            strcpy(dateAdded, date);
        }
        void setQty(int qty, int index) {
            qtyOnHand = qty;
        }
        void setWholesale(double wholesale_price, int index) {
            wholesale = wholesale_price;
        }
        void setRetail(double retail_price, int index) {
            retail = retail_price;
        }
};
