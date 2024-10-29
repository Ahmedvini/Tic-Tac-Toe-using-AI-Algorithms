cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

set(SOURCES main.c board.c computer_move.c gui.c)
set(HEADERS board.h computer_move.h gui.h)

add_executable(TicTacToe ${SOURCES} ${HEADERS})
target_link_libraries(TicTacToe ${GTK3_LIBRARIES} -lm)
