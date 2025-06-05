#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>

struct Save
{
    void create_save(std::string save_name) // creates and names a new savefile
    {
        std::filesystem::create_directories("Saves"); // creates the "Saves" folder if it doesn't exist
        std::fstream save_file("Saves/" + save_name); // creates new save in the Saves directory
        save_file.close(); // closes the file after creation
        set_save(save_name);
    }
    void load_save(std::string save_name) // loads the savefile to memory for, readability, modification, lighter load
    {
        set_save(save_name); // ensures the correct save is active
        std::fstream save_file("Saves/" + active_save, std::ios::in); // opens the current chosen save in read mode
        std::string line; // stores the current line being read

        while (std::getline(save_file, line)) // loops through each line and adds it to the save string in memory
        {
            save_content += line + '\n';
        }
        save_file.close();
    }
    void save_data() // writes modified save data to the savefile from memory
    {
        std::fstream save_file("Saves/" + active_save, std::ios::out | std::ios::trunc); // opens the file to write, "trunc" clears the file first
        save_file << save_content; // write
        save_file.close();
    }
    void set_save(std::string save_tload)
    {
        active_save = save_tload;
    }

private:
    std::string active_save;
    std::string save_content;
};