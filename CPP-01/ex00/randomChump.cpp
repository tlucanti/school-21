#include "Zombie.hpp"

namespace tlucanti
{
    void randomChump(const std::string &name) noexcept
    {
        Zombie(name).announce();
    }
}

