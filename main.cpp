#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {
    //
    //    PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);

    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
}

void makeAMove(char b[][3], char player){
    int rowNumber;
    int columnNumber;
    
    cout<<"Enter a row (0, 1, 2) for player" << player<< "\t:"<< endl;
    cin >> rowNumber;
    cin.
    cout<<"Enter a column (0, 1, 2) for player" << player<< ":"<< endl;
    cin>> columnNumber;
    if (b[rowNumber][columnNumber] != 'X' && b[rowNumber][columnNumber] != 'O') {
        b[rowNumber][columnNumber] = player;
    } else{
        cout<<"This cell is already occupied. Try a different cell" << endl;
    }
}

void displayBoard(char b[][3]){
    cout <<"-------------" << endl;
    cout <<"| "<<b[0][0]<<" | "<<b[0][1]<<" | "<<b[0][2]<<" |" << endl;
    cout <<"-------------" << endl;
    cout <<"| "<<b[1][0]<<" | "<<b[1][1]<<" | "<<b[1][2]<<" |" << endl;
    cout <<"-------------" << endl;
    cout <<"| "<<b[2][0]<<" | "<<b[2][1]<<" | "<<b[2][2]<<" |" << endl;
    cout <<"-------------" << endl;
}

bool isDraw(char b[][3]){
    int result = 0;
    int usedCell = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(b[i][j] != ' '){
                ++usedCell;
            }
            if (usedCell == 9) {
                result = 1;
            }else{
            result = 0;
            }
        }
    }
    return result;
}

bool isWon(char player, char b[][3]){
    int playerWon = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 1; j++){
            if (b[i][j] == player && b[i][j+1] == player && b[i][j+2] == player) {
                playerWon = 1;
            }else if (b[i][j] == player && b[i+1][j] == player && b[i+2][j] == player) {
                playerWon = 1;
            }
        }
    }
    if (b[1][1] != ' ' && ((b[0][0] == b[1][1] && b[0][0] == b[2][2]) || (b[2][0] == b[1][1] && b[2][0] == b[0][2]))){
        playerWon = 1;
    }
    return playerWon;
}
