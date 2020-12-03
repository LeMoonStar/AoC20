add_executable(AoC20 main.cpp)

add_subdirectory(common)
add_subdirectory(day01)
add_subdirectory(day02)
add_subdirectory(day03)
target_link_libraries(AoC20 common day01 day02 day03)