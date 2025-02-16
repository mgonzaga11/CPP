#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon &weapom;
        std::string Name;
    public:
        HumanA(std::string name, Weapon &weapon);
        void attack(void);
};


#endif