cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add marco
add_definitions(-DUSE_SIGSETJMP)

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(real_timer real_timer.c)
add_executable(timed_read timed_read.c)
add_executable(t_nanosleep t_nanosleep.c)


target_link_libraries(real_timer PUBLIC tlpi_lib)
target_link_libraries(timed_read PUBLIC tlpi_lib)
target_link_libraries(t_nanosleep PUBLIC tlpi_lib)


# include paths
include_directories(fileio 
                    "../lib"
                    )