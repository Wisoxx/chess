#include "Game.h"
#include "IO.h"

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);  // fixes displaying unicode characters

    IO io;
    Game game(&io);

    game.mainloop();

    return 0;
}
