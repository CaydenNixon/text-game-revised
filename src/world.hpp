#pragma once

#include <iostream>
#include <unordered_map>

#include "equipment.hpp"
#include "trait.hpp"

class World
{
public:
// void init_traits();
void init_equipment()
{
    world_equipment.init_equipment();
}

private:
static std::unordered_map<std::string, Trait> char_traits;
static std::unordered_map<std::string, Trait> item_traits;
Equipment world_equipment;

};