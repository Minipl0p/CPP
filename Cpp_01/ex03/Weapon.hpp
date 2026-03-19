#ifndef WEAPONA_HPP
# define WEAPONA_HPP

#include <string>

class	Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string weapon);
		~Weapon();
		const std::string&	getType() const;	
		void				setType(const std::string& newType);
};
#endif
