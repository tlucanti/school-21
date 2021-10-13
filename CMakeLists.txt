cmake_minimum_required(VERSION 3.20)
project(philo C)

set(CMAKE_C_STANDARD 99)

add_executable(philo
        main.c
        ft_atoi.c
        include/philo.h
)

target_link_libraries(philo
        pthread
)