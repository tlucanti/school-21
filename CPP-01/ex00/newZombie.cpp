#include "Zombie.cpp"

namespace tlucanti
{
    [[nodiscard]]
    void *newZombie(const std::string &name) noexcept
    {
		return new Zombie(name);;
    }
}
