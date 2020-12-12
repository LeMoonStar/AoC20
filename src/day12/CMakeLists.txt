file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day12 STATIC ${SOURCE_FILES})

target_link_libraries(day12 common)

target_include_directories(day12 PUBLIC .)