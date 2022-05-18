#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>

typedef struct s_Data
{
	int num;
	char c;
	float f;
	double d;
} Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
