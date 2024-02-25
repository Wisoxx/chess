#include "Piece.h"

Piece::Piece(bool is_white, const std::string& position, Board* board) : is_white(is_white){
    set_position(position);
    this->board = board;
}

std::vector<std::string> Piece::calculate_moves(){
    return moves;
}

bool Piece::is_valid_move(const std::string& move){
    calculate_moves();
    if(std::find(moves.begin(), moves.end(), move) != moves.end()){
        return true;
    }
    return false;
}

void Piece::set_position(const std::string& new_position) {
    position = (Board::are_valid_coords(new_position) && new_position != "undefined") ? new_position : position;
}

std::string Piece::get_position() {
    return position;
}

bool Piece::is_white_func(const std::wstring &piece) {
    std::wstring white[] = {L"♖", L"♘", L"♗", L"♕", L"♔", L"♙"};
    for(const std::wstring& p : white){
        if(piece == p) return true;
    }
    return false;
}

void Piece::check_direction(int difference_i, int difference_j) {  // checks every something tile and adds to moves if not taken by the same-colored piece
    int i = Board::coords_to_indexes(position)[0] + difference_i;
    int j = Board::coords_to_indexes(position)[1] + difference_j;

    while((i >= 0 && i <= 7) && (j >=0 && j <= 7)){
        if(!board->is_taken(i, j)){  // if empty
            moves.push_back(Board::indexes_to_coords(i, j));
        }
        else{
            if(board->is_taken_by(!is_white, i, j)){  // if taken by the opposite team
                moves.push_back(Board::indexes_to_coords(i, j));
            }
            break;
        }
        i = i + difference_i;
        j = j + difference_j;
    }
}

void Piece::check_tile(int i, int j) {
    if(!((i >= 0 && i <= 7) && (j >=0 && j <= 7))){
        return;
    }
    if(!board->is_taken(i, j)){  // if empty
        moves.push_back(Board::indexes_to_coords(i, j));
    }
    else{
        if(board->is_taken_by(!is_white, i, j)){  // if taken by the opposite team
            moves.push_back(Board::indexes_to_coords(i, j));
        }
    }
}
