file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day02 STATIC ${SOURCE_FILES})

target_link_libraries(day02 common)

target_include_directories(day02 PUBLIC .)