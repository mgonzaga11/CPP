#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon *weapom;
        std::string Name;
    public:
        HumanB(std::string name, Weapon &weapon);
        void attack(void);
};


#endif