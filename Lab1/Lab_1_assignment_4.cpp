/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include <iostream>
using namespace std;

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

int main() {
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

