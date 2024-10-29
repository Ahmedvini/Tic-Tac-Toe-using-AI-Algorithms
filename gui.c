#include <gtk/gtk.h>
#include "board.h"
#include "computer_move.h"
#include "gui.h"

static Board *game_board;
static int algorithm_choice = 1;

void reset_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game_board->cells[i][j] = EMPTY;
            gtk_button_set_label(GTK_BUTTON(game_board->buttons[i][j]), "");
        }
    }
    gtk_label_set_text(GTK_LABEL(game_board->status_label), "New game! Make your move.");
}

void on_play_again_clicked(GtkWidget *widget, gpointer data) {
    reset_board();
}

void on_button_clicked(GtkWidget *widget, gpointer data) {
    int *position = (int *)data;
    int row = position[0];
    int col = position[1];

    // Check if the game is already won
    if (check_winner(game_board) != EMPTY || is_draw(game_board)) {
        // Update the status to reflect that the game is over
        gtk_label_set_text(GTK_LABEL(game_board->status_label), "Game over! Press Play Again to start a new game.");
        return; // Don't allow moves if the game is already won or drawn
    }

    // Player move
    if (make_move(game_board, row, col, PLAYER)) {
        gtk_button_set_label(GTK_BUTTON(widget), "X");

        // Check if the player has won
        if (check_winner(game_board) == PLAYER) {
            gtk_label_set_text(GTK_LABEL(game_board->status_label), "You win!");
        } else if (is_draw(game_board)) {
            gtk_label_set_text(GTK_LABEL(game_board->status_label), "It's a draw!");
        } else {
            // Computer's turn if the game is not over
            Move comp_move;
            if (algorithm_choice == 5) {
                comp_move = get_best_move(game_board);
            } else {
                switch (algorithm_choice) {
                    case 1: comp_move = bfs(game_board); break;
                    case 2: comp_move = dfs(game_board); break;
                    case 3: comp_move = ucs(game_board); break;
                    case 4: comp_move = iterative_deepening(game_board); break;
                }
            }

            // Apply computer's move
            game_board->cells[comp_move.row][comp_move.col] = COMPUTER;
            gtk_button_set_label(GTK_BUTTON(game_board->buttons[comp_move.row][comp_move.col]), "O");

            // Check if the computer has won
            if (check_winner(game_board) == COMPUTER) {
                gtk_label_set_text(GTK_LABEL(game_board->status_label), "Computer wins!");
            } else if (is_draw(game_board)) {
                gtk_label_set_text(GTK_LABEL(game_board->status_label), "It's a draw!");
            }
        }
    }
}


void create_gui(Board *board) {
    game_board = board;

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *grid = gtk_grid_new();
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            GtkWidget *button = gtk_button_new_with_label("");
            g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), board->positions[i][j]);
            gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1);
            board->buttons[i][j] = button;
        }
    }

    board->status_label = gtk_label_new("Select an algorithm and make your move.");
    gtk_box_pack_start(GTK_BOX(vbox), board->status_label, FALSE, FALSE, 5);

    GtkWidget *combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), NULL, "BFS");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), NULL, "DFS");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), NULL, "UCS");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), NULL, "Iterative Deepening");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), NULL, "Unbeatable");
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0);
    gtk_box_pack_start(GTK_BOX(vbox), combo, FALSE, FALSE, 5);
    g_signal_connect(combo, "changed", G_CALLBACK(on_combo_changed), &algorithm_choice);

    GtkWidget *play_again_button = gtk_button_new_with_label("Play Again");
    gtk_box_pack_start(GTK_BOX(vbox), play_again_button, FALSE, FALSE, 5);
    g_signal_connect(play_again_button, "clicked", G_CALLBACK(on_play_again_clicked), NULL);

    gtk_widget_show_all(window);
}

void on_combo_changed(GtkComboBox *widget, gpointer data) {
    int *algorithm = (int *)data;
    *algorithm = gtk_combo_box_get_active(widget) + 1;
}
