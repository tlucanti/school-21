cmake_minimum_required(VERSION 3.20)
project(school_21)

set (CMAKE_CXX_COMPILER "/usr/bin/g++")
#set (CMAKE_VERBOSE_MAKEFILE true)

#set(CMAKE_CXX_STANDARD 23)
 set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -O0")
#set(CMAKE_CXX_FLAGS "-O0")

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

add_executable(CPP-01-04
	CPP-01/ex04/main.cpp
)

add_executable(CPP-01-05
	CPP-01/ex05/Karen.hpp
	CPP-01/ex05/Karen.cpp
	CPP-01/ex05/main.cpp
)

add_executable(CPP-01-06
	CPP-01/ex06/Karen.hpp
	CPP-01/ex06/Karen.cpp
	CPP-01/ex06/main.cpp
)

add_executable(CPP-02-00
	CPP-02/ex00/Fixed.hpp
	CPP-02/ex00/Fixed.cpp
	CPP-02/ex00/main.cpp
)

add_executable(CPP-02-03
	CPP-02/ex03/bsp.cpp
	CPP-02/ex03/Fixed.cpp
	CPP-02/ex03/Fixed.hpp
	CPP-02/ex03/main.cpp
	CPP-02/ex03/Makefile
	CPP-02/ex03/Point.cpp
	CPP-02/ex03/Point.hpp
)

add_executable(CPP-03-00
	CPP-03/ex00/ClapTrap.hpp
	CPP-03/ex00/ClapTrap.cpp
	CPP-03/ex00/main.cpp
)

add_executable(CPP-03-01
	CPP-03/ex01/ClapTrap.cpp
	CPP-03/ex01/ClapTrap.hpp
	CPP-03/ex01/main.cpp
	CPP-03/ex01/Makefile
	CPP-03/ex01/ScavTrap.cpp
	CPP-03/ex01/ScavTrap.hpp
)

add_executable(CPP-03-02
	CPP-03/ex02/ClapTrap.cpp
	CPP-03/ex02/ClapTrap.hpp
	CPP-03/ex02/FragTrap.cpp
	CPP-03/ex02/FragTrap.hpp
	CPP-03/ex02/main.cpp
	CPP-03/ex02/Makefile
	CPP-03/ex02/ScavTrap.cpp
	CPP-03/ex02/ScavTrap.hpp
)

add_executable(CPP-03-03
	CPP-03/ex03/ClapTrap.cpp
	CPP-03/ex03/DiamondTrap.cpp
	CPP-03/ex03/FragTrap.cpp
	CPP-03/ex03/main.cpp
	CPP-03/ex03/ScavTrap.cpp
	CPP-03/ex03/ClapTrap.hpp
	CPP-03/ex03/DiamondTrap.hpp
	CPP-03/ex03/FragTrap.hpp
	CPP-03/ex03/ScavTrap.hpp
)

add_executable(CPP-04-00
	CPP-04/ex00/Animal.cpp
	CPP-04/ex00/Animal.hpp
	CPP-04/ex00/Cat.cpp
	CPP-04/ex00/Cat.hpp
	CPP-04/ex00/Dog.cpp
	CPP-04/ex00/Dog.hpp
	CPP-04/ex00/main.cpp
	CPP-04/ex00/WrongAnimal.cpp
	CPP-04/ex00/WrongAnimal.hpp
	CPP-04/ex00/WrongCat.cpp
	CPP-04/ex00/WrongCat.hpp
)

add_executable(CPP-04-01
	CPP-04/ex01/Animal.cpp
	CPP-04/ex01/Animal.hpp
	CPP-04/ex01/Brain.cpp
	CPP-04/ex01/Brain.hpp
	CPP-04/ex01/Cat.cpp
	CPP-04/ex01/Cat.hpp
	CPP-04/ex01/Dog.cpp
	CPP-04/ex01/Dog.hpp
	CPP-04/ex01/main.cpp
)

