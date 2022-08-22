cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)
link_libraries(pthread)

add_executable(simple_thread simple_thread.c)



target_link_libraries(simple_thread PUBLIC tlpi_lib)



# include paths
include_directories(fileio 
                    "../lib"
                    )