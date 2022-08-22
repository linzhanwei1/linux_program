cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(simple_pipe simple_pipe.c)
add_executable(pipe_sync pipe_sync.c ../time/curr_time.c)
add_executable(pipe_ls_wc pipe_ls_wc.c)


target_link_libraries(simple_pipe PUBLIC tlpi_lib)
target_link_libraries(pipe_sync PUBLIC tlpi_lib)
target_link_libraries(pipe_ls_wc PUBLIC tlpi_lib)



# include paths
include_directories(fileio 
                    "../lib"
                    "../time"
                    )