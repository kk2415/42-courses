#include <iostream>
#include "serialize.hpp"

int main(void)
{
	Data* data = new Data;
	data->num = 1;
	data->c = 'c';
	data->f = 1.1f;
	data->d = 12.3;

	uintptr_t serial = serialize(data);
	Data* deserial = deserialize(serial);

	std::cout << deserial->num << std::endl;
	std::cout << deserial->c << std::endl;
	std::cout << deserial->f << std::endl;
	std::cout << deserial->d << std::endl;
}
