file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day01 STATIC ${SOURCE_FILES})

target_link_libraries(day01 common)

target_include_directories(day01 PUBLIC .)