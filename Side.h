#ifndef CHESS_SIDE_H
#define CHESS_SIDE_H
#include <list>
#include "pieces/King.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Pawn.h"

class Side {
    /* Class storing all pieces */
    friend class Game;
    King king;
    std::list<Queen> queens;
    std::list<Rook> rooks;
    std::list<Knight> knights;
    std::list<Bishop> bishops;
    std::list<Pawn> pawns;

    Side(bool is_white, Board* board);
    bool remove_at(const std::string& coords);

    template <typename T>
    bool remove_at(std::list<T> * list, const std::string& coords);
};


#endif //CHESS_SIDE_H
