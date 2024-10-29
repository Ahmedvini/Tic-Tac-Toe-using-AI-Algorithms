#include <gtk/gtk.h>
#include "board.h"
#include "computer_move.h"
#include "gui.h"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    Board board;
    init_board(&board);
    create_gui(&board);  // Initialize the GUI with the board

    gtk_main();  // GTK main loop
    return 0;
}
