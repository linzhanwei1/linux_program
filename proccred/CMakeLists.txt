cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(idshow idshow.c ../users_groups/ugid_functions.c)


target_link_libraries(idshow PUBLIC tlpi_lib)


# include paths
include_directories(fileio 
                    "../lib"
                    "../users_groups"
                    )