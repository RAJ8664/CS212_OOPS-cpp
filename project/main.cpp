#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> snakes;
vector<pair<int, int>> ladders;

class Board {
private:
    const int SIZE = 10;
    const int WINNING_POSITION = 100;
    const int NUM_SNAKES = 10;
    const int NUM_LADDERS = 15;
    const char PLAYER1_SYMBOL = 'P';
    const char PLAYER2_SYMBOL = 'Q';
    const char SNAKE_SYMBOL = 'S';
    const char LADDER_SYMBOL = 'L';

    
public:

    void generateSnakesAndLadders() {
        // Generate snake positions
        for (int i = 0; i < NUM_SNAKES; ++i) {
            int head = rand() % (WINNING_POSITION - 1) + 2; // Ensure snakes don't start from position 1
            int tail = rand() % head + 1; // Tail should be before the head
            snakes.push_back({head, tail});
        }

        // Generate ladder positions
        for (int i = 0; i < NUM_LADDERS; ++i) {
            int bottom = rand() % (WINNING_POSITION - 1) + 2; // Ensure ladders don't start from position 1
            int top = rand() % (WINNING_POSITION - bottom) + bottom + 1; // Top should be after the bottom
            ladders.push_back({bottom, top});
        }

        // Shuffle the positions
        //random_shuffle(snakes.begin(), snakes.end());
        //random_shuffle(ladders.begin(), ladders.end());
    }

    Board() {
        generateSnakesAndLadders();
    }

    void draw(int player1Position, int player2Position) {
        for (int i = SIZE; i >= 1; --i) {
            for (int j = 1; j <= SIZE; ++j) {
                int cellNumber = (i - 1) * SIZE + j;
                char symbol = getSymbol(cellNumber, player1Position, player2Position);
                if (symbol == PLAYER1_SYMBOL)
                    cout << "\033[1;31m" << symbol << "\033[0m   "; // Red color for Player 1
                else if (symbol == PLAYER2_SYMBOL)
                    cout << "\033[1;34m" << symbol << "\033[0m   "; // Blue color for Player 2
                else
                    cout << "\033[1;30m" << cellNumber << "\033[0m   "; // White color for numbers
            }
            cout << endl << endl;
        }
    }

    char getSymbol(int cellNumber, int player1Position, int player2Position) {
        if (cellNumber == player1Position)
            return PLAYER1_SYMBOL;
        else if (cellNumber == player2Position)
            return PLAYER2_SYMBOL;
        else {
            for (const auto &snake : snakes) {
                if (cellNumber == snake.first)
                    return SNAKE_SYMBOL;
            }
            for (const auto &ladder : ladders) {
                if (cellNumber == ladder.first)
                    return LADDER_SYMBOL;
            }
            return ' ';
        }
    }

    pair<int, bool> checkSnakeOrLadder(int position) {
        for (const auto &snake : snakes) {
            if (position == snake.first)
                return {snake.second, true}; // Go back to the tail of the snake
        }
        for (const auto &ladder : ladders) {
            if (position == ladder.first)
                return {ladder.second, true}; // Climb up the ladder
        }
        return {position, false};
    }

    bool checkWin(int position) {
        return position >= WINNING_POSITION;
    }
};

template<typename T>
T rollDice(T minVal, T maxVal) {
    return rand() % (maxVal - minVal + 1) + minVal;
}

int main() {
    srand(time(0)); // Seed for random number generation

    
    Board board;
    int player1Position = 0;
    int player2Position = 0;
    bool player1Turn = true;
    //cout << snakes.size() << endl;

    cout << "Snake and Ladder Game\n\n";
    while (!board.checkWin(player1Position) && !board.checkWin(player2Position)) {
        
        board.draw(player1Position, player2Position);
        cout << "\n";

        cout << "Press Enter to roll the dice";
        cin.ignore(); // Wait for user to press Enter

        int dice = rollDice<int>(1, 6);
        cout << "You rolled a " << dice << endl;

        if (player1Turn) {
            cout << "Player 2's turn\n";
            player1Position += dice;
            auto result = board.checkSnakeOrLadder(player1Position);
            if (result.second) {
                if (player1Position > result.first)
                    cout << "Oops! You encountered a snake!\n";
                else
                    cout << "Congratulations! You climbed a ladder!\n";
            }
            player1Position = result.first;
            cout << "You are now at position " << player1Position << endl;
        } 
        else {
            cout << "Player 1's turn\n";
            player2Position += dice;
            auto result = board.checkSnakeOrLadder(player2Position);
            if (result.second) {
                if (player2Position > result.first)
                    cout << "Oops! You encountered a snake!\n";
                else
                    cout << "Congratulations! You climbed a ladder!\n";
            }
            player2Position = result.first;
            cout << "You are now at position " << player2Position << endl;
        }

        player1Turn = !player1Turn;
    }

    if (board.checkWin(player1Position))
        cout << "Congratulations! Player 1 reached the winning position." << endl;
    else
        cout << "Congratulations! Player 2 reached the winning position." << endl;

    return 0;
}

