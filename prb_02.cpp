/** Project - 02 **/
/** BookShop Management **/

#include <bits/stdc++.h>
using namespace std;
#define READ(f)         freopen(f, "r", stdin)
#define WRITE(f)        freopen(f, "w", stdout)

#define __              std::ios_base::sync_with_stdio(false); cin.tie(0);
#define ___             cerr << endl << "Execution Time : " << 1 * clock() / CLOCKS_PER_SEC << endl;
#define START           double start_s=clock();
#define STOP            double stop_s=clock();
#define _               cerr << "Time Elapsed : " << (stop_s-start_s)/double(CLOCKS_PER_SEC);

#define mem(x,y)        memset(x,y,sizeof(x))
#define DEBUG(x)        cout << #x << " = " << x << endl

#define TC(T)           int T;cin>>T;while(T--)
#define FTC(T)          int T;cin>>T;for(int TestCase=1;TestCase<=T;TestCase++)
#define CASE_OUT()      cout << "Case " << TestCase << ": ";
#define pf              cout <<
#define sc              cin >>

#define ERR             1e-9
#define pi              (2*acos(0))
#define PI              3.141592653589793
#define MOD             1000000009
#define el              cout << endl
#define bor             |
#define infinity        1e10

typedef long double LD;
typedef unsigned int UI;
typedef long long int LL;
typedef unsigned long long int ULL;
#define SS              stringstream
#define vi              vector<int>
#define vii             vector< vi >
#define pb              push_back


class BookStore;
class Person
{
    string name, birthday;
    public:
        Person() {}
        Person(string name, string birthday) {
            this->name = name;
            this->birthday = birthday;
        }
        void viewPerson() {
            pf"Name: " ; pf name; el;
            pf"Date of birth: "; pf birthday; el;
        }
};

class Book
{
        int quantity = 0;
        double price;
        string bookName, writersName, category;

    public:
        Book()  {}
        Book(string bookName, string writersName, string category, double price, int quantity) {
            this->bookName = bookName; this->writersName = writersName; this->category = category ;
            this->price = price; this->quantity += quantity;
        }
        void viewBook() {
            pf("Book name: "); pf this->bookName; el; pf("Writer name: "); pf this->writersName; el;
            pf("Price: "); pf this->price; el; pf("Category: "); pf this->category; el;
            pf("Category: "); pf this->category; el;
        }
        double getPrice(int x) {
            return price;
        }
        double getQuantity(int x) {
            return quantity;
        }
        void setQuantity(int x) {
            quantity += x;
        }
        friend double selectBook( BookStore stor );
};

class Customer : public Person
{
        double payment = 0;
        string customer_no;
    public:
        Customer() {}
        Customer(string name,string birthday, string customer_no): Person(name,birthday) {
            this->customer_no = customer_no;
        }
        double getPayment() {
            return payment;
        }
        string getID() {
            return customer_no;
        }

        void outCustomer() {
            pf"Customer No: "; pf this->customer_no; el; viewPerson(); pf"Payment: "; pf this->payment; el;
        }
        void viewCustomer() {
            pf"Customer ID: " ; pf this->customer_no; el; viewPerson();
        }
        void clearPayment() {
            payment = 0;
        }
        void setPayment(double x) {
            payment += x;
        }
};


class BookStore
{
        vector <Customer> customers;
        vector <Book> books;
    public:
        int checkCustomer(string ss) {
            bool flag = false;
            int i;
            for(i = 0; i < customers.size(); i++) {
                if(customers[i].getID()==ss) {
                    flag = true;
                    break;
                }
            }
            if(flag) return i;
            return -1;
        }
        friend double selectBook(BookStore stor);
        void getCustomer(Customer customer) {
            customers.pb(customer);
        }
        void setPayment(int i, double x) {
            customers[i].setPayment(x);
        }
        void getBook(Book book) {
            books.pb(book);
        }
        Customer getCustomer(int i) {
            return customers[i];
        }
        void clearCustomer(int i) {
            customers[i].clearPayment();
        }
};

double selectBook( BookStore store ) {
    double xx = 0;
    for(int i = 0; i < store.books.size(); i++) {
        int x;
        store.books[i].viewBook(); pf"Enter 1 to buy book, 0 to ignore: "; sc x;
        if(x == 1) xx += store.books[i].price;
    }
    return xx;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // READ("input.txt");
    //WRITE("output.txt");

    int x , check;
    BookStore bookStore;
    string a , b, c , str;
    double pay , m;
    while(true)
    {
        pf"Please, enter 1 to input Customer in book store,"; el;
        pf"Please, enter 2 to input Book into book store, "; el;
        pf"Please, enter 3 to see customer data,"; el;
        pf"Please, enter 4 to buy books,"; el;
        pf"Please, enter 5 to clear payment," ; el;
        pf"Please, enter 0 to exit: "; el; sc x;

        if(!x) {
            break;
        }
        else if(x) {
            if(x == 1) {
                pf"Please, enter Customer Name: "; sc a;
                pf"Please, enter Customer Date of birth: "; sc b;
                pf"Please, enter Customer ID: "; sc c;
                Customer customer(a,b,c);
                bookStore.getCustomer(customer);
            }
            if(x == 2) {
                double m; int n;
                pf"Please, enter book Name: "; sc a;
                pf"Please, enter writer name: "; sc b;
                pf"Please, enter Category: "; sc c;
                pf"Please, enter Price: "; sc m;
                pf"Please, enter quantity: "; sc n;
                bookStore.getBook(Book(a,b,c,m,n));
            }
             if(x == 3) {
                    pf"Please, enter your ID: "; sc str;
                    check = bookStore.checkCustomer(str);
                    if(check != -1) {
                        Customer c = bookStore.getCustomer(check);
                        c.viewCustomer(); el;
                    }
                    else pf"User Not Found" ; el;
                }
            if(x == 4) {
                pf"Please, enter customer no: "; sc str;
                check = bookStore.checkCustomer(str);
                if( check != -1) {
                    pay = selectBook(bookStore);
                    bookStore.setPayment(check, pay);
                }
                else pf"User Not Found" ; el;
            }

            if(x == 5) {

                pf "Please, enter your ID: "; sc str;
                check = bookStore.checkCustomer(str);

                if(check != -1) {
                    Customer c = bookStore.getCustomer(check);
                    pf"Please,  pay "<<c.getPayment()* 0.90<<" Taka(10%% discount): "; sc m;
                    if((c.getPayment()*0.90) == m) {
                        bookStore.clearCustomer(check);
                    }
                }
                else pf "User Not Found" ; el;
            }
        }
    }
    return 0;
}
