
#include <string>

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		~Zombie();

		void	setName(std::string name);
		void	announce() const;
};

Zombie	*zombieHorde(size_t N, std::string name);
