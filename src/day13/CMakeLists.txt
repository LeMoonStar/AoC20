file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day13 STATIC ${SOURCE_FILES})

target_link_libraries(day13 common)

target_include_directories(day13 PUBLIC .)