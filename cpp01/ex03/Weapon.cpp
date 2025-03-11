#include "Weapon.hpp"

Weapon::Weapon (std::string type) : Type(type){}

const std::string& Weapon::getType() const{
	return this->Type;
}

void Weapon::setType(const std::string& type){
	this->Type = type;
}