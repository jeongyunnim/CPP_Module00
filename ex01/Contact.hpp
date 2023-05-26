#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <iostream>
#include <string>
#define ERROR -1

class Contact
{
public:

	const std::string	getFirstName(void);
	const std::string	getLastName(void);
	const std::string	getNickname(void);
	const std::string	getPhoneNumber(void);
	const std::string	getDarkestSecret(void);
	void				setFirstName(void);
	void				setLastName(void);
	void				setNickname(void);
	void				setPhoneNumber(void);
	void				setDarkestSecret(void);

	Contact();
	~Contact();

	const std::string	getSimpleForm(std::string& message, char c);
	void				add(void);
	void				clear(void);

private:

	std::string firstName;
	std::string lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

};

#endif