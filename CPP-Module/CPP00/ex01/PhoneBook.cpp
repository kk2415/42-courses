#include "PhoneBook.hpp"
#include <sstream>

PhonBook::PhonBook(void)
{
	userCount = 0;
}

int PhonBook::size(void)
{
	return userCount;
}

void PhonBook::add(void)
{
	int			idx;
	std::string	temp;

	idx = 0;
	PhoneUser phoneUser;
	while (idx < phoneUser.fieldCount)
	{
		std::cout << "Input " << phoneUser.fieldArray[idx] << " :" << std::endl;;
		std::getline(std::cin, temp, '\n');
		if (phoneUser.fieldArray[idx] == "firstName")
			phoneUser.firstName = temp;
		else if (phoneUser.fieldArray[idx] == "lastName")
			phoneUser.lastName = temp;
		else if (phoneUser.fieldArray[idx] == "nickName")
			phoneUser.nickName = temp;
		else if (phoneUser.fieldArray[idx] == "phoneNumber")
			phoneUser.phoneNumber = temp;
		else if (phoneUser.fieldArray[idx] == "darkestSecret")
			phoneUser.darkestSecret = temp;
		idx++;
	}
	userArray[userCount] = phoneUser;
	userCount++;
}

void PhonBook::search(void)
{
	int			idx;
	std::string	line;

	idx = 0;
	line = "--------------------------------------------";
	printLable();
	if (userCount <= 0)
	{
		std::cout << "Threr is no User in the phonebook" << std::endl;
		std::cout << std::endl << std::endl;
		return ;
	}
	while (idx < userCount)
	{
		printRecord(userArray[idx], idx);
		idx++;
	}
	std::cout << line << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	printUserInfo();
}

void PhonBook::printLable(void)
{
	std::string	line;

	line = "--------------------------------------------";
	std::cout << std::endl;
	std::cout << line << std::endl;
	std::cout << "	     Phone Number Talbe" << std::endl;
	std::cout << line << std::endl;
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nick name" << "|" << std::endl;
	std::cout << line << std::endl;
}

void PhonBook::printRecord(PhoneUser phoneUser, int num)
{
	std::cout << std::setw(10) << num << "|";
	if (phoneUser.firstName.length() >= 10)
		std::cout << phoneUser.firstName.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << phoneUser.firstName << "|";
	if (phoneUser.lastName.length() >= 10)
		std::cout << phoneUser.lastName.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << phoneUser.lastName << "|";
	if (phoneUser.nickName.length() >= 10)
		std::cout << phoneUser.nickName.substr(0, 9) << "." << "|" << std::endl;
	else
		std::cout << std::setw(10) << phoneUser.nickName << "|" << std::endl;
}

void PhonBook::printUserInfo(void)
{
	int					userIdx;
	std::string			line;
	std::string			answer;
	PhoneUser			phoneUser;

	line = "--------------------------------------------";
	while (true)
	{
		std::cout << line << std::endl << "If you back Menu, Input \'q\' or \'quit\'" << std::endl;
		std::cout << line << std::endl;
		std::cout << "Enter the index of the user who you want>>  ";
		std::getline(std::cin, answer, '\n');
		std::cout << std::endl;
		if (answer == "q" || answer == "quit")
			return ;
		userIdx = getUserIdx(answer);
		if (userIdx == -1)
			continue ;
		phoneUser = userArray[userIdx];
		std::cout << line << std::endl;
		std::cout << std::setw(17) << std::setfill('-') << "First name : "
			<< phoneUser.firstName << std::endl;
		std::cout << std::setw(17) << std::setfill('-') << "Last name : "
			<< phoneUser.lastName << std::endl;
		std::cout << std::setw(17) << std::setfill('-') << "nickname : "
			<< phoneUser.nickName << std::endl;
		std::cout << std::setw(17) << std::setfill('-') << "phone number : "
			<< phoneUser.phoneNumber << std::endl;
		std::cout << std::setw(17) << std::setfill('-') << "darkest secret : "
			<< phoneUser.darkestSecret << std::endl;
	}
}

int	PhonBook::getUserIdx(std::string answer)
{
	int	userIdx;

	std::stringstream strToint(answer);
	strToint >> userIdx;
	if (strToint.fail())
	{
		std::cout << " << Pleae Input Number >> " << std::endl;
		std::cout << std::endl;
		return (-1);
	}
	if (userIdx >= userCount || userIdx < 0)
	{
		std::cout << " << Pleae Input correct Index >> " << std::endl;
		std::cout << std::endl;
		return (-1);
	}
	return (userIdx);
}

void PhonBook::exit(void)
{
	std::cout << "<< program will be terminated >>" << std::endl;
	std::exit(EXIT_SUCCESS);
}
