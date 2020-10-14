
file(GLOB_RECURSE TEST_SOURCES "*.cpp")
add_executable(unit_tests ${TEST_SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/vendor)

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.1.0)
#FetchContent_MakeAvailable(Catch2)

find_package(Catch2 REQUIRED)

target_link_libraries(unit_tests
        PUBLIC library
        Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(unit_tests)
