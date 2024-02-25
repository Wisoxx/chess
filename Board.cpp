#include "Board.h"

bool Board::are_valid_coords(const std::string& coords) {
    if(coords.size() == 2 && (coords[0] >= 'a' && coords[0] <= 'h') && (coords[1] >= '1' && coords[1] <= '8')){
        return true;
    }
    return false;
}

std::vector<int> Board::coords_to_indexes(const std::string& coords){
    int i, j;
    if(are_valid_coords(coords)){
        i = 8 - (coords[1] - '0');
        j = coords[0] - 'a';
    }
    else {
        i = -1;
        j = -1;
    }

    return std::vector<int>({i, j});
}

bool Board::is_white(const std::wstring &piece) {
    std::wstring white[] = {L"♖", L"♘", L"♗", L"♕", L"♔", L"♙"};
    for(const std::wstring& p : white){
        if(piece == p) return true;
    }
    return false;
}

bool Board::is_taken(int i, int j) {
    return board[i][j] != L" ";
}

bool Board::is_taken(const std::string &coords) {
    std::vector<int> indexes = coords_to_indexes(coords);
    return board[indexes[0]][indexes[1]] != L" ";
}

bool Board::is_taken_by(bool white, const std::string& coords) {
    std::vector<int> indexes = coords_to_indexes(coords);
    return is_taken(indexes[0], indexes[1]) && (is_white(board[indexes[0]][indexes[1]]) == white);
}

bool Board::is_taken_by(bool white, int i, int j) {
    return is_taken(i, j) && (is_white(board[i][j]) == white);
}

std::string Board::indexes_to_coords(int i, int j) {
    return std::string(1, j + 'a') + std::to_string(8 - i);
}

bool Board::is_white(int i, int j) {
    return is_white(board[i][j]);
}

std::wstring Board::at(const std::string &coords) {
    std::vector<int> indexes = coords_to_indexes(coords);
    return board[indexes[0]][indexes[1]];
}

void Board::set(const std::string &coords, const std::wstring &value) {
    std::vector<int> indexes = coords_to_indexes(coords);
    board[indexes[0]][indexes[1]] = value;
}

void Board::move_tile(const std::string &old_pos, const std::string &new_pos) {
    set(new_pos, at(old_pos));
    set(old_pos, L" ");
}
