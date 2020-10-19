#include <map>
#include <vector>
#include <exception>

#include "Solver.h"
#include "Board.h"

static int get_minimal_evaluation(std::vector<Board> * possible_outcomes) {
    if (possible_outcomes->empty())
            // TODO: Create informative exception
            throw 1;
    int minimal_score = possible_outcomes->at(0).evaluate_score();
    for (Board outcome : *possible_outcomes) {
        if (outcome.evaluate_score() < minimal_score)
            minimal_score = outcome.evaluate_score();
    }
    return minimal_score;
}

move_t Solver::get_next_move(Board * board) {
    auto possible_outcomes_by_move = std::map<move_t, std::vector<Board> *>();
    auto min_score_by_move = std::map<move_t, int>();
    for (const move_t move : Moves::All) {
        possible_outcomes_by_move[move] = board->get_possible_outcomes(move);
        min_score_by_move[move] = get_minimal_evaluation(possible_outcomes_by_move[move]);
    }
    int max_min_score = min_score_by_move[Moves::UP];
    move_t optimal_move = Moves::UP;
    for (const move_t move : Moves::All) {
        if (min_score_by_move[move] > max_min_score) {
            optimal_move = move;
            max_min_score = min_score_by_move[move];
        }
    }
    delete &possible_outcomes_by_move;
    delete &min_score_by_move;
    return optimal_move;
}
