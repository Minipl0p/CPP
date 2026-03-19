
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

Zombie	*zombieHorde(int N, std::string name);
