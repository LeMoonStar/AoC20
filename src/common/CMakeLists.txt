file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(common STATIC ${SOURCE_FILES})

target_include_directories(common PUBLIC .)