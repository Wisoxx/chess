#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "Piece.h"


class Pawn : public Piece{
    /* Class for all pawns */
public:
    using Piece::Piece;
    const std::string type = "pawn";  // debugging-only purposes
    std::vector<std::string> calculate_moves() override;
    ~Pawn()= default;
};

#endif //CHESS_PAWN_H
