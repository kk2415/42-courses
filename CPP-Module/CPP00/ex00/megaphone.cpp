#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>

int main(int argc, char *argv[])
{
	int	idx;
	std::string arg;

	idx = 1;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[idx])
	{
		arg += argv[idx];
		idx++;
	}
	std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);
	std::cout << arg << std::endl;
}