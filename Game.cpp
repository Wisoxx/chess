#include "Game.h"

void Game::process_input(const std::string& input) {
    if (input == "exit"){
        aborted_ = true;
        active = false;
    }
    else if (input == "swap"){
        message = L"";
        playing_as_white_ = !playing_as_white_;
    }
    else if(input.size() == 5 && Board::are_valid_coords(input.substr(0,2)) &&
            input[2] == '-' && Board::are_valid_coords(input.substr(3,2))){
        std::wstring side[] = {L"black", L"white"};

        // converting user strings to wstrings
        std::string old_pos = input.substr(0,2);
        std::string new_pos = input.substr(3,2);
        std::wstring w_old_pos(old_pos.size(), L' ');
        std::wstring w_new_pos(new_pos.size(), L' ');
        w_old_pos.resize(std::mbstowcs(&w_old_pos[0], old_pos.c_str(), old_pos.size()));
        w_new_pos.resize(std::mbstowcs(&w_new_pos[0], new_pos.c_str(), new_pos.size()));

        switch(process_move(input)){
            case 0:
                message = L"";
                break;
            case 1:
                message = L"There is no piece at " +  w_old_pos + L"!";
                break;
            case 2:
                message = L"Piece at " + w_old_pos + L" isn't " + side[is_white_turn_] + L"!";
                break;
            case 3:
                message = L"Piece can't move from " + w_old_pos + L" to " + w_new_pos + L"!";
                break;
            case 4:
                message = L"Black win!";
                active = false;
                break;
            case 5:
                message = L"White win!";
                active = false;
                break;
        }
    }
    else{
        message = L"Invalid command or move!";
    }

}

int Game::process_move(const std::string &move) {
    std::string old_pos = move.substr(0,2);
    std::string new_pos = move.substr(3,2);
    Piece* piece = at(old_pos);

    if(piece == nullptr)
        return 1;
    if(piece->is_white != is_white_turn_){
        return 2;
    }

    if(piece->is_valid_move(new_pos)){  // if new_pos is valid, it's empty or there's enemy
        std::wstring at_new_pos = board.at(new_pos);
        std::wstring at_old_pos = board.at(old_pos);

        if(board.is_taken(new_pos)){
            if(at_new_pos == board.king[1]){
                board.move_tile(old_pos, new_pos);
                return 4;
            }
            if(at_new_pos == board.king[0]){
                board.move_tile(old_pos, new_pos);
                return 5;
            }
            Side* side = piece->is_white ? &black : &white;
            side->remove_at(new_pos);
        }
        piece->set_position(new_pos);
        board.move_tile(old_pos, new_pos);

        if((new_pos[1] == '8' && at_old_pos == board.pawn[1]) ||  // end for white pawn
           (new_pos[1] == '1' && at_old_pos == board.pawn[0])){   // end for black pawn
            promote(new_pos, piece->is_white);
        }

        is_white_turn_ = !is_white_turn_;
        return 0;
    }
    else{
        return 3;
    }

}

Piece *Game::at(const std::string &coords) {  // goes over every list and returns pointer to a piece with needed coords
    Side* side = &white;
    start:
    King* king = &side->king;
    if(king->get_position() == coords){
        return king;
    }
    for(auto & queen : side->queens){
        if(queen.get_position() == coords){
            return &queen;
        }
    }
    for(auto & rook : side->rooks){
        if(rook.get_position() == coords){
            return &rook;
        }
    }
    for(auto & knight : side->knights){
        if(knight.get_position() == coords){
            return &knight;
        }
    }
    for(auto & bishop : side->bishops){
        if(bishop.get_position() == coords){
            return &bishop;
        }
    }
    for(auto & pawn : side->pawns){
        if(pawn.get_position() == coords){
            return &pawn;
        }
    }
    if(side == &white){
        side = &black;
        goto start;
    }
    return nullptr;
}

bool Game::is_active() const {
    return active;
}

bool Game::playing_as_white() const {
    return playing_as_white_;
}

std::wstring Game::get_message() const {
    return message;
}

void Game::promote(const std::string &coords, bool is_white) {
    int a;
    std::wstring symbol;
    Side* side = is_white ? &white : &black;
    side->remove_at(coords);

    start:
    io->display(board.get(), playing_as_white(), is_white_turn(), get_message());
    a = io->get_promotion_choice(message);
    message = L"";

    switch(a){
        case 0:
            symbol = board.queen[is_white];
            side->queens.push_back(Queen({is_white, coords, &board}));
            break;
        case 1:
            symbol = board.rook[is_white];
            side->rooks.push_back(Rook({is_white, coords, &board}));
            break;
        case 2:
            symbol = board.knight[is_white];
            side->knights.push_back(Knight({is_white, coords, &board}));
            break;
        case 3:
            symbol = board.bishop[is_white];
            side->bishops.push_back(Bishop({is_white, coords, &board}));
            break;
        default:  // wrong input
            message = L"Choose from the list!";
            goto start;
    }
    board.set(coords, symbol);
}

Game::Game(IO *io) {
    this->io = io;
}

bool Game::is_white_turn() const {
    return is_white_turn_;
}

bool Game::aborted() const {
    return aborted_;
}

void Game::mainloop() {
    std::string input;
    while(active){
        io->display(board.board, playing_as_white_, is_white_turn_, message);
        input = io->input();
        process_input(input);
    }

    if(!aborted_){
        io->print_results(board.board, playing_as_white_, message);
    }
}
