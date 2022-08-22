cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)
link_libraries(pthread)

add_executable(simple_thread simple_thread.c)
add_executable(detached_attrib detached_attrib.c)
add_executable(thread_incr thread_incr.c)
add_executable(thread_incr_mutex thread_incr_mutex.c)
add_executable(thread_multijoin thread_multijoin.c)


target_link_libraries(simple_thread PUBLIC tlpi_lib)
target_link_libraries(detached_attrib PUBLIC tlpi_lib)
target_link_libraries(thread_incr PUBLIC tlpi_lib)
target_link_libraries(thread_incr_mutex PUBLIC tlpi_lib)
target_link_libraries(thread_multijoin PUBLIC tlpi_lib)



# include paths
include_directories(fileio 
                    "../lib"
                    )