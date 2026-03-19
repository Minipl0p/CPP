#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _number;
		std::string _darkestSecret;

		void setFirstName(const std::string& value);
		void setLastName(const std::string& value);
		void setNickname(const std::string& value);
		void setNumber(const std::string& value);
		void setDarkestSecret(const std::string& value);
	public:
		Contact();
		void	addNew(const std::string& first, const std::string& last, const std::string& nick,
				const std::string& number, const std::string& secret);

		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		const std::string& getNickname() const;
		const std::string& getNumber() const;
		const std::string& getDarkestSecret() const;
};

#endif
