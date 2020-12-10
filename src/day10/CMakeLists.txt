file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day10 STATIC ${SOURCE_FILES})

target_link_libraries(day10 common)

target_include_directories(day10 PUBLIC .)