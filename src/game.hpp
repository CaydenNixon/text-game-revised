#pragma once

#include <iostream>

#include "character.hpp"
#include "save.hpp"
#include "world.hpp"

class Game
{
public:
    Game()
    {
        run_game();
    }
    void run_game();
    void new_game();
    std::string t_rsp();

private:
    Character player;
    Save save;
    World world;
};