add_executable(CPP-04-02
	CPP-04/ex02/Animal.cpp
	CPP-04/ex02/Animal.hpp
	CPP-04/ex02/Brain.cpp
	CPP-04/ex02/Brain.hpp
	CPP-04/ex02/Cat.cpp
	CPP-04/ex02/Cat.hpp
	CPP-04/ex02/Dog.cpp
	CPP-04/ex02/Dog.hpp
	CPP-04/ex02/main.cpp
)

add_executable(CPP-04-03
	CPP-04/ex03/AMateria.cpp
	CPP-04/ex03/AMateria.hpp
	CPP-04/ex03/Character.cpp
	CPP-04/ex03/Character.hpp
	CPP-04/ex03/Cure.cpp
	CPP-04/ex03/Cure.hpp
	CPP-04/ex03/Ice.cpp
	CPP-04/ex03/Ice.hpp
	CPP-04/ex03/ICharacter.hpp
	CPP-04/ex03/IMateriaSource.hpp
	CPP-04/ex03/main.cpp
	CPP-04/ex03/MateriaSource.cpp
	CPP-04/ex03/MateriaSource.hpp
)

add_executable(CPP-05-00
	CPP-05/ex00/Bureaucrat.cpp
	CPP-05/ex00/Bureaucrat.hpp
	CPP-05/ex00/Exception.cpp
	CPP-05/ex00/Exception.hpp
	CPP-05/ex00/main.cpp
	CPP-05/ex00/defs.h
)

add_executable(CPP-05-01
	CPP-05/ex01/Bureaucrat.cpp
	CPP-05/ex01/Bureaucrat.hpp
	CPP-05/ex01/defs.h
	CPP-05/ex01/Exception.cpp
	CPP-05/ex01/Exception.hpp
	CPP-05/ex01/Form.cpp
	CPP-05/ex01/Form.hpp
	CPP-05/ex01/main.cpp
)

add_executable(CPP-05-02
	CPP-05/ex02/Bureaucrat.cpp
	CPP-05/ex02/Bureaucrat.hpp
	CPP-05/ex02/defs.h
	CPP-05/ex02/Exception.cpp
	CPP-05/ex02/Exception.hpp
	CPP-05/ex02/Form.cpp
	CPP-05/ex02/Form.hpp
	CPP-05/ex02/main.cpp
	CPP-05/ex02/Makefile
	CPP-05/ex02/PresidentialPardonForm.cpp
	CPP-05/ex02/PresidentialPardonForm.hpp
	CPP-05/ex02/RobotomyRequestForm.cpp
	CPP-05/ex02/RobotomyRequestForm.hpp
	CPP-05/ex02/ShrubberyCreationForm.cpp
	CPP-05/ex02/ShrubberyCreationForm.hpp
)

add_executable(CPP-05-03
	CPP-05/ex03/Bureaucrat.cpp
	CPP-05/ex03/Bureaucrat.hpp
	CPP-05/ex03/defs.h
	CPP-05/ex03/Exception.cpp
	CPP-05/ex03/Exception.hpp
	CPP-05/ex03/Form.cpp
	CPP-05/ex03/Form.hpp
	CPP-05/ex03/home_shrubbery
	CPP-05/ex03/Intern.cpp
	CPP-05/ex03/Intern.hpp
	CPP-05/ex03/main.cpp
	CPP-05/ex03/PresidentialPardonForm.cpp
	CPP-05/ex03/PresidentialPardonForm.hpp
	CPP-05/ex03/RobotomyRequestForm.cpp
	CPP-05/ex03/RobotomyRequestForm.hpp
	CPP-05/ex03/ShrubberyCreationForm.cpp
	CPP-05/ex03/ShrubberyCreationForm.hpp
)

add_executable(CPP-06-00
	CPP-06/ex00/Converter.cpp
	CPP-06/ex00/Converter.hpp
	CPP-06/ex00/defs.h
	CPP-06/ex00/main.cpp
)

add_executable(CPP-06-01
	CPP-06/ex01/main.cpp
)
