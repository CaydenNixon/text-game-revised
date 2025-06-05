#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

class Trait
{
public:
    Trait(std::string name, std::string desc)
    {
        trait_name = name;
        trait_desc = desc;
    }
    void add_bonus(int index, std::string name, float amount)
    {
        trait_bonuses[index] = {name, amount};
    }

private:
    std::string trait_name;
    std::string trait_desc;
    std::unordered_map<int, std::pair<std::string, float>> trait_bonuses;
};