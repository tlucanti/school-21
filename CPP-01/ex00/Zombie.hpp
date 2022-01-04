#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

namespace tlucanti
{
	class Zombie
	{
	public:
		Zombie(const std::string &_name) noexcept;
		void announce() const noexcept;
	private:
		const std::string &name;
	};
}

#endif
