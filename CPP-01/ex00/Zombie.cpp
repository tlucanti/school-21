#include "Zombie.hpp"

tlucanti::Zombie::Zombie(const std::string &_name) noexcept
	: name(_name) {}

void
tlucanti::Zombie::announce() const noexcept
{
	std::cout << '<' << name << "> BraiiiiiiinnnzzzZ...\n";
}
