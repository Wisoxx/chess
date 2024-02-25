#ifndef CHESS_IO_H
#define CHESS_IO_H
#include <string>
#include <fcntl.h>     // fixes displaying unicode characters
#include <io.h>
#include <cstdio>
#include <iostream>
#include "pieces/Piece.h"

class IO {
    /* Class for communication with user */
public:
    // b stands for bright
    enum Color {reset, black, red, green, yellow, blue, magenta, cyan, white, b_black, b_red, b_green, b_yellow, b_blue, b_magenta, b_cyan, b_white};
    const std::wstring text_colors[17] = {L"\u001b[0m", L"\u001b[30m", L"\u001b[31m", L"\u001b[32m", L"\u001b[33m", L"\u001b[34m", L"\u001b[35m", L"\u001b[36m", L"\u001b[37m", L"\u001b[30;1m", L"\u001b[31;1m", L"\u001b[32;1m", L"\u001b[33;1m", L"\u001b[34;1m", L"\u001b[35;1m", L"\u001b[36;1m", L"\u001b[37;1m"};
    const std::wstring bg_colors[17] = {L"\u001b[0m", L"\u001b[40m", L"\u001b[41m", L"\u001b[42m", L"\u001b[43m", L"\u001b[44m", L"\u001b[45m", L"\u001b[46m", L"\u001b[47m", L"\u001b[40;1m", L"\u001b[41;1m", L"\u001b[42;1m", L"\u001b[43;1m", L"\u001b[44;1m", L"\u001b[45;1m", L"\u001b[46;1m", L"\u001b[47;1m"};

    static const Color white_tile = b_white;
    static const Color black_tile = black;
    static const Color white_piece = white;
    static const Color black_piece = b_magenta;
    static const Color frame_color = b_black;
    static const Color text_color = white;

    static std::string input();
    static void set_cursor_position(int x, int y);
    void print(const std::wstring& text, Color color=white, Color bg_color=black);
    void print_board(const std::wstring board[8][8], bool playing_as_white);
    void print_info(const std::wstring& message, bool is_white_turn);
    void print_results(const std::wstring board[8][8], bool playing_as_white, const std::wstring& message);
    static void erase();

    int get_promotion_choice(const std::wstring& message);
    void display(const std::wstring board[8][8], bool playing_as_white, bool is_white_turn, const std::wstring& message);
};


#endif //CHESS_IO_H
