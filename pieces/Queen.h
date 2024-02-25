#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Piece.h"


class Queen : public Piece{
    /* Class for all queens */
public:
    using Piece::Piece;
    const std::string type = "queen";  // debugging-only purposes
    std::vector<std::string> calculate_moves() override;
    ~Queen()= default;
};


#endif //CHESS_QUEEN_H
