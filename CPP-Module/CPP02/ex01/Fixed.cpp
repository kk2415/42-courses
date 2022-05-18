#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	fixPointNum = 0;
}

Fixed::Fixed( const int iValue )
{
	std::cout << "Int constructor called" << std::endl;
	fixPointNum = iValue << this->fractionalBits;
}

Fixed::Fixed( const float fValue )
{
	std::cout << "Float constructor called" << std::endl;
	this->fixPointNum = roundf(fValue * (1 << this->fractionalBits));
}

Fixed::Fixed( const Fixed& fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(fixed);
}

int Fixed::getRawBits( void ) const
{
	return (fixPointNum);
}

void Fixed::setRawBits( int const raw )
{
	this->fixPointNum = raw;
}

float Fixed::toFloat( void ) const
{
	float	fValue;

	fValue = (float)this->fixPointNum / (1 << this->fractionalBits);
	return (fValue);
}

int Fixed::toInt( void ) const
{
	return (fixPointNum >> 8);
}

void Fixed::operator=(const Fixed& fix)
{
	std::cout << "Assignation operator called" << std::endl;
	fixPointNum = fix.getRawBits();
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<( std::ostream& out, const Fixed& fix ) {
	out << fix.toFloat();
	return (out);
}
