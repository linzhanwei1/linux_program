cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(calendar_time calendar_time.c)
add_executable(strtime strtime.c)
add_executable(process_time process_time.c)


target_link_libraries(calendar_time PUBLIC tlpi_lib)
target_link_libraries(strtime PUBLIC tlpi_lib)
target_link_libraries(process_time PUBLIC tlpi_lib)


# include paths
include_directories(fileio 
                    "../lib"
                    )