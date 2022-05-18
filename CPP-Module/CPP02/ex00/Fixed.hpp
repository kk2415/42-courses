#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
public:
	Fixed( void );
	Fixed( const Fixed& fixed );
	~Fixed( void );

	void	operator=(const Fixed& fix);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					fixPointNum;
	static const int	fractionalBits = 8;
};

#endif
