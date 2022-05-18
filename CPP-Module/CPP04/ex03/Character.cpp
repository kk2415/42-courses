#include "Character.hpp"

Character::Character() : name("defalt"), inventorySize(-1)
{
	this->inventory = new METERIA_PTR[MAX];
}

Character::Character(std::string name) : name(name), inventorySize(-1)
{
	this->inventory = new METERIA_PTR[MAX];
}

Character::Character(const Character& character)
	: name(character.getName()), inventorySize(character.getInventorySize())
{
	for (int i = 0; i < character.inventorySize; i++)
	{
		AMateria* tmp = character.inventory[i]->clone();
		this->inventory[i] = tmp;
	}
}

Character::~Character()
{
	delete [] this->inventory;
}

std::string const & Character::getName() const
{
	return this->name;
}

int Character::getInventorySize() const
{
	return this->inventorySize;
}

void Character::equip(AMateria* m)
{
	if (this->inventorySize >= MAX)
	{
		std::cout << "The Inventory is full." << std::endl;
		return ;
	}
	inventorySize++;
	this->inventory[inventorySize] = m;
}

void Character::unequip(int idx)
{
	if (this->inventorySize < MIN)
	{
		std::cout << "The Inventory is empty." << std::endl;
		return ;
	}
	this->inventory[inventorySize] = NULL;
	inventorySize--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > this->inventorySize || idx < 0)
	{
		std::cout << idx << " is out of Boundary" << std::endl;
		return ;
	}
	this->inventory[idx]->use(target);
}

Character& Character::operator=(const Character& ref)
{
	while (this->inventorySize > -1)
	{
		delete this->inventory[this->inventorySize];
		this->inventorySize--;
	}

	this->name = ref.name;
	this->inventorySize = ref.inventorySize;
	for (int i = 0; i < ref.inventorySize; i++)
	{
		AMateria* tmp = ref.inventory[i]->clone();
		this->inventory[i] = tmp;
	}
	return *this;
}
