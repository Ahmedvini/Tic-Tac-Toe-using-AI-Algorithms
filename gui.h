#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>
#include "board.h"

// Initializes the GUI and creates the game window.
void create_gui(Board *board);

// Callback for the algorithm selection combo box.
void on_combo_changed(GtkComboBox *widget, gpointer data);

// Callback for button clicks on the Tic Tac Toe grid.
void on_button_clicked(GtkWidget *widget, gpointer data);

#endif
