#include "Bishop.h"

std::vector<std::string> Bishop::calculate_moves(){
    moves.clear();

    check_direction(-1, 1);  // up-right
    check_direction(-1, -1);  // up-left
    check_direction(1, 1);  // down-right
    check_direction(1, -1);  // down-left

    return moves;
}