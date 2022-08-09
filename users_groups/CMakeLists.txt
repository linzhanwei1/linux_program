cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(t_getpwent t_getpwent.c)
add_executable(t_getpwnam_r t_getpwnam_r.c)
add_executable(check_password check_password.c)


target_link_libraries(t_getpwent PUBLIC tlpi_lib)
target_link_libraries(t_getpwnam_r PUBLIC tlpi_lib)
target_link_libraries(check_password PUBLIC tlpi_lib crypt)



# include paths
include_directories(fileio 
                    "../lib"
                    )