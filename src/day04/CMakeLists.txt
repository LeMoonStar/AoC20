file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day04 STATIC ${SOURCE_FILES})

target_link_libraries(day04 common)

target_include_directories(day04 PUBLIC .)