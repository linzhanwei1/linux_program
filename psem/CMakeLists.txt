cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)
link_libraries(pthread)

add_executable(psem_create psem_create.c)
add_executable(psem_unlink psem_unlink.c)
add_executable(psem_wait psem_wait.c)
add_executable(psem_post psem_post.c)
add_executable(psem_getvalue psem_getvalue.c)


target_link_libraries(psem_create PUBLIC tlpi_lib)
target_link_libraries(psem_unlink PUBLIC tlpi_lib)
target_link_libraries(psem_wait PUBLIC tlpi_lib)
target_link_libraries(psem_post PUBLIC tlpi_lib)
target_link_libraries(psem_getvalue PUBLIC tlpi_lib)


# include paths
include_directories(fileio 
                    "../lib"
                    "../time"
                    )