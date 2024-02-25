#include "Knight.h"

std::vector<std::string> Knight::calculate_moves(){
    moves.clear();

    int i = Board::coords_to_indexes(position)[0];
    int j = Board::coords_to_indexes(position)[1];

    check_tile(i - 2, j - 1);
    check_tile(i - 2, j + 1);

    check_tile(i + 2, j - 1);
    check_tile(i + 2, j + 1);

    check_tile(i - 1, j + 2);
    check_tile(i + 1, j + 2);

    check_tile(i + 1, j - 2);
    check_tile(i - 1, j - 2);

    return moves;
}
