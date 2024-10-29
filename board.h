#ifndef BOARD_H
#define BOARD_H

#include <gtk/gtk.h>  // Include GTK header for GtkWidget

#define EMPTY 0
#define PLAYER 1
#define COMPUTER 2

typedef struct {
    int row, col;
} Move;

typedef struct {
    int cells[3][3];
    GtkWidget *buttons[3][3];
    GtkWidget *status_label;
    int positions[3][3][2];
} Board;

void init_board(Board *board);
int make_move(Board *board, int row, int col, int player);
int check_winner(const Board *board);
int is_draw(const Board *board);  // Declaration for is_draw

#endif
