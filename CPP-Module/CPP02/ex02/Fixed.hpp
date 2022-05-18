#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>
#include <string>

typedef long fixPoint;

class Fixed
{
public:
	Fixed( void );
	Fixed( const int iValue );
	Fixed( const float fValue );
	Fixed( const fixPoint fValue );
	Fixed( const Fixed& fixed );
	~Fixed( void );

	bool	operator < ( const Fixed& fix );
	bool	operator > ( const Fixed& fix );
	bool	operator <= ( const Fixed& fix );
	bool	operator >= ( const Fixed& fix );
	bool	operator == ( const Fixed& fix );
	bool	operator != ( const Fixed& fix );
	Fixed	operator = (const Fixed& fix);
	Fixed	operator + ( const Fixed& fix );
	Fixed	operator - ( const Fixed& fix );
	Fixed	operator * ( const Fixed& fix );
	Fixed	operator / ( const Fixed& fix );
	Fixed	operator ++ ( void );
	Fixed	operator -- ( void );
	Fixed	operator ++ ( int fixNum );
	Fixed	operator -- ( int fixNum );

	float 	toFloat( void ) const;
	int		toInt( void ) const;

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	static float max(Fixed& a, Fixed& b);
	static float max(const Fixed& a, const Fixed& b);
	static float min(Fixed& a, Fixed& b);
	static float min(const Fixed& a, const Fixed& b);

private:
	int					fixPointNum;
	static const int	fractionalBits = 8;
};

std::ostream& operator<<( std::ostream& out, const Fixed& fix );

#endif
