#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__
#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
public:

	int	getCount(void);

	PhoneBook();
	~PhoneBook();
	
	void		interactionMode(void);
	void		contactOverflow(void);
	void		search(void);

private:

	Contact		contact[8];
	const int	maxSize;
	int			count;

};

#endif