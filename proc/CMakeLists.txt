cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(necho necho.c)
add_executable(display_env display_env.c)
add_executable(modify_env modify_env.c)


target_link_libraries(necho PUBLIC tlpi_lib)
target_link_libraries(display_env PUBLIC tlpi_lib)
target_link_libraries(modify_env PUBLIC tlpi_lib)


# include paths
include_directories(fileio 
                    "../lib"
                    )