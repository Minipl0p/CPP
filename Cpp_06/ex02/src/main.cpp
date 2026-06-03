
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <iostream>
#include <cstdlib>

Base *generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A();
	if (i == 1)
		return new B();
	if (i == 2)
		return new C();
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "type is : A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "type is : B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "type is : C" << std::endl;
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "type is : A" << std::endl;
		(void)a;
	}
	catch(std::exception &e) {}

	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "type is : B" << std::endl;
		(void)b;
	}
	catch(std::exception &e) {}

	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "type is : C" << std::endl;
		(void)c;
	}
	catch(std::exception &e) {}
}

int main(void)
{
	srand(time(NULL) ^ clock());
	Base *base_find = generate();

	std::cout << "Base *p" << std::endl;
	identify(base_find);
	std::cout << std::endl;
	std::cout << "Base &p" << std::endl;
	Base &base_ref = *base_find;
	identify(base_ref);
	std::cout << std::endl;
	delete base_find;
}
