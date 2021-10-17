cmake_minimum_required(VERSION 3.20)
project(philo C)

set(CMAKE_C_STANDARD 99)

add_executable(philo
        ft_atoi.c
        main.c
        mutex.c
        pthread.c
        utils.c

        include/philo.h
)

target_link_libraries(philo
        pthread
)