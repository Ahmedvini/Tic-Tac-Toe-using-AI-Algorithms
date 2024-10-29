#ifndef COMPUTER_MOVE_H
#define COMPUTER_MOVE_H

#include "board.h"

Move bfs(Board *board);
Move dfs(Board *board);
Move ucs(Board *board);
Move iterative_deepening(Board *board);
Move get_best_move(Board *board);

#endif
