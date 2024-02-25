#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "Piece.h"


class Knight : public Piece {
    /* Class for all knights */
public:
    using Piece::Piece;
    const std::string type = "knight";  // debugging-only purposes
    std::vector<std::string> calculate_moves() override;
    ~Knight()= default;
};


#endif //CHESS_KNIGHT_H
