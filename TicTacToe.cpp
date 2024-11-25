#include <iostream>
using namespace std;

void printBoard();
int checkwin();

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {
    int player = 1, input, status = -1;
    printBoard();

    while (status == -1) {
        if (player % 2 == 0) {
            player = 2;
        } else {
            player = 1;
        }

        char mark;

        if (player == 1) {
            mark = 'x';
        } else {
            mark = '0';
        }
        cout << " Dear Player " << player << "\n Enter a number:\n";
        cin >> input;

        if (input < 1 || input > 9) {
            cout << "Invalid input";
            continue;
        }

        board[input] = mark;
        printBoard();

        int result = checkwin();

        if (result == 1) {
            cout << "Congratulations! Player " << player << ". You are the winner, yahoo!\n";
            return 0;
        } else if (result == 0) {
            cout << "It's a Draw. Better Luck Next Time\n";
            return 0;
        }
        player++;
    }
    return 0;
}

void printBoard() {
    // system("cls"); // Uncomment this line for Windows to clear the screen
    system("cls");
    cout << "\n\n";
    cout << "\t\t          TIC TAC TOE \t\t \n\n";
    cout << "\t\t Dear Player, please select a number \n";
    cout << "\n\n";
    cout << "\t\t\t    " << board[1] << "   " << board[2] << "   " << board[3] << " \n";
    cout << "\n";
    cout << "\t\t\t    " << board[4] << "   " << board[5] << "   " << board[6] << " \n";
    cout << "\n";
    cout << "\t\t\t    " << board[7] << "   " << board[8] << "   " << board[9] << " \n";
    cout << "\n\n";
}

int checkwin() {
    if (board[1] == board[2] && board[2] == board[3]) {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7]) {
        return 1;
    }
    if (board[7] == board[8] && board[8] == board[9]) {
        return 1;
    }
    if (board[3] == board[6] && board[6] == board[9]) {
        return 1;
    }
    if (board[1] == board[5] && board[5] == board[9]) {
        return 1;
    }
    if (board[3] == board[5] && board[5] == board[7]) {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8]) {
        return 1;
    }
    if (board[4] == board[5] && board[5] == board[6]) {
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= 9; i++) {
        if (board[i] == 'x' || board[i] == '0') {
            count++;
        }
    }

    if (count == 9) {
        return 0;
    }
    return -1;
}
