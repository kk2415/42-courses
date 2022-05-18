#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main( void )
{
	Weapon weapon1 = Weapon("crude spiked club");
	Weapon weapon2 = Weapon("crude spiked club");

	HumanA humanA("kyunkim", weapon1);
	HumanB humanB("jiskim");
	humanB.setWeapon(weapon2);

	humanA.attack();
	humanB.attack();

	weapon1.setType("sword");
	weapon2.setType("sword");

	humanA.attack();
	humanB.attack();
}
