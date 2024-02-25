#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "Piece.h"


class King : public Piece{
    /* Class for all kings */
public:
    using Piece::Piece;
    const std::string type = "king";  // debugging-only purposes
    std::vector<std::string> calculate_moves() override;
    ~King()= default;
};


#endif //CHESS_KING_H
