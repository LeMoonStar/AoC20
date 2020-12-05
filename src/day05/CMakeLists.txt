file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day05 STATIC ${SOURCE_FILES})

target_link_libraries(day05 common)

target_include_directories(day05 PUBLIC .)