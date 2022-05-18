#include "File.hpp"

File::File( std::string fileName )
{
	in.open(fileName);
	if (in.fail())
	{
		std::cerr << "can not find file" << std::endl;
		exit(1);
	}
	this->fileName = fileName;
}

std::string	File::replace( std::string s1, std::string s2 )
{
	std::string	newFile;
	std::string	newLine;
	std::string	bufferStr;
	int			findIdx;

	while (in.getline(tempBuffer, sizeof(tempBuffer)))
	{
		findIdx = 0;
		newLine = "";
		bufferStr = static_cast<std::string>(tempBuffer);
		findIdx = bufferStr.find(s1);
		if (findIdx == -1)
		{
			newFile.append(bufferStr);
			newFile.append("\n");
			continue ;
		}
		if (s1.length() == 1)
			newLine = changeAllchar(bufferStr, s1, s2);
		else
		{
			newLine = bufferStr;
			newLine.erase(findIdx, s1.length());
			newLine.insert(findIdx, s2);
		}
		newLine.append("\n");
		newFile.append(newLine);
	}
	newFile.erase(newFile.length() - 1, newFile.length());
	return (newFile);
}

std::string	File::changeAllchar( std::string bufStr, std::string s1, std::string s2 )
{
	int	idx;
	int	findIdx;
	std::string	newLine;

	findIdx = 0;
	newLine = bufStr;
	for(idx = 0; idx < newLine.length(); idx++)
	{
		findIdx = newLine.find(s1, findIdx);
		if (findIdx == -1)
			break ;
		newLine.erase(findIdx, 1);
		newLine.insert(findIdx, s2);
	}
	return (newLine);
}

void	File::write( std::string str )
{
	std::ofstream out;

	out.open(this->fileName, std::ios::out);
	out << str;
}

void	File::close( void )
{
	in.close();
}