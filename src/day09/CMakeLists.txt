file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day09 STATIC ${SOURCE_FILES})

target_link_libraries(day09 common)

target_include_directories(day09 PUBLIC .)