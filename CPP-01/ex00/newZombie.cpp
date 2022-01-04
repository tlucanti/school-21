#include "Zombie.hpp"

namespace tlucanti
{
    __WUR
    Zombie *newZombie(const std::string &name) noexcept
    {
		return new Zombie(name);
    }
}
