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
        void setISBN(const char* isbn, int index) {
            strcpy(isbn, isbn);
        }
};