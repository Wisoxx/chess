#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "Piece.h"


class Bishop : public Piece{
    /* Class for all bishops */
public:
    using Piece::Piece;
    const std::string type = "bishop";  // debugging-only purposes
    std::vector<std::string> calculate_moves() override;
    ~Bishop()= default;
};


#endif //CHESS_BISHOP_H
