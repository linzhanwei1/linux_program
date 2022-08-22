cmake_minimum_required(VERSION 3.2)
project(fileio VERSION 1.0.0 LANGUAGES C)

# set variable

# add the Common_fun library
add_library(tlpi_lib STATIC ../lib/error_functions.c ../daemons/become_daemon.c ../lib/get_num.c)

add_executable(us_xfr_cl us_xfr_cl.c)
add_executable(us_xfr_sv us_xfr_sv.c)
add_executable(ud_ucase_sv ud_ucase_sv.c)
add_executable(ud_ucase_cl ud_ucase_cl.c)
add_executable(us_abstract_bind us_abstract_bind.c)
add_executable(i6d_ucase_cl i6d_ucase_cl.c)
add_executable(i6d_ucase_sv i6d_ucase_sv.c)
add_executable(is_seqnum_sv is_seqnum_sv.c read_line.c)
add_executable(is_seqnum_cl is_seqnum_cl.c read_line.c)
add_executable(id_echo_sv id_echo_sv.c inet_sockets.c)
add_executable(id_echo_cl id_echo_cl.c inet_sockets.c)

target_link_libraries(us_xfr_cl PUBLIC tlpi_lib)
target_link_libraries(us_xfr_sv PUBLIC tlpi_lib)
target_link_libraries(ud_ucase_sv PUBLIC tlpi_lib)
target_link_libraries(ud_ucase_cl PUBLIC tlpi_lib)
target_link_libraries(us_abstract_bind PUBLIC tlpi_lib)
target_link_libraries(i6d_ucase_cl PUBLIC tlpi_lib)
target_link_libraries(i6d_ucase_sv PUBLIC tlpi_lib)
target_link_libraries(is_seqnum_sv PUBLIC tlpi_lib)
target_link_libraries(is_seqnum_cl PUBLIC tlpi_lib)
target_link_libraries(id_echo_sv PUBLIC tlpi_lib)
target_link_libraries(id_echo_cl PUBLIC tlpi_lib)

# include paths
include_directories(fileio 
                    "../lib"
                    "../daemons"
                    )