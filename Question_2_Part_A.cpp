#include <iostream>
#include <string>
using namespace std;

class Books
{
    // this will be like a node
public:
    string author;
    string title;
    float price;
    string publisher;
    int stock;
    // next pointer
    Books *next;

    Books(string auth, string title, float price, string publisher, int stock)
    { // constructor for the Books class
        this->author = auth;
        this->title = title;
        this->price = price;
        this->publisher = publisher;
        this->stock = stock;
        // next null nu hi point kre
        this->next = NULL;
    }
};

class Inventory
{
    Books *head;
    Books *tail;

public:
    Inventory()
    {
        // this is a empty constructor made just to intialise the values of the head and tail pointer
        head = tail = NULL;
    }

    // the below function is to add new books to the inventory
    void add_book(string auth, string title, float price, string publisher, int stock)
    {
        // just like the puch back function of the Linked List

        Books *newbook = new Books(auth, title, price, publisher, stock); // ehe ikk new node bnauga

        // what is the book is the first one
        if (head == NULL)
        {                          // this means the linked list is empty
            head = tail = newbook; // head and tail will both point to the same node because it is the first node
        }
        else
        { // what if it is not the first node
            // then we will insert it as the first node
            newbook->next = head;
            head = newbook;
        }
    }

    void search_book()
    {
        Books *ptr = head; // ikk pointer which will traverse and find the book in the Inventory
        // input the title of the book to be found
        cout << "Enter the Title of the Book: ";
        string search_title, search_author;
        getline(cin, search_title);
        cout << "Enter the Author of the Book: ";
        getline(cin, search_author);

        // traverse the list to find the book
        while (ptr != NULL)
        {
            if (ptr->title == search_title)
            {
                // means we found the book
                cout << "Book in Stock" << endl;

                // input the number of copies needed
                cout << "Enter the Number of Copies: ";
                int copies;
                cin >> copies;
                // now check if we have the required number of Copies
                if (ptr->stock >= copies)
                { // means we have the copies required
                    // display the cost
                    cout << "The total cost of the Books is " << ((ptr->price) * copies) << endl;
                }
                else
                {
                    // means we don't have the number of copies needed
                    cout << "Required Copies not in the Stock " << endl;
                }
                return;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        // this means we haven't found the book as if we have found it then it would not be executed
        cout << "The Book is NOT in the Stock " << endl;
    }
};

int main()
{

    Inventory l1;
    // string auth,string title,float price,string publisher,int stock
    l1.add_book("Bjarne Stroustrup", "The C++ Programming Language", 750.0, "Addison-Wesley", 8);
    l1.add_book("E. Balagurusamy", "Object Oriented Programming with C++", 550.0, "McGraw Hill", 12);
    l1.add_book("Herbert Schildt", "C++: The Complete Reference", 600.0, "Tata McGraw Hill", 5);
    l1.add_book("Robert Lafore", "OOP in C++", 500.0, "Pearson", 10);
    l1.add_book("Yashavant Kanetkar", "Let Us C++", 450.0, "BPB Publications", 15);
    l1.add_book("Andrew S. Tanenbaum", "Modern Operating Systems", 700.0, "Pearson", 6);

    l1.search_book();

    return 0;
}