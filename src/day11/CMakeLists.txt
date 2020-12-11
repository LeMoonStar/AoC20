file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day11 STATIC ${SOURCE_FILES})

target_link_libraries(day11 common)

target_include_directories(day11 PUBLIC .)