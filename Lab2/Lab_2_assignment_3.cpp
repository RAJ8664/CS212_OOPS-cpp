/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include<iostream>
using namespace std;


/*Lab1 by using constructor and destructor  as per the utilization*/

/*-----------------------------------------------------------------------------------------------------*/
/*Lab1 assignment2 using constructor and destructor*/
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

/*------------------------------------------------------------------------------------------*/



/*Lab1 assignment3 using constructor and destructor*/
class DB; 

class DM {
private:
    int meters;
    float centimeters;

public:
   // Default Constructor
    DM() {
        meters = 0;
        centimeters = 0.0;
    }

    // Parameterized Constructor
    DM(int m, float cm) {
        meters = m;
        centimeters = cm;
    }

    // Destructor
    ~DM() {
        cout << "Destructor called for DM object" << endl;
    }

    void setDistance(int m, float cm) {
        meters = m;
        centimeters = cm;
    }

    friend DM addDistances(const DM& d1, const DB& d2);
    friend void displayDistance(const DM& d);
};

class DB {
private:
    int feet;
    float inches;

public:
    
    // Default Constructor
    DB() {
        feet = 0;
        inches = 0.0;
    }

    // Parameterized Constructor
    DB(int ft, float inch) {
        feet = ft;
        inches = inch;
    }

    // Destructor
    ~DB() {
        cout << "Destructor called for DB object" << endl;
    }

    void setDistance(int ft, float inch) {
        feet = ft;
        inches = inch;
    }

    friend DM addDistances(const DM& d1, const DB& d2);
    friend void displayDistance(const DB& d);
};

DM addDistances(const DM& d1, const DB& d2) {
    DM result;
    float totalMeters = d2.feet * 0.3048 + d2.inches * 0.0254;
    result.meters = d1.meters + static_cast<int>(totalMeters);
    result.centimeters = d1.centimeters + (totalMeters - static_cast<int>(totalMeters)) * 100;
    return result;
}

void displayDistance(const DM& d) {
    cout << "Distance: " << d.meters << " meters and " << d.centimeters << " centimeters." << std::endl;
}

void displayDistance(const DB& d) {
    cout << "Distance: " << d.feet << " feet and " << d.inches << " inches." << std::endl;
}
/*-----------------------------------------------------------------------------------------------------------------------------*/


/*Lab1 assignment4 using constructor and destructor*/


class ticTacToe {
private:
    char board[3][3];
    char currentPlayer; // 'X' or 'O' for the current player

public:
    // Default Constructor
    ticTacToe() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X'; // Start with player 'X'
    }

    // Destructor
    ~ticTacToe() {
        cout << "Destructor called for ticTacToe object" << endl;
    }

    void printBoard() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "---------" << endl;
        }
        cout << endl;
    }

    bool isValidMove(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    void makeMove(int row, int col) {
        
        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;
            switchPlayer(); 
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    bool checkWinner() const {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true; 
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true; 
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true; 
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true; 
        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    const char (*getBoard())[3] {
        // Return a const pointer to the board array
        return board;
    }

    char getCurrentPlayer() const {
        // Return the current player ('X' or 'O')
        return currentPlayer;
    }
};

/*-----------------------------------------------------------------------------------------------------------------------------------------*/


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




    DM dmObj;
    DB dbObj;

    // Set distances for DM and DB objects
    dmObj.setDistance(12, 31.0);
    dbObj.setDistance(2, 9.9);

    // Add DM and DB distances
    DM result = addDistances(dmObj, dbObj);

    // Display the result in the appropriate format
    displayDistance(result);




    ticTacToe game;

    while (true) {
        game.printBoard();

        int row, col;
        cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
        cin >> row >> col;

        game.makeMove(row, col);

        if (game.checkWinner()) {
            game.printBoard();
            cout << "Player " << game.getCurrentPlayer() << " wins!" << std::endl;
            break;
        }

        // Check for a tie
        bool isTie = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (game.getBoard()[i][j] == ' ') {
                    isTie = false;
                    break;
                }
            }
            if (!isTie) break;
        }

        if (isTie) {
            game.printBoard();
            cout << "It's a tie!" << std::endl;
            break;
        }
    }


    return 0;
}