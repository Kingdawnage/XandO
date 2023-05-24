#include <iostream>
#include <vector>

using namespace std;

// Defining the board and the players

const int boardSize = 3;
const char player1 = 'X';
const char player2 = 'O';

// Defining the layout of the board using the vector library to display it as a 3x3 array
void view_board(const vector<vector<char>>& board){
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Defining the boundaries of feasible moves using conditional statements
bool is_correct_move(const vector<vector<char>>& board, int row, int col){
    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize){
        return false;
    }
    else if (board[row][col] != ' '){
        return false;
    }
    return true;
}

// Determining the winner across each column and row and diagonally
bool is_winner(const vector<vector<char>>& board, char player){
    for (int i = 0; i < boardSize; i++){
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }
        else if (board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player){
        return true;
    }
    return false;
}

// Checking for when the board is full
bool is_board_full (const vector<vector<char>>& board){
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            if (board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char>> board(boardSize, vector<char>(boardSize, ' '));
    int row, col;
    char player = player1;

    while (!is_winner(board, player1) && !is_winner(board, player2) && !is_board_full(board)){
        cout << player << "'s turn" << endl;
        view_board(board);
        cout << "Enter desired row and column: ";
        cin >> row >> col;
        
        if (is_correct_move(board, row, col)){
            board[row][col] = player;
            if(is_winner(board, player1)){
                cout << "Player " << player << " wins!" << endl;
            }
            if(is_board_full(board)){
                cout << "It'a tie game" << endl;
            }
            player = (player == player1) ? player2 : player1;
        }
    }

    return 0;
}