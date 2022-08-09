cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(t_stat t_stat.c file_perms.c)
add_executable(t_utime t_utime.c)
add_executable(t_chown t_chown.c ../users_groups/ugid_functions.c)
add_executable(t_umask t_umask.c file_perms.c)

target_link_libraries(t_stat PUBLIC tlpi_lib)
target_link_libraries(t_utime PUBLIC tlpi_lib)
target_link_libraries(t_chown PUBLIC tlpi_lib)
target_link_libraries(t_umask PUBLIC tlpi_lib)


# include paths
include_directories(fileio 
                    "../lib"
                    )