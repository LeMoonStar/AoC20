file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day08 STATIC ${SOURCE_FILES})

target_link_libraries(day08 common)

target_include_directories(day08 PUBLIC .)