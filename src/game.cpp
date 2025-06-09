#include "game.hpp"

void Game::run_game()
{
    bool running = true;
    while (running)
    {
        std::cout << "NEW GAME [1]" << std::endl
                  << "LOAD GAME [2]" << std::endl
                  << "CLOSE GAME [3]" << std::endl;
        std::string menu1 = t_rsp();
        if (menu1 == "1")
        {
            std::cout << "NAME YOUR SAVE:" << std::endl;
            std::string save_name = t_rsp();
            save.create_save(save_name);
        }
        else if (menu1 == "2")
        {
            std::cout << "WHICH SAVE WILL YOU LOAD:" << std::endl;
            std::cout << save.save_list() << std::endl;
            std::string save_name = t_rsp();
            save.load_save(save_name);
        } // inclomplete, do not use
        else if (menu1 == "3")
        {
            exit(0);
        }
        else
        {
            std::cout << "TYPE 1, 2, OR 3" << std::endl;
        }
    }
}
std::string Game::t_rsp()
{
    std::string rsp;
    std::cin >> rsp;
    // modify this when encounters implemented (I have no idea what this means anymore, I forgot)
    if (rsp == "EXIT" || rsp == "exit")
    {
        exit(0);
    }
    else
    {
        return rsp;
    }
}