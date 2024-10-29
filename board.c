#include "board.h"
#include <stdio.h>

void init_board(Board *board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board->cells[i][j] = EMPTY;
            board->positions[i][j][0] = i;
            board->positions[i][j][1] = j;
        }
    }
}

int make_move(Board *board, int row, int col, int player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board->cells[row][col] != EMPTY) {
        return 0;
    }
    board->cells[row][col] = player;
    return 1;
}

int check_winner(const Board *board) {
    for (int i = 0; i < 3; i++) {
        if (board->cells[i][0] == board->cells[i][1] &&
            board->cells[i][1] == board->cells[i][2] &&
            board->cells[i][0] != EMPTY) {
            return board->cells[i][0];
            }
        if (board->cells[0][i] == board->cells[1][i] &&
            board->cells[1][i] == board->cells[2][i] &&
            board->cells[0][i] != EMPTY) {
            return board->cells[0][i];
            }
    }

    if (board->cells[0][0] == board->cells[1][1] &&
        board->cells[1][1] == board->cells[2][2] &&
        board->cells[0][0] != EMPTY) {
        return board->cells[0][0];
        }
    if (board->cells[0][2] == board->cells[1][1] &&
        board->cells[1][1] == board->cells[2][0] &&
        board->cells[0][2] != EMPTY) {
        return board->cells[0][2];
        }

    return EMPTY;
}

int is_draw(const Board *board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board->cells[i][j] == EMPTY) {
                return 0; // Not a draw if there's an empty cell
            }
        }
    }
    return 1; // Draw if all cells are filled
}
