cmake_minimum_required(VERSION 3.20)
project(school_21)

#set(CMAKE_CXX_STANDARD 23)
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
