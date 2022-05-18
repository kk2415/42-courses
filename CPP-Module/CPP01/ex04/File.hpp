# ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <fstream>

class File
{

public:
	void		close( void );
	void		write( std::string str );
	std::string	replace( std::string s1, std::string s2 );
	std::string	changeAllchar( std::string bufStr, std::string s1, std::string s2 );

	File( std::string fileName );

private:
	std::ifstream	in;
	std::string		fileName;
	char			tempBuffer[1000];
};

#endif