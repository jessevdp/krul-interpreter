file(GLOB_RECURSE LIB_SOURCES "*.cpp")
list(REMOVE_ITEM LIB_SOURCES "main.cpp")

add_library(library STATIC ${LIB_SOURCES})

target_include_directories(library
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(executable main.cpp)

target_link_libraries(executable
        PUBLIC library)
