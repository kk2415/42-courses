#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : curPoint(-1)
{
	this->materiaList = new MATERIA_PTR[MAX];
	memset(this->materiaList, 0, MAX);
}

MateriaSource::~MateriaSource()
{
	for (int i = this->curPoint; i > -1; i--)
	{
		delete this->materiaList[i];
	}
	delete [] this->materiaList;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->curPoint >= MAX)
	{
		std::cout << "can't learn no more" << std::endl;
		return ;
	}
	this->curPoint++;
	this->materiaList[this->curPoint] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (this->curPoint < 0)
	{
		std::cout << "I didn't learn anything." << std::endl;
		return NULL;
	}

	for(int i = curPoint; i > -1; i--)
	{
		if (this->materiaList[i]->getType() == type)
		{
			return this->materiaList[i]->clone();
		}
	}
	return NULL;
}
