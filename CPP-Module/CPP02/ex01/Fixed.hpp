#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
public:
	Fixed( void );
	Fixed( const int iValue );
	Fixed( const float fValue );
	Fixed( const Fixed& fixed );
	~Fixed( void );

	float toFloat( void ) const;
	int toInt( void ) const;

	void	operator=(const Fixed& fix);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					fixPointNum;
	static const int	fractionalBits = 8;
};

std::ostream& operator<<( std::ostream& out, const Fixed& fix );

#endif
