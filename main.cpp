#include <iostream>
#include <io.h>        // fixes displaying unicode characters
#include <fcntl.h>     // fixes displaying unicode characters

// b stands for bright
enum Color {reset, black, red, green, yellow, blue, magenta, cyan, white, b_black, b_red, b_green, b_yellow, b_blue, b_magenta, b_cyan, b_white};
std::wstring text_colors[] = {L"\u001b[0m", L"\u001b[30m", L"\u001b[31m", L"\u001b[32m", L"\u001b[33m", L"\u001b[34m", L"\u001b[35m", L"\u001b[36m", L"\u001b[37m", L"\u001b[30;1m", L"\u001b[31;1m", L"\u001b[32;1m", L"\u001b[33;1m", L"\u001b[34;1m", L"\u001b[35;1m", L"\u001b[36;1m", L"\u001b[37;1m"};
std::wstring bg_colors[] = {L"\u001b[0m", L"\u001b[40m", L"\u001b[41m", L"\u001b[42m", L"\u001b[43m", L"\u001b[44m", L"\u001b[45m", L"\u001b[46m", L"\u001b[47m", L"\u001b[40;1m", L"\u001b[41;1m", L"\u001b[42;1m", L"\u001b[43;1m", L"\u001b[44;1m", L"\u001b[45;1m", L"\u001b[46;1m", L"\u001b[47;1m"};

class IO{
public:
    static std::string get_move(){

    }

    static void print(const std::wstring& text, Color color, Color bg_color){
        std::wcout << bg_colors[bg_color] << text_colors[color] << text << text_colors[reset];
    }

    static void print_board(bool play_as_white = true){  // TODO take into consideration play_as_white
        for(int i = 8; i > 0; i--){
            for(int j = 0; j < 8; j++){
                Color tile_color = (i % 2 == 0 && j % 2 == 1) ? b_white : black;
            }
        }
    }

    static void print_options(bool play_as_white = true){  // TODO take into consideration play_as_white

    }

    static void print_all(bool play_as_white = true){  // TODO take into consideration play_as_white
        print_board(play_as_white);
        print_options(play_as_white);
    }

};

class Game{
    bool play_as_white = true;
    bool is_white_turn = true;
    std::wstring board[8][8] = {{L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
                                {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
                                {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
                                {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
                                {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
                                {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
                                {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
                                {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "}};
    //                             A     B     C     D     E     F     G     H
};

class Piece{
    bool is_white{};
    bool alive = true;
    std::string position;
    std::string type;
    std::string moves[0];

    std::string* get_possible_moves(){
        return moves;
    }
    bool is_valid_move(const std::string& move){
        get_possible_moves();
        // todo check if move is in moves
    }
};

class King : Piece{
    std::string moves[8];   // maximum 1 tile radius
    std::string* get_possible_moves(){
        // TODO
    }

};

class Queen : Piece{
    std::string moves[0];   // TODO
    std::string* get_possible_moves(){
        // TODO
    }
};

class Rook : Piece{
    std::string moves[14];   // 7 horizontally + 7 vertically
    std::string* get_possible_moves(){
        // TODO
    }
};

class Bishop : Piece{
    std::string moves[0];   // TODO
    std::string* get_possible_moves(){
        // TODO
    }
};

class Knight : Piece{
    std::string moves[0];   // TODO
    std::string* get_possible_moves(){
        // TODO
    }
};

class Pawn : Piece{
    std::string moves[4];
    std::string* get_possible_moves(){

    }
};

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);  // fixes displaying unicode characters

    Game game;

    std::string a;
    std::cin >> a;
    return 0;
}

/*
 * Todo:
 * @ add letters and numbers
 * @ check valid moves
 * @ show possible moves by entering an existing piece location
 * @ import game
 * @ export game
 * @ switch board
 * @ maybe moves list
 * @ show time
 */