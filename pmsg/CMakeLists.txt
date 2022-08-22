cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)
link_libraries(rt)

add_executable(pmsg_unlink pmsg_unlink.c)
add_executable(pmsg_create pmsg_create.c)
add_executable(pmsg_getattr pmsg_getattr.c)
add_executable(pmsg_send pmsg_send.c)
add_executable(pmsg_receive pmsg_receive.c)

target_link_libraries(pmsg_unlink PUBLIC tlpi_lib)
target_link_libraries(pmsg_create PUBLIC tlpi_lib)
target_link_libraries(pmsg_getattr PUBLIC tlpi_lib)
target_link_libraries(pmsg_send PUBLIC tlpi_lib)
target_link_libraries(pmsg_receive PUBLIC tlpi_lib)


# include paths
include_directories(fileio 
                    "../lib"
                    "../time"
                    )