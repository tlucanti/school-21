#include "Zombie.cpp"

namespace tlucanti
{
    inline
    void randomChump(const std::string name) noexcept
    {
        Zombie(name).announce();
    }
}

