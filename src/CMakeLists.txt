add_executable(AoC20 main.cpp)

add_subdirectory(common)
add_subdirectory(day01)
add_subdirectory(day02)
add_subdirectory(day03)
add_subdirectory(day04)
add_subdirectory(day05)
add_subdirectory(day06)
add_subdirectory(day07)
add_subdirectory(day08)
add_subdirectory(day09)
add_subdirectory(day10)
add_subdirectory(day11)
add_subdirectory(day12)
add_subdirectory(day13)
target_link_libraries(AoC20 common day01 day02 day03 day04 day05 day06 day07 day08 day09 day10 day11 day12 day13)