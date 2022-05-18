#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->fixPointNum = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixPointNum = fixed.getRawBits();
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixPointNum);
}

void Fixed::setRawBits( int const raw )
{
	this->fixPointNum = raw;
	std::cout << "setRawBits member function called" << std::endl;

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
