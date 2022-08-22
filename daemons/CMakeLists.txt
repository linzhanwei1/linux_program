cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(test_become_daemon test_become_daemon.c become_daemon.c)
add_executable(daemon_SIGHUP daemon_SIGHUP.c become_daemon.c)


target_link_libraries(test_become_daemon PUBLIC tlpi_lib)
target_link_libraries(daemon_SIGHUP PUBLIC tlpi_lib)


# include paths
include_directories(fileio 
                    "../lib"
                    )