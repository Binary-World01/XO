#include <stdio.h>

char board[3][3];

void initializeBoard() {
    int num = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + num++;
        }
    }
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
}

char checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) &&
            (board[i][0] == 'X' || board[i][0] == 'O')) {
            return board[i][0];
        }
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) &&
            (board[0][i] == 'X' || board[0][i] == 'O')) {
            return board[0][i];
        }
    }
    
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) &&
        (board[0][0] == 'X' || board[0][0] == 'O')) {
        return board[0][0];
    }
    
    if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) &&
        (board[0][2] == 'X' || board[0][2] == 'O')) {
        return board[0][2];
    }

    return '*';
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

void playGame() {
    int move, row, col, player = 1;
    char symbol, winner = '*';

    initializeBoard();

    while (winner == '*' && !isBoardFull()) {
        displayBoard();
        symbol = (player == 1) ? 'X' : 'O';

        do {
            printf("Player %d (%c), enter position (1-9): ", player, symbol);
            scanf("%d", &move);
            move--;
            row = move / 3;
            col = move % 3;
        } while (move < 0 || move > 8 || board[row][col] == 'X' || board[row][col] == 'O');

        board[row][col] = symbol;
        winner = checkWinner();
        player = (player == 1) ? 2 : 1;
    }

    displayBoard();

    if (winner != '*') {
        printf("Player %c wins!\n", winner);
    } else {
        printf("It's a draw!\n");
    }
}

int main() {
    printf("Welcome to Tic-Tac-Toe!\n");
    playGame();
    return 0;
}
