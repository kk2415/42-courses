#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// Animal* animal = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	dog->makeSound();
	cat->makeSound();
}
