
#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &input)
{
	*this = input;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (src._slots[i] != NULL) {
			this->_slots[i] = src._slots[i]->clone();
		}
		else
			this->_slots[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++) {
		if (this->_slots[i] != NULL)
			delete _slots[i];
	}
}

void MateriaSource::learnMateria(AMateria * m)
{
	for (int i = 0; i < 4; i++) {
		if (this->_slots[i] == NULL) {
			this->_slots[i] = m;
			m = NULL;
			break ;
		}
	}
	if (m != NULL) {
		delete m;
	}
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++) {
		if (this->_slots[i] != NULL && this->_slots[i]->getType() == type)
			return (this->_slots[i]->clone());
	}
	return 0;
}
