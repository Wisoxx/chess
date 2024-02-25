#include "Pawn.h"

std::vector<std::string> Pawn::calculate_moves() {
    moves.clear();

    int x = Board::coords_to_indexes(position)[1];    // j
    int y = Board::coords_to_indexes(position)[0];    // i

    if(is_white){
        if(!board->is_taken(y - 1,x)){  // if ahead is empty
            moves.push_back(Board::indexes_to_coords(y - 1, x));

            if(y == 6){   // is on start position for white
                moves.push_back(Board::indexes_to_coords(y - 2, x));
            }
        }
        if(x > 0 && board->is_taken_by(false, y - 1, x - 1)){  // left diagonal
            moves.push_back(Board::indexes_to_coords(y - 1, x - 1));
        }
        if(x < 7 && board->is_taken_by(false, y - 1, x + 1)){  // right diagonal
            moves.push_back(Board::indexes_to_coords(y - 1, x + 1));
        }
    }
    else{
        if(!board->is_taken(y + 1,x)){  // if ahead is empty
            moves.push_back(Board::indexes_to_coords(y + 1, x));

            if(y == 1){   // is on start position for black
                moves.push_back(Board::indexes_to_coords(y + 2, x));
            }
        }
        if(x > 0 && board->is_taken_by(true, y + 1, x - 1)){
            moves.push_back(Board::indexes_to_coords(y + 1, x - 1));
        }
        if(x < 7 && board->is_taken_by(true, y + 1, x + 1)){
            moves.push_back(Board::indexes_to_coords(y + 1, x + 1));
        }
    }
    return moves;
}
