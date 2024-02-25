#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <string>
#include "Side.h"
#include "IO.h"

class Game {
    /*Class connecting board, teams and user input. Class ruling everything*/
public:
    explicit Game(IO* io);
    Board board;
    [[nodiscard]] bool is_active() const;
    [[nodiscard]] bool playing_as_white() const;
    [[nodiscard]] bool is_white_turn() const;
    [[nodiscard]] std::wstring get_message() const;
    [[nodiscard]] bool aborted() const;
    void mainloop();

private:
    bool active = true;
    bool playing_as_white_ = true;
    bool is_white_turn_ = true;
    bool aborted_ = false;
    std::wstring message;
    IO* io;

    Side white{true, &board};
    Side black{false, &board};

    void process_input(const std::string& input);
    int process_move(const std::string& move);
    void promote(const std::string& coords, bool is_white);
    Piece* at(const std::string& coords);
};


#endif //CHESS_GAME_H
