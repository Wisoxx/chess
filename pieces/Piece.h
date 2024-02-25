#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <string>
#include <vector>
#include <algorithm>
#include "../Board.h"


class Piece {
    /* Base class for all pieces */
public:
    Piece(bool is_white, const std::string& position, Board* board);

    const std::string type = "piece";  // debugging-only purposes
    const bool is_white;
    void set_position(const std::string& new_position);
    std::string get_position();
    static bool is_white_func(const std::wstring &piece);
    virtual std::vector<std::string> calculate_moves();
    bool is_valid_move(const std::string& move);

protected:
    std::string position = "undefined";
    std::vector<std::string> moves;
    Board* board;

    void check_direction(int difference_i, int difference_j);
    void check_tile(int i, int j);
};


#endif //CHESS_PIECE_H
