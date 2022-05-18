#include "Fixed.hpp"

Fixed::Fixed( void )
{
	fixPointNum = 0;
}

Fixed::Fixed( const int iValue )
{
	fixPointNum = iValue << this->fractionalBits;
}

Fixed::Fixed( const float fValue )
{
	this->fixPointNum = roundf(fValue * (1 << this->fractionalBits));
}

Fixed::Fixed( const fixPoint fValue )
{
	fixPointNum = fValue;
}

Fixed::Fixed( const Fixed& fixed )
{
	this->fixPointNum = fixed.getRawBits();
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

float Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a.toFloat());
	return (b.toFloat());
}

float Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a.toFloat());
	return (b.toFloat());
}

float Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b.toFloat());
	return (a.toFloat());
}

float Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b.toFloat());
	return (a.toFloat());
}

Fixed Fixed::operator = (const Fixed& fix)
{
	fixPointNum = fix.getRawBits();
	return (*this);
}

bool Fixed::operator > ( const Fixed& fix )
{
	return  (this->getRawBits() > fix.getRawBits());
}

bool Fixed::operator < ( const Fixed& fix )
{
	return  (this->getRawBits() < fix.getRawBits());
}

bool Fixed::operator <= ( const Fixed& fix )
{
	return  (this->getRawBits() <= fix.getRawBits());
}

bool Fixed::operator >= ( const Fixed& fix )
{
	return  (this->getRawBits() >= fix.getRawBits());
}

bool Fixed::operator == ( const Fixed& fix )
{
	return  (this->getRawBits() == fix.getRawBits());
}

bool Fixed::operator != ( const Fixed& fix )
{
	return  (this->getRawBits() != fix.getRawBits());
}

Fixed Fixed::operator + ( const Fixed& fix )
{
	return (Fixed((fixPoint)this->fixPointNum + fix.fixPointNum));
}

Fixed Fixed::operator - ( const Fixed& fix )
{
	return (Fixed((fixPoint)this->fixPointNum - fix.fixPointNum));
}

Fixed Fixed::operator * ( const Fixed& fix )
{
	return (Fixed((fixPoint)this->fixPointNum * fix.fixPointNum / (1 << this->fractionalBits)));
}

Fixed Fixed::operator / ( const Fixed& fix )
{
	return (Fixed((fixPoint)this->fixPointNum * (1 << this->fractionalBits) / fix.fixPointNum));
}

Fixed Fixed::operator ++ ( void )
{
	++this->fixPointNum;
	return (*this);
}

Fixed Fixed::operator -- ( void )
{
	--this->fixPointNum;
	return (*this);
}

Fixed Fixed::operator ++ ( int fixNum )
{
	Fixed fix( (fixPoint)this->fixPointNum );
	this->fixPointNum++;
	return (fix);
}

Fixed Fixed::operator -- ( int fixNum )
{
	Fixed fix( (fixPoint)this->fixPointNum );
	this->fixPointNum--;
	return (fix);
}

Fixed::~Fixed( void )
{

}

std::ostream& operator<<( std::ostream& out, const Fixed& fix )
{
	out << fix.toFloat();
	return (out);
}
