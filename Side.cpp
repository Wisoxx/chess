#include "Side.h"

Side::Side(bool is_white, Board* board) : king(is_white, is_white ? "e1" : "e8", board){  // setting up default position
    queens.push_back(Queen({is_white, is_white ? "d1" : "d8", board}));
    rooks.push_back(Rook({is_white, is_white ? "a1" : "a8", board}));
    rooks.push_back(Rook({is_white, is_white ? "h1" : "h8", board}));
    knights.push_back(Knight({is_white, is_white ? "b1" : "b8", board}));
    knights.push_back(Knight({is_white, is_white ? "g1" : "g8", board}));
    bishops.push_back(Bishop({is_white, is_white ? "c1" : "c8", board}));
    bishops.push_back(Bishop({is_white, is_white ? "f1" : "f8", board}));

    std::string pawn_row = is_white ? "2" : "7";
    for(char c : "abcdefgh"){
        if(c != '\0')
            pawns.push_back(Pawn({is_white, std::string({c}) + pawn_row, board}));
    }
}

bool Side::remove_at(const std::string& coords) {  // Kings cannot be removed, because they are not in a list
    return (remove_at(&queens, coords) || remove_at(&rooks, coords) || remove_at(&knights, coords) ||
            remove_at(&bishops, coords) || remove_at(&pawns, coords));
}

template <typename T>
bool Side::remove_at(std::list<T> *list, const std::string &coords) {
    for(auto it = list->begin(); it != list->end(); ++it){
        if(it->get_position() == coords){
            list->erase(it);
            return true;  // success
        }
    }
    return false;  // fail
}

// allows separating declaration from implementation
template bool Side::remove_at<Queen>(std::list<Queen> *list, const std::string &coords);
template bool Side::remove_at<Rook>(std::list<Rook> *list, const std::string &coords);
template bool Side::remove_at<Knight>(std::list<Knight> *list, const std::string &coords);
template bool Side::remove_at<Bishop>(std::list<Bishop> *list, const std::string &coords);
template bool Side::remove_at<Pawn>(std::list<Pawn> *list, const std::string &coords);
