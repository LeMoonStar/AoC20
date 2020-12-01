add_executable(AoC20 main.cpp)

add_subdirectory(common)
add_subdirectory(day01)
target_link_libraries(AoC20 common day01)