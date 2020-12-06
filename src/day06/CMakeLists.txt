file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day06 STATIC ${SOURCE_FILES})

target_link_libraries(day06 common)

target_include_directories(day06 PUBLIC .)