#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <cstring>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

typedef AMateria * MATERIA_PTR;

class MateriaSource : public IMateriaSource
{
private:
	MATERIA_PTR * materiaList;
	int curPoint;
	const int static MAX = 4;

public:
	MateriaSource();
	~MateriaSource();
	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
