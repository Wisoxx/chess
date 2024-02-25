#include "IO.h"

std::string IO::input() {
    std::string input, lower_input;
    std::cin >> input;
    for(char c : input){
        lower_input += std::tolower((unsigned char) c);
    }
    return lower_input;
}

void IO::print(const std::wstring& text, Color color, Color bg_color){
    wprintf(bg_colors[bg_color].c_str());
    wprintf(text_colors[color].c_str());
    wprintf(text.c_str());
    wprintf(text_colors[reset].c_str());
}

void IO::print_board(const std::wstring board[8][8], bool playing_as_white){
    if(playing_as_white){
        print(L" ABCDEFGH \n", text_color, frame_color);   // column name
        for(int i = 0; i < 8; i++){
            print(std::to_wstring(8-i), text_color, frame_color);  // line number
            for(int j = 0; j < 8; j++){
                Color tile_color = (i % 2 == j % 2) ? white_tile: black_tile;
                Color piece_color = Piece::is_white_func(board[i][j]) ? white_piece : black_piece;
                print(board[i][j], piece_color, tile_color);
            }
            print(std::to_wstring(8-i), text_color, frame_color);  // line number
            std::wcout << L"\n";
        }
        print(L" ABCDEFGH \n", text_color, frame_color); // column name
    }
    else{
        print(L" HGFEDCBA \n", text_color, frame_color);   // column name
        for(int i = 7; i >= 0; i--){
            print(std::to_wstring(8-i), text_color, frame_color);  // line number
            for(int j = 7; j >= 0; j--){
                Color tile_color = (i % 2 != j % 2) ? white_tile: black_tile;
                Color piece_color = Piece::is_white_func(board[i][j]) ? white_piece : black_piece;
                print(board[i][j], piece_color, tile_color);
            }
            print(std::to_wstring(8-i), text_color, frame_color);  // line number
            std::wcout << L"\n";
        }
        print(L" HGFEDCBA \n", text_color, frame_color);   // column name
    }

}

void IO::erase() {
    std::wcout << "\033[H\033[J";
}

void IO::print_info(const std::wstring& message, bool is_white_turn) {
    set_cursor_position(21, 1);
    print(L"Chess.cpp", text_color);
    set_cursor_position(13, 2);
    print(L"Valid commands:", text_color);
    set_cursor_position(13, 3);
    print(L"* exit  * swap", text_color);

    set_cursor_position(13, 5);
    std::wstring turn[] = {L"black", L"white"};
    print(L"It's " + turn[is_white_turn] + L"'s turn", text_color);

    set_cursor_position(13, 7);
    print(message, text_color);

    set_cursor_position(13, 9);
    print(L"Type your command or move", text_color);
    set_cursor_position(13, 10);
    print(L"(e.g. e2-e4): ", text_color);
}

void IO::set_cursor_position(int x, int y) {
    char str[10];
    snprintf(str, 10, "\033[%d;%df", y, x);
    std::wcout << str;
}

void IO::print_results(const std::wstring board[8][8], bool playing_as_white, const std::wstring& message) {
    erase();
    print_board(board, playing_as_white);
    set_cursor_position(21, 1);
    print(L"Chess.cpp", text_color);

    set_cursor_position(21, 6);
    print(message, text_color);

    int a;
    std::cin >> a;
}

int IO::get_promotion_choice(const std::wstring& message) {
    set_cursor_position(13, 7);
    print(message, IO::text_color);

    set_cursor_position(13,9);
    print(L"Choose what to promote to", IO::text_color);
    set_cursor_position(13,10);
    print(L"Queen - 0, Rook - 1,");
    set_cursor_position(13,11);
    print(L"Knight - 2, Bishop - 3: ");

    int a;
    std::cin >> a;
    if(std::cin.fail()){
        std::cin.clear();  // reset flags
        std::cin.ignore(100, '\n');  // empty the buffer
        return -1;
    }

    return a;
}

void IO::display(const std::wstring board[8][8], bool playing_as_white, bool is_white_turn, const std::wstring& message) {
    erase();
    print_board(board, playing_as_white);
    print_info(message, is_white_turn);
}
