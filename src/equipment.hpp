#pragma once

#include <iostream>
#include <unordered_map>

#include "trait.hpp"

class Equipment
{
public:
    void init_equipment()
    {
        init_weapons();
        init_armors();
        init_accessories();
    }
    struct Weapon
    {
        Weapon() = default;
        Weapon(std::string name, float init_attack, std::string new_class)
        {
            attack = init_attack;
            item_name = name;
            weapon_class = new_class;
        }
        void set_attack(float new_attack) { attack = new_attack; }
        void set_bonus(Trait bonus, std::string name)
        {
            weapon_bonuses[name] = bonus;
        }

    private:
        float attack;
        std::string item_name;
        std::string weapon_class;
        std::unordered_map<std::string, Trait> weapon_bonuses;
    };
    struct Armor
    {
        Armor() = default;
        Armor(std::string name, float init_defence, std::string new_class)
        {
            defence = init_defence;
            item_name = name;
            armor_class = new_class;
        }
        void set_defence(float new_defence) { defence = new_defence; }
        void set_bonus(Trait bonus, std::string name)
        {
            armor_bonuses[name] = bonus;
        }

    private:
        float defence; // flat damage reduction
        std::string item_name;
        std::string armor_class;
        std::unordered_map<std::string, Trait> armor_bonuses; // resistances and bonuses
    };
    struct Accessory
    {
        Accessory() = default;
        Accessory(std::string name, std::string new_type)
        {
            item_name = name;
        }
        void set_bonus(Trait bonus, std::string name)
        {
            accessory_bonuses[name] = bonus;
        }

    private:
        std::unordered_map<std::string, Trait> accessory_bonuses;
        std::string item_name;
        std::string accessory_type;
    };

    void init_weapons();
    void init_armors();
    void init_accessories();

private:
    std::unordered_map<std::string, Weapon> weapon_list;
    std::unordered_map<std::string, Armor> armor_list;
    std::unordered_map<std::string, Accessory> accessory_list;
};