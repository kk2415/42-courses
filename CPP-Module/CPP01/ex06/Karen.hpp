# ifndef KAREN_H
#define KAREN_H

#include <iostream>
#include <string>

class Karen
{

public:
	void complain( std::string level );

private:	
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

};

enum COMMENTS
{
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR
};

typedef struct s_map 
{
	std::string key;
	int			value;
} t_map;

#endif