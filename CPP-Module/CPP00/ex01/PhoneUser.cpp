#include "./PhoneUser.hpp"

PhoneUser::PhoneUser(void)
{
	firstName = "firstName";
	lastName = "lastName";
	nickName = "nickName";
	phoneNumber = "phoneNumber";
	darkestSecret = "darkestSecret";
	fieldArray = new std::string[5];
	fieldArray[0] = "firstName";
	fieldArray[1] = "lastName";
	fieldArray[2] = "nickName";
	fieldArray[3] = "phoneNumber";
	fieldArray[4] = "darkestSecret";
	fieldCount = 5;
}
