#include "Zombie.hpp"

int main()
{
	tlucanti::Zombie z("zomba");
	z.announce();

	tlucanti::randomChump("another");

	tlucanti::Zombie *grave = tlucanti::newZombie("rottenman");
	grave->announce();
	delete grave;
}
