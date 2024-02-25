#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "Piece.h"


class Rook : public Piece{
    /* Class for all rooks */
public:
    using Piece::Piece;
    const std::string type = "rook";  // debugging-only purposes
    std::vector<std::string> calculate_moves() override;
    ~Rook()= default;
};


#endif //CHESS_ROOK_H
