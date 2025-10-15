cmake_minimum_required(VERSION 4.0)
project(GoL)


set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)


set(SRCs src/main.cpp src/board.cpp src/game.cpp src/engine.cpp)
add_executable(main ${SRCs})
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(SFML REQUIRED COMPONENTS Graphics Window)
target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)



target_compile_options(main PUBLIC 
	-Wall
	-Wextra
	-Wconversion
	-Waddress
	-Wpedantic
	-O3
)


