#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

typedef AMateria * METERIA_PTR;

class Character : public ICharacter
{
private:
	std::string name;
	METERIA_PTR * inventory;
	int	inventorySize;
	const int static MAX = 4;
	const int static MIN = 0;

public:
	Character();
	Character(std::string name);
	Character(const Character& character);
	~Character();

	virtual std::string const & getName() const;
	virtual int getInventorySize() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

	Character& operator=(const Character& ref);
};

#endif
