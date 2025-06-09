#pragma once

#include <iostream>
#include <unordered_map>
#include <cmath>

#include "equipment.hpp"
#include "trait.hpp"
#include "utils.hpp"

class Character
{
public:
    void init_char(std::string new_name)
    {
        name = new_name;
        roll_stats();

        stat_map["exp"] = 0;
        stat_map["exp req"] = 100;
        level = 1;
    }
    void set_stat(std::string type, float value) { stat_map[type] = value; }
    void roll_stats()
    {
        stat_map["init str"] = Utils::num_gen(Utils::get_seed(), 1, 20);
        stat_map["init dex"] = Utils::num_gen(Utils::get_seed(), 1, 20);
        stat_map["init con"] = Utils::num_gen(Utils::get_seed(), 1, 20);
        stat_map["init int"] = Utils::num_gen(Utils::get_seed(), 1, 20);
        stat_map["init wis"] = Utils::num_gen(Utils::get_seed(), 1, 20);
        stat_map["init hp max"] = 100;
    }
    void level_scaling()
    {
        stat_map["str"] = stat_map["init str"] + (round(stat_map["init str"] / 10) * level);
        stat_map["dex"] = stat_map["init dex"] + (round(stat_map["init dex"] / 10) * level);
        stat_map["con"] = stat_map["init con"] + (round(stat_map["init con"] / 10) * level);
        stat_map["int"] = stat_map["init int"] + (round(stat_map["init int"] / 10) * level);
        stat_map["wis"] = stat_map["init wis"] + (round(stat_map["init int"] / 10) * level);
        stat_map["hp max"] = stat_map["init hp max"] + (round(stat_map["init hp max"] / 10) * level);
    }
    void exp_req()
    {
        stat_map["exp req"] += (10 * (5 * (1.1f * level))) * pow(1.5f, (level / 10));
    }
    void level_up()
    {
        bool level_loop = true;
        while (level_loop)
        {
            if (stat_map["exp"] >= stat_map["exp req"])
            {
                level += 1;
                stat_map["exp"] -= stat_map["exp req"];
                level_scaling();
                exp_req();
            }
            else { return; }
        }
    }
    float get_stat(std::string type)
    {
        return stat_map[type];
    }

private:
    std::string name;
    std::unordered_map<std::string, float> stat_map;
    int level;
};