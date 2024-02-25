#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include <string>
#include <vector>

class Board {
    /* Class storing visual representation of all pieces' position. Doesn't have access to actual pieces and their logics */
private:
    friend class Game;

    void set(const std::string &coords, const std::wstring &value);
    void move_tile(const std::string& old_pos, const std::string& new_pos);

    std::wstring board[8][8] = {{L"♜", L"♞", L"♝", L"♛", L"♚", L"♝", L"♞", L"♜"},  // 8
                                {L"♟", L"♟", L"♟", L"♟", L"♟", L"♟", L"♟", L"♟"},  // 7
                                {L" ",  L" ",  L" ", L" ",  L" ", L" ",  L" ", L" "},   // 6
                                {L" ",  L" ",  L" ", L" ",  L" ", L" ",  L" ", L" "},   // 5
                                {L" ",  L" ",  L" ", L" ",  L" ", L" ",  L" ", L" "},   // 4
                                {L" ",  L" ",  L" ", L" ",  L" ", L" ",  L" ", L" "},   // 3
                                {L"♙", L"♙", L"♙", L"♙", L"♙", L"♙", L"♙", L"♙"},  // 2
                                {L"♖", L"♘", L"♗", L"♕", L"♔", L"♗", L"♘", L"♖"}}; // 1
    //                             A      B      C     D      E     F      G      H

public:
    auto const get() const  {return board;}
    static bool are_valid_coords(const std::string& coords);
    static std::vector<int> coords_to_indexes(const std::string& coords);
    static std::string indexes_to_coords(int i, int j);
    static bool is_white(const std::wstring &piece);
    bool is_white(int i, int j);

    bool is_taken_by(bool white, const std::string& coords);
    bool is_taken_by(bool white, int i, int j);
    bool is_taken(const std::string& coords);
    bool is_taken(int i, int j);

    std::wstring at(const std::string& coords);

    const std::wstring king[2] = {L"♚", L"♔"};
    const std::wstring queen[2] = {L"♛", L"♕"};
    const std::wstring rook[2] = {L"♜", L"♖"};
    const std::wstring knight[2] = {L"♞", L"♘"};
    const std::wstring bishop[2] = {L"♝", L"♗"};
    const std::wstring pawn[2] = {L"♟", L"♙"};
};


#endif //CHESS_BOARD_H
