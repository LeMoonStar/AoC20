file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day07 STATIC ${SOURCE_FILES})

target_link_libraries(day07 common)

target_include_directories(day07 PUBLIC .)