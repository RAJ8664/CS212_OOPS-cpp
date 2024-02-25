/*Author : RAJ ROY*/
/*Scholar Id = 2212002*/

#include<iostream>
#include<string>
using namespace std;


class Salesperson;

class Sale {
private:
    int dayOfMonth;
    double amount;
    int salespersonID;

public:
    Sale(int day, double amt, int id)  {
        dayOfMonth = day;
        amount = amt;
        salespersonID = id;
    }

    friend void display(const Sale& sale, const Salesperson& salesperson);
    int getSalespersonID() const { return salespersonID;}
};

class Salesperson {
private:
    int salespersonID;
    string lastName;

public:
    Salesperson(int id, string name) {
        salespersonID = id;
        lastName = name;
    }

    friend void display(const Sale& sale, const Salesperson& salesperson);
    int getSalespersonID() const { return salespersonID; }
};

// Friend function to print data from both classes
void display(const Sale& sale, const Salesperson& salesperson) {
    cout << "Date: " << sale.dayOfMonth << endl;
    cout << "Amount: " << sale.amount << endl;
    cout << "Salesperson ID: " << salesperson.salespersonID << endl;;
    cout << "Salesperson Name: " << salesperson.lastName << endl;
    cout << endl;
}

int main() {
    Sale sale1(15, 50000.50, 500);
    Salesperson salesperson1(101, "RAJ ROY");

    display(sale1, salesperson1);

    return 0;
}