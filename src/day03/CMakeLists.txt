file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day03 STATIC ${SOURCE_FILES})

target_link_libraries(day03 common)

target_include_directories(day03 PUBLIC .)