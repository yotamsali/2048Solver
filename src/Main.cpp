#include "Board.h"
#include "Game.h"
#include "Solver.h"

int main() {
    Game game_2048 = Game();
    Solver solver = Solver();
    game_2048.raise_2048();
    while (!game_2048.is_game_over()) {
        Board * current_board = game_2048.get_board();
        move_t next_move = solver.get_next_move(current_board);
        game_2048.make_move(next_move);
    }
    return EXIT_SUCCESS;
}