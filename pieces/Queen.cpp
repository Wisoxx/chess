#include "Queen.h"

std::vector<std::string> Queen::calculate_moves(){
    moves.clear();

    check_direction(0, 1);  // right
    check_direction(0, -1);  // left
    check_direction(-1, 0);  // up
    check_direction(1, 0);  // down

    check_direction(-1, 1);  // up-right
    check_direction(-1, -1);  // up-left
    check_direction(1, 1);  // down-right
    check_direction(1, -1);  // down-left

    return moves;
}
