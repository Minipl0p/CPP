

#include "../includes/Character.hpp"
#include <iostream>

Character::Character(void) {}

Character::Character(std::string NAME) : _name(NAME)
{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
	this->_last_idx = 0;
	for (int i = 0; i < 4; i++)
		this->_floor[i] = NULL;
	this->_last_floor = 0;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++) {
		if (this->_slots[i] != NULL)
			delete this->_slots[i];
	}
	for (int i = 0; i < _last_floor; i++)
		if (this->_floor[i] != NULL)
			delete this->_floor[i];
}

Character::Character(const Character &cpy)
{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->_floor[i] = NULL;
	*this = cpy;
}

Character	&Character::operator=(const Character &src)
{
	if (this == &src)
		return *this;
	this->_name = src.getName();
	this->_last_idx = 0;
	for (int i = 0; i < 4; i++) {
		if (this->_slots[i] != NULL) {
			delete this->_slots[i];
			this->_slots[i] = NULL;
		}
	}
	for (int i = 0; i < this->_last_floor; i++) {
		if (this->_floor[i] != NULL) {
			delete this->_floor[i];
			this->_floor[i] = NULL;
		}
	}
	this->_last_floor = 0;
	for (int i = 0; i < 4; i++)
		this->_slots[i] = src._slots[i] ? src._slots[i]->clone() : NULL;
	return *this;
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int find = 0;
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++) {
		if (this->_slots[i] == NULL) {
			this->_slots[i] = m;
			find = 1;
			break;
		}
	}
	if (!find)
			std::cout << "\e[31mYou cannot equip another item, your inventory is full !\e[0m" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 4) {
		std::cout << "\e[31mYou cannot unequip an item with an index >= 4\e[0m" << std::endl; }
	else if (this->_slots[idx] == NULL) {
		std::cout << "\e[31mYou cannot unequip an item NULL\e[0m" << std::endl; }
	else if (_last_floor < 1000)
	{
		this->_floor[_last_floor++] = this->_slots[idx];
		this->_slots[idx] = NULL;
	}
	else if (_last_floor == 1000)
	{
		delete this->_slots[idx];
		_slots[idx] = NULL;
	}
	else
		this->_slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 4) {
		std::cout << "\e[31mYou cannot use an item with an index >= 4\e[0m" << std::endl; }
	else if (this->_slots[idx] == NULL) {
		std::cout << "\e[31mYou cannot use an item NULL\e[0m" << std::endl; }
	else
		this->_slots[idx]->use(target);
}
