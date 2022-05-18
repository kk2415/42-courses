#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneUser.hpp"

class PhonBook
{
private:
	int			userCount;
	PhoneUser	userArray[20000];

public:
	void	add(void);
	void	search(void);
	void	printLable(void);
	void	printRecord(PhoneUser phoneUser, int num);
	void	printUserInfo(void);
	int		getUserIdx(std::string answer);
	void	exit(void);
	int		size(void);

	PhonBook(void);
};

#endif