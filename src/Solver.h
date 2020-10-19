#ifndef INC_2048SOLVER_SOLVER_H
#define INC_2048SOLVER_SOLVER_H

#include "Board.h"

class Solver {
public:
    Solver(int minmax_depth)
        { minmax_depth_(minmax_depth) };
    move_t get_next_move(Board * board);
private:
    int minmax_depth_;
};


#endif //INC_2048SOLVER_SOLVER_H
