cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add marco
add_definitions(-DUSE_SIGSETJMP)

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(ouch ouch.c)
add_executable(intquit intquit.c)
add_executable(t_kill t_kill.c)
add_executable(sig_sender sig_sender.c)
add_executable(sig_receiver sig_receiver.c signal_functions.c)
add_executable(nonreentrant nonreentrant.c)
add_executable(sigmask_longjmp sigmask_longjmp.c signal_functions.c)
add_executable(t_sigaltstack t_sigaltstack.c)

target_link_libraries(ouch PUBLIC tlpi_lib)
target_link_libraries(intquit PUBLIC tlpi_lib)
target_link_libraries(t_kill PUBLIC tlpi_lib)
target_link_libraries(sig_sender PUBLIC tlpi_lib)
target_link_libraries(sig_receiver PUBLIC tlpi_lib)
target_link_libraries(nonreentrant PUBLIC tlpi_lib crypt)
target_link_libraries(sigmask_longjmp PUBLIC tlpi_lib)
target_link_libraries(t_sigaltstack PUBLIC tlpi_lib)

# include paths
include_directories(fileio 
                    "../lib"
                    )