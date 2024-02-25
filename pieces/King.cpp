#include "King.h"

std::vector<std::string> King::calculate_moves(){
    moves.clear();
    int x = Board::coords_to_indexes(position)[1];    // j
    int y = Board::coords_to_indexes(position)[0];    // i

    for(int i = y - 1; i < y + 2; i++){
        if(i < 0 || i > 7) continue;         // asserts inside the borders
        for(int j = x - 1; j < x + 2; j++){
            if((j < 0 || j > 7) ||    // asserts inside the borders
               (y == i && x == j)  ||   // skipping current position
               (board->is_taken_by(is_white, i, j))) // skipping pieces of the same color
                continue;

            moves.push_back(Board::indexes_to_coords(i, j));
        }
    }
    return moves;
}
