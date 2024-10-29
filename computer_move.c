#include "computer_move.h"
#include <limits.h>
#include <stdbool.h>
#include <math.h>

static int minimax(Board *board, int depth, bool is_maximizing, int alpha, int beta);
static int evaluate_board(const Board *board);
static bool is_move_valid(const Board *board, int row, int col);

Move bfs(Board *board) {
    Move best_move = { -1, -1 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (is_move_valid(board, i, j)) {
                best_move.row = i;
                best_move.col = j;
                return best_move;  // Returns the first empty cell (simulating a BFS approach)
            }
        }
    }
    return best_move;
}

Move dfs(Board *board) {
    Move best_move = { -1, -1 };
    for (int i = 2; i >= 0; i--) {
        for (int j = 2; j >= 0; j--) {
            if (is_move_valid(board, i, j)) {
                best_move.row = i;
                best_move.col = j;
                return best_move;  // Returns the last empty cell found (simulating a DFS approach)
            }
        }
    }
    return best_move;
}

Move ucs(Board *board) {
    Move best_move = { -1, -1 };
    int costs[3][3] = { {3, 2, 3}, {2, 1, 2}, {3, 2, 3} };
    int best_score = -INT_MAX;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (is_move_valid(board, i, j)) {
                board->cells[i][j] = COMPUTER;
                int score = evaluate_board(board) - costs[i][j];
                board->cells[i][j] = EMPTY;

                if (score > best_score) {
                    best_score = score;
                    best_move.row = i;
                    best_move.col = j;
                }
            }
        }
    }
    return best_move;
}

Move iterative_deepening(Board *board) {
    Move best_move = { -1, -1 };
    int depth_limit = 3;  // Maximum depth limit

    for (int depth = 1; depth <= depth_limit; depth++) {
        best_move = get_best_move(board);  // Uses Minimax as a proxy for depth-limited search
    }
    return best_move;
}

Move get_best_move(Board *board) {
    Move best_move = { -1, -1 };
    int best_score = -INT_MAX;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (is_move_valid(board, i, j)) {
                board->cells[i][j] = COMPUTER;
                int score = minimax(board, 0, false, -INT_MAX, INT_MAX);
                board->cells[i][j] = EMPTY;

                if (score > best_score) {
                    best_score = score;
                    best_move.row = i;
                    best_move.col = j;
                }
            }
        }
    }
    return best_move;
}

static int minimax(Board *board, int depth, bool is_maximizing, int alpha, int beta) {
    int score = evaluate_board(board);

    if (score == 10 || score == -10) return score;
    if (is_draw(board)) return 0;

    if (is_maximizing) {
        int best = -INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (is_move_valid(board, i, j)) {
                    board->cells[i][j] = COMPUTER;
                    best = fmax(best, minimax(board, depth + 1, false, alpha, beta));
                    board->cells[i][j] = EMPTY;
                    alpha = fmax(alpha, best);

                    if (beta <= alpha) break;
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (is_move_valid(board, i, j)) {
                    board->cells[i][j] = PLAYER;
                    best = fmin(best, minimax(board, depth + 1, true, alpha, beta));
                    board->cells[i][j] = EMPTY;
                    beta = fmin(beta, best);

                    if (beta <= alpha) break;
                }
            }
        }
        return best;
    }
}

static int evaluate_board(const Board *board) {
    int winner = check_winner(board);
    if (winner == COMPUTER) return 10;
    if (winner == PLAYER) return -10;
    return 0;
}

static bool is_move_valid(const Board *board, int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board->cells[row][col] == EMPTY;
}
