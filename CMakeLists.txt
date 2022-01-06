cmake_minimum_required(VERSION 3.20)
project(school_21)

# set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(CPP-00-00
	CPP-00/ex00/megaphone.cpp
)

add_executable(CPP-00-01
	CPP-00/ex01/src/pb.cpp
	CPP-00/ex01/inc/phbook.hpp
	CPP-00/ex01/inc/color.hpp
)

add_executable(CPP-00-02
	CPP-00/ex02/Account.cpp
	CPP-00/ex02/Account.hpp
	CPP-00/ex02/tests.cpp
)

add_executable(CPP-01-00
	CPP-01/ex00/main.cpp
	CPP-01/ex00/Makefile
	CPP-01/ex00/newZombie.cpp
	CPP-01/ex00/randomChump.cpp
	CPP-01/ex00/Zombie.cpp
	CPP-01/ex00/Zombie.hpp
)

add_executable(CPP-01-01
	CPP-01/ex01/main.cpp
	CPP-01/ex01/random.cpp
	CPP-01/ex01/Zombie.cpp
	CPP-01/ex01/zombieHorde.cpp
	CPP-01/ex01/Zombie.hpp
)

add_executable(CPP-01-02
	CPP-01/ex02/main.cpp
)

add_executable(CPP-01-03
	CPP-01/ex03/HumanA.cpp
	CPP-01/ex03/HumanB.cpp
	CPP-01/ex03/main.cpp
	CPP-01/ex03/Weapon.cpp
	CPP-01/ex03/HumanA.hpp
	CPP-01/ex03/HumanB.hpp
	CPP-01/ex03/Weapon.hpp
)
