#include "equipment.hpp"

void Equipment::init_accessories()
{
    accessory_list["test accessory"] = Accessory("test accessory", "ring");
}
void Equipment::init_armors()
{
    armor_list["test armor"] = Armor("test armor", 10, "heavy");
}
void Equipment::init_weapons()
{
    weapon_list["test weapon"] = Weapon("test weapon", 10, "1h sword");
}