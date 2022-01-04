#include "Zombie.hpp"

int main()
{
	tlucanti::Zombie z("zomba");
	z.announce();

	tlucanti::Zombie *grave = tlucanti::newZombie("flowy");
	grave->announce();
}
