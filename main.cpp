// Created by Doniyorbek Ibrokhimov
// ID - 210046
// Lab 3 class assignment

#include <iostream>

using namespace std;

int main() {
    // task1
    int size = 3;
    int *ptr_array = new int[size];

    int counter = 0;
    char decision;
    for (int i = 0; i < size; i++) {
        cout << "Enter a number to the array:->";
        cin >> ptr_array[counter];
        counter++;
        cout << "To stop press any key" << "If you want to continue to add numbers press 'Y':->";
        cin >> decision;
        if (decision != 'Y') break;
        if (counter == size) {
            size *= 2;
            int *temp_ptr_array = new int[size];
            for (int j = 0; j < size / 2; j++) {
                temp_ptr_array[counter] = ptr_array[counter];
            }
            delete[] ptr_array;
            ptr_array = temp_ptr_array;
        }
    }

    //task2
    class Book {
    private:
        string Name_book, Name_author, Name_publisher;
        int ISSN = 0, Edition = 0, AssignedCMS = 0;
        bool isAvailable;
    public:
        // i
        Book() {
            isAvailable = true;
        }

        // ii
        Book(string Name_bookFun, string Name_authorFun, string Name_pubFun, int ISSNFun) {
            Name_book = Name_bookFun;
            Name_author = Name_authorFun;
            Name_publisher = Name_pubFun;
            ISSN = ISSNFun;
            Edition = 1;
            isAvailable = true;
        }

        // iii
        Book(string Name_bookFun, string Name_authorFun, string Name_pubFun, int ISSNFun, int EditionFun) {
            Name_book = Name_bookFun;
            Name_author = Name_authorFun;
            Name_publisher = Name_pubFun;
            ISSN = ISSNFun;
            Edition = EditionFun;
            isAvailable = true;
        }

        // iv
        void inputDetails() {
            cout << "Enter the name of the book: ";
            cin >> Name_book;
            cout << "Enter the name of the author: ";
            cin >> Name_author;
            cout << "Enter the name of the publisher: ";
            cin >> Name_publisher;
            cout << "Enter the ISSN number: ";
            cin >> ISSN;
            cout << "Enter the Edition number: ";
            cin >> Edition;
            cout << "Enter the Assigned CMS number ";
            cin >> AssignedCMS;
        }

        // v
        // needs input before calling
        bool DispDetails(string Name_bookFun) {
            if (Name_bookFun == Name_book) {
                cout << "The book name is: " << Name_book << endl
                     << "The author name is: " << Name_author << endl
                     << "The publisher name is: " << Name_publisher << endl
                     << "The ISSN number is: " << ISSN << endl
                     << "The Assigned CMS is: " << AssignedCMS << endl
                     << "The Edition number is: " << Edition << endl
                     << "The availability status is: " << isAvailable << endl;
                return true;
            } else {
                cout << "There is no such book" << endl;
                return false;
            }
        }

        // vi
        // needs input before calling
        bool DispDetails(int ISSNFun) {
            if (ISSNFun == ISSN) {
                cout << "The book name is: " << Name_book << endl
                     << "The author name is: " << Name_author << endl
                     << "The publisher name is: " << Name_publisher << endl
                     << "The ISSN number is: " << ISSN << endl
                     << "The Assigned CMS is: " << AssignedCMS << endl
                     << "The Edition number is: " << Edition << endl
                     << "The availability status is: " << isAvailable << endl;
                return true;
            } else {
                cout << "There is no such book" << endl;
                return false;
            }
        }

        //vii
        void DispDetails() {
            cout << "The book name is: " << Name_book << endl
                 << "The author name is: " << Name_author << endl
                 << "The publisher name is: " << Name_publisher << endl
                 << "The ISSN number is: " << ISSN << endl
                 << "The Assigned CMS is: " << AssignedCMS << endl
                 << "The Edition number is: " << Edition << endl
                 << "The availability status is: ";
            if (isAvailable) cout << "available\n";
            else cout << "not available\n";
        }

        //viii
        bool AvailabilityStatus() {
            return isAvailable;
        }

        // ix
        void issueBook(int cms_id) {
            if (!isAvailable) {
                cout << "Book is already issued to a student with CMS id: " << AssignedCMS << endl;
            } else {
                AssignedCMS = cms_id;
                cout << "The book " << Name_book << " is successfully assigned to " << cms_id << endl;
                isAvailable = false;
            }
        }
    };

    class Library : public Book {
    private:
        string Librarian;
        int maxBookNums, currBooksNum;
        Book *booksPtr;
    public:
        // i
        Library(string LibrarianFun) {
            Librarian = LibrarianFun;
            maxBookNums = 100;
            booksPtr = new Book[maxBookNums];
            currBooksNum = 0;
        }

        // ii
        Library(string LibrarianFun, int maxSizeFun) {
            Librarian = LibrarianFun;
            maxBookNums = maxSizeFun;
            booksPtr = new Book[maxBookNums];
            currBooksNum = 0;
        }

        // iii
        void DispBookDetails() {
            DispDetails();
        }

        // iv
        void addBook() {
            inputDetails(); // add that book to the dynamic array of objects -- misunderstanding part
            if (currBooksNum < maxBookNums) currBooksNum++;
            // Make sure that the currBooksNum doesn't exceed the maximum size -- misunderstanding part
        }

        // v
        bool searchBook(string Name_bookFun) {
            return DispDetails(Name_bookFun);
        }

        // vi
        void assignBook(int cms_id, string Name_bookFun) { // why do we need name of the book
            issueBook(cms_id);
        }

        // vii
        ~Library() {
            cout << "Library destructor is working" << endl;
        };
    };

    // task 3
    class TwoDRandArray {
    public:
        int **Ptr;
        int numRows;
        int *numColsPtr;

        TwoDRandArray(int numRowsFun, int numColsFun[]) {
            numRows = numRowsFun;
            numColsPtr = numColsFun;

            Ptr = new int *[numRows];
            for (int i = 0; i < numRows; i++) {
                Ptr[i] = new int[numColsPtr[i]];
                for (int j = 0; j < numColsPtr[i]; ++j) {
                    Ptr[i][j] = 0;
                }
            }
        }

        void getInput() {
            for (int i = 0; i < numRows; i++) {
                for (int j = 0; j < *numColsPtr; j++) {
                    cout << "Enter the value for array Ptr[" << i << "][" << j << "] ->";
                    cin >> Ptr[i][j];
                }
            }
        }

        void display() {
            for (int i = 0; i < numRows; i++) {
                for (int j = 0; j < numColsPtr[i]; j++) {
                    cout << "the values for array Ptr[" << i << "][" << j << "] is " << Ptr[i][j] << endl;
                }
            }
        }

        ~TwoDRandArray() {
            cout << "TwoDRandArray destructor is working\n";
        };
    };

    // testing task 2
    Book book1("cp", "Doniyor", "DoniyorLTD", 001, 2);
    Book book2("physics", "Konstantin", "Maslov", 002, 3);
    Book book3("statistics", "Bahodir", "Akhmedov", 003, 4);

    Library lib("Doniyor", 100);

    cout << "Add a book to the library\n";
    lib.addBook();
    lib.DispBookDetails();
    lib.issueBook(210087);
    lib.searchBook("CP");
    lib.assignBook(210052, "math");

    book1.DispDetails("cp");
    book1.DispDetails(001);
    cout << "Availability status is: " << book1.AvailabilityStatus() << endl;
    book1.issueBook(210046);
    book1.issueBook(210032);

    cout << "Book 2 details started\n";
    book2.DispDetails("cp");
    book2.DispDetails(001);
    cout << "Availability status is: " << book2.AvailabilityStatus() << endl;
    book2.issueBook(210046);
    book2.issueBook(210032);

    lib.DispBookDetails();

    // testing task 3
    int test_cols[3] = {3, 1, 2};
    TwoDRandArray obj(3, test_cols);
    obj.display();

    return 0;
}