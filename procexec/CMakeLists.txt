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
add_executable(child_status child_status.c print_wait_status.c)
add_executable(make_zombie make_zombie.c)
add_executable(multi_SIGCHLD multi_SIGCHLD.c ../time/curr_time.c print_wait_status.c)
add_executable(t_execve t_execve.c)
add_executable(envargs envargs.c)
add_executable(t_execlp t_execlp.c)
add_executable(t_execle t_execle.c)
add_executable(t_execl t_execl.c)
add_executable(t_system t_system.c print_wait_status.c)
#add_executable(simple_system simple_system.c)

target_link_libraries(t_fork PUBLIC tlpi_lib)
target_link_libraries(fork_file_sharing PUBLIC tlpi_lib)
target_link_libraries(footprint PUBLIC tlpi_lib)
target_link_libraries(t_vfork PUBLIC tlpi_lib)
target_link_libraries(fork_whos_on_first PUBLIC tlpi_lib)
target_link_libraries(fork_sig_sync PUBLIC tlpi_lib)
target_link_libraries(exit_handlers PUBLIC tlpi_lib)
target_link_libraries(fork_stdio_buf PUBLIC tlpi_lib)
target_link_libraries(multi_wait PUBLIC tlpi_lib)
target_link_libraries(child_status PUBLIC tlpi_lib)
target_link_libraries(make_zombie PUBLIC tlpi_lib)
target_link_libraries(multi_SIGCHLD PUBLIC tlpi_lib)
target_link_libraries(envargs PUBLIC tlpi_lib)
target_link_libraries(t_execve PUBLIC tlpi_lib)
target_link_libraries(t_execlp PUBLIC tlpi_lib)
target_link_libraries(t_execle PUBLIC tlpi_lib)
target_link_libraries(t_execl PUBLIC tlpi_lib)
target_link_libraries(t_system PUBLIC tlpi_lib)
#target_link_libraries(simple_system PUBLIC tlpi_lib)

# include paths
include_directories(fileio 
                    "../lib"
                    "../time"
                    )