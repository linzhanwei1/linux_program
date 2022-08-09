cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(copy copy.c)
add_executable(seek_io seek_io.c)
add_executable(bad_exclusive_open bad_exclusive_open.c)
add_executable(t_readv t_readv.c)

target_link_libraries(copy PUBLIC tlpi_lib)
target_link_libraries(seek_io PUBLIC tlpi_lib)
target_link_libraries(bad_exclusive_open PUBLIC tlpi_lib)
target_link_libraries(t_readv PUBLIC tlpi_lib)

# include paths
include_directories(fileio 
                    "../lib"
                    )