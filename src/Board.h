#ifndef INC_2048SOLVER_BOARD_H
#define INC_2048SOLVER_BOARD_H

#include <vector>
#include <map>

#define BOARD_SIZE 4
#define EMPTY_CELL 0
#define NUMBER_OF_POSSIBLE_PLACEMENTS 2

using board_data_t = unsigned int [BOARD_SIZE][BOARD_SIZE];
using shift_direction_t = struct shift_direction {
    bool is_forward;
    bool is_row;
};
namespace Moves
{
    enum moves { UP, DOWN, LEFT, RIGHT };
    static const moves All[] = { UP, DOWN, LEFT, RIGHT };
}
using move_t = Moves::moves;

static const std::map<move_t, shift_direction_t> SHIFT_DIRECTION_BY_MOVE = {
        { Moves::UP, {true, true} },
        { Moves::DOWN, {false, true} },
        { Moves::LEFT, {true, false} },
        { Moves::RIGHT, {false, false} }
};
static const int SCORE_FILTER [BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0, 0},
                                                                   {0, 0, 0, 0},
                                                                   {0, 0, 0, 0},{0, 0, 0, 0}};


class Board {
public:
    Board(board_data_t board_data);
    int evaluate_score();
    std::vector<Board> * get_possible_outcomes(move_t move);

private:
    board_data_t board_data_;
    Board apply_move_(move_t move);
    std::vector<Board> * get_possible_game_placements_();
};


#endif //INC_2048SOLVER_BOARD_H
