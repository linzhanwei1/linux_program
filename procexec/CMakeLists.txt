cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add marco
add_definitions(-DUSE_SIGSETJMP)

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../lib/get_num.c)

add_executable(t_fork t_fork.c)
add_executable(fork_file_sharing fork_file_sharing.c)
add_executable(footprint footprint.c)
add_executable(t_vfork t_vfork.c)
add_executable(fork_whos_on_first fork_whos_on_first.c)
add_executable(fork_sig_sync fork_sig_sync.c ../time/curr_time.c)
add_executable(exit_handlers exit_handlers.c)
add_executable(fork_stdio_buf fork_stdio_buf.c)
add_executable(multi_wait multi_wait.c ../time/curr_time.c)

target_link_libraries(t_fork PUBLIC tlpi_lib)
target_link_libraries(fork_file_sharing PUBLIC tlpi_lib)
target_link_libraries(footprint PUBLIC tlpi_lib)
target_link_libraries(t_vfork PUBLIC tlpi_lib)
target_link_libraries(fork_whos_on_first PUBLIC tlpi_lib)
target_link_libraries(fork_sig_sync PUBLIC tlpi_lib)
target_link_libraries(exit_handlers PUBLIC tlpi_lib)
target_link_libraries(fork_stdio_buf PUBLIC tlpi_lib)
target_link_libraries(multi_wait PUBLIC tlpi_lib)

# include paths
include_directories(fileio 
                    "../lib"
                    "../time"
                    )