#include <cmath>

#include "Board.h"

static void shift_sequence(unsigned int * sequence) {
    return;
}

static void copy_board_data(board_data_t source, board_data_t destination) {
    for (int row = 0; row < BOARD_SIZE; row++)
        for (int col = 0; col < BOARD_SIZE; col++)
            destination[row][col] = source[row][col];
}

Board::Board(board_data_t board_data) {
    copy_board_data(board_data, this->board_data_);
}

int Board::evaluate_score() {
    int score = 0;
    for (int row = 0; row < BOARD_SIZE; row++)
        for (int col = 0; col < BOARD_SIZE; col++)
            score += SCORE_FILTER[row][col] * this->board_data_[row][col];
    return score;
}

std::vector<Board> * Board::get_possible_outcomes(move_t move) {
    return this->apply_move_(move).get_possible_game_placements_();
}


Board Board::apply_move_(move_t move) {
    board_data_t result_data;
    shift_direction_t  shift_direction = SHIFT_DIRECTION_BY_MOVE.at(move);

}

std::vector<Board> *Board::get_possible_game_placements_() {
    auto * possible_outcomes = new std::vector<Board *>();
    for (int row = 0; row < BOARD_SIZE; row++)
        for (int col = 0; col < BOARD_SIZE; col++)
            if (this->board_data_[row][col] == EMPTY_CELL) {
                for (int exp = 1; exp <= NUMBER_OF_POSSIBLE_PLACEMENTS; exp++) {
                    board_data_t possible_placement_board_data;
                    copy_board_data(this->board_data_, possible_placement_board_data);
                    possible_placement_board_data[row][col] = (int) pow(2, (double) exp);
                    auto * possible_placement_board = new Board(possible_placement_board_data);
                    possible_outcomes->push_back(possible_placement_board);
                }
            }
}

