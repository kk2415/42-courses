#ifndef PHONEUSER_H
#define PHONEUSER_H

#include <iostream>
#include <string>

class PhoneUser
{
public:
	int			fieldCount;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	std::string	*fieldArray;
	PhoneUser(void);
};

#endif
