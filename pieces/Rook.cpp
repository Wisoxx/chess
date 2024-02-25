#include "Rook.h"

std::vector<std::string> Rook::calculate_moves(){
    moves.clear();

    check_direction(0, 1);  // right
    check_direction(0, -1);  // left
    check_direction(-1, 0);  // up
    check_direction(1, 0);  // down

    return moves;
}
