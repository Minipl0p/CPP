
#include "../includes/Serializer.hpp"


Serializer::Serializer(void) {}

Serializer::~Serializer(void) {}

Serializer::Serializer(const Serializer &cpy) { (void)cpy;}

Serializer	&Serializer::operator=(const Serializer &src) {(void)src; return *this;}

uintptr_t Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}
