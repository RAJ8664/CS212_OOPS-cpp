/*Author : RAJ ROY*/
/*Scholar Id = 2212002*/

#include <iostream>
#include <string>
#include <array>
using namespace std;



class Salesperson; 
class Sale {
private:
    int dayOfMonth;
    double amount;
    int salespersonID;

public:
    Sale(int day, double amt, int id) {
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

// Friend function to display data from both classes
void display(const Sale& sale, const Salesperson& salesperson) {
    cout << "Date: " << sale.dayOfMonth << "\n";
    cout << "Amount: " << sale.amount << "\n";
    cout << "Salesperson ID: " << salesperson.salespersonID << endl;
    cout << "Salesperson Name: " << salesperson.lastName << endl;
    cout << endl;
}

int main() {
    const int numSalespersons = 5;
    array<Salesperson, numSalespersons> salespersons = {
        Salesperson(2212002, "RAJ ROY"),
        Salesperson(22120069, "SUMIT"),
        Salesperson(2212017, "KANIKA"),
        Salesperson(2212077, "NIKHIL"),
        Salesperson(17216211, "UNKNOWN")
    };

    int day;
    double amount;
    int salespersonID;

    while (true) {
        cout << "Enter sale data (day, amount, salesperson ID): ";
        cin >> day >> amount >> salespersonID;
        if (day == -1) break;
        bool valid = false;
        for (const auto& sp : salespersons) {
            if (sp.getSalespersonID() == salespersonID) {
                valid = true;
                break;
            }
        }

        if (valid) {
            Sale sale(day, amount, salespersonID);
            display(sale, Salesperson(salespersonID, " "));
        } else {
            cout << "Invalid salesperson ID. Please enter a valid salesperson ID" << endl;;
        }
    }
    return 0;
}