/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include<iostream>
using namespace std;

class Bank{
    private:
        string Name_of_depositor;
        string Account_Number;
        string Type_of_Account;
        double Balance;

    public:
        // Parameterized Constructor
        Bank(string Name, string account_number, string type_of_account, double balance) {
            Name_of_depositor = Name;
            Account_Number = account_number;
            Type_of_Account = type_of_account;
            Balance = balance;

        }

         // Default Constructor
        Bank() {
            Name_of_depositor = "";
            Account_Number = "";
            Type_of_Account = "";
            Balance = 0.0;
        }


         // Destructor
        ~Bank() {
            cout << "Destructor called for " << Name_of_depositor << endl;
        }

        
        void deposit( double amount) {
            cout << "Depositing Amount-->" << " " << amount << endl;
            Balance += amount;
            cout << "Amount Deposited Successfully and the new Balance is-->" << " " << Balance << endl;
        }

        void withdraw(double amount) {
            if(amount > Balance) {
                cout << "Not enough Balance" << endl;
            }
            else {
                cout << "Withdrawing Amount" << " " << amount << endl;
                Balance = Balance - amount;
                cout << "Balance Remaining is -->" << " " << Balance << endl;
            }
        }

        void info() {
            cout << "Name-->" << " " << Name_of_depositor << endl;
            cout << "Balance-->" << " " << Balance << endl;
        }  
};

int main() {
    
    Bank person1 = Bank("RAJ" , "2212002" , "Saving" , 50000.14);
    Bank person2 = Bank("NIKHIL" , "22120070" , "Saving" , 1500.25);
    Bank person3 = Bank("BISHAL" , "22120056" , "Saving" , 2500.25);
    Bank person4 = Bank("SAM" , "22120090" , "Saving" , 3500.25);
    Bank person5 = Bank("KARAN" , "22120012" , "Saving" , 4500.25);
    Bank person6 = Bank("KANIKA" , "22120034" , "Saving" , 5500.25);
    Bank person7 = Bank("SUMIT" , "22120088" , "Saving" , 6500.25);
    Bank person8 = Bank("ISHU" , "22120099" , "Saving" , 7500.25);
    Bank person9 = Bank("THOMAS" , "22120011" , "Saving" , 8500.25);
    Bank person10 = Bank("BRUCE" , "22120066" , "Saving" , 9500.25);
    
    person1.info();
    person2.info();
    person3.info();
    person4.info();
    person5.info();
    person6.info();
    person7.info();
    person8.info();
    person9.info();
    person10.info();
    return 0;
}