file(GLOB SOURCE_FILES "*.cpp" "*.h")

add_library(day13 STATIC ${SOURCE_FILES})

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

target_link_libraries(day13 common Threads::Threads)

target_include_directories(day13 PUBLIC .)