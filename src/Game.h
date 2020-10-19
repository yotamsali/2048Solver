#ifndef INC_2048SOLVER_GAME_H
#define INC_2048SOLVER_GAME_H

#include "Board.h"

class Game {
public:
    void raise_2048();
    Board * get_board();
    void make_move(move_t move);
    int get_2048_score();
    void reset_game();
    bool is_game_over();
};


#endif //INC_2048SOLVER_GAME_H
