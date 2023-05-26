#include "Contact.hpp"

const std::string	Contact::getFirstName(void)
{
	return (firstName);
}

const std::string	Contact::getLastName(void)
{
	return (lastName);	
}

const std::string	Contact::getNickname(void)
{
	return (nickname);	
}

const std::string	Contact::getPhoneNumber(void)
{
	return (phoneNumber);
}

const std::string	Contact::getDarkestSecret(void)
{
	return (darkestSecret);	
}

int	isPrintable(std::string name)
{
	for(std::string::iterator it = name.begin(); it != name.end(); it++)
	{
		if (*it <= ' ' || 127 < *it)
			return (ERROR);
	}
	return (0);
}

int	isNumber(std::string name)
{
	for(std::string::iterator it = name.begin(); it != name.end(); it++)
	{
		if (*it < '0' || '9' < *it)
			return (ERROR);
	}
	return (0);
}

void Contact::setFirstName()
{
	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	if (std::cin.fail() || std::cin.eof())
		return ;
	if (isPrintable(firstName) == ERROR || firstName.size() == 0)
	{
		std::cout << "Invalid input" << std::endl;
		firstName.clear();
	}
}

void Contact::setLastName()
{
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	if (std::cin.fail() || std::cin.eof())
		return ;
	if (isPrintable(lastName) == ERROR || lastName.size() == 0)
	{
		std::cout << "Invalid input" << std::endl;
		lastName.clear();
	}
}

void Contact::setNickname()
{
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if (std::cin.fail() || std::cin.eof())
		return ;
	if (isPrintable(nickname) == ERROR || nickname.size() == 0)
	{
		std::cout << "Invalid input" << std::endl;
		nickname.clear();
	}
}

void Contact::setPhoneNumber()
{
	std::cout << "Phone Number: ";
	std::getline(std::cin, phoneNumber);
	if (std::cin.fail() || std::cin.eof())
		return ;
	if (isNumber(phoneNumber) == ERROR || phoneNumber.size() == 0)
	{
		std::cout << "Invalid input. Please enter without '-' sign" << std::endl;
		phoneNumber.clear();
	}
}

void Contact::setDarkestSecret()
{
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkestSecret);
	if (std::cin.fail() || std::cin.eof())
		return ;
	if (isPrintable(darkestSecret) == ERROR || darkestSecret.size() == 0)
	{
		std::cout << "Invalid input" << std::endl;
		darkestSecret.clear();
	}
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::add(void)
{
	while (1)
	{
		if (std::cin.fail() || std::cin.eof())
			return ;
		if ((std::cin.fail() == 0 || std::cin.eof() == 0) && firstName.size() == 0)
			setFirstName();
		if (firstName.size() == 0)
			continue ;
		if ((std::cin.fail() == 0 || std::cin.eof() == 0) && lastName.size() == 0)
			setLastName();
		if (lastName.size() == 0)
			continue ;
		if ((std::cin.fail() == 0 || std::cin.eof() == 0) && nickname.size() == 0)
			setNickname();
		if (nickname.size() == 0)
			continue ;
		if ((std::cin.fail() == 0 || std::cin.eof() == 0) && phoneNumber.size() == 0)
			setPhoneNumber();
		if (phoneNumber.size() == 0)
			continue ;
		if ((std::cin.fail() == 0 || std::cin.eof() == 0) && darkestSecret.size() == 0)
			setDarkestSecret();
		if (darkestSecret.size() == 0)
			continue ;
		break ;
	}
	if (std::cin.fail() == 0 || std::cin.eof() == 1)
		std::cout << "[PhoneBook v1.0.0] Successfully Added" << std::endl;
}

const std::string Contact::getSimpleForm(std::string& message, char c)
{
	if (c == 'f')
	{
		if (firstName.size() < 10)
			message = firstName;
		else
			message = firstName.substr(0, 9) + '.';
	}
	else if (c == 'l')
	{
		if (lastName.size() < 10)
			message = lastName;
		else
			message = lastName.substr(0, 9) + '.';
	}
	else if (c == 'n')
	{
		if (nickname.size() < 10)
			message = nickname;
		else
			message = nickname.substr(0, 9) + '.';
	}
	return (message);
}

void	Contact::clear(void)
{
	firstName.clear();
	lastName.clear();
	nickname.clear();
	phoneNumber.clear();
	darkestSecret.clear();
}