cmake_minimum_required(VERSION 3.9)
project(Timus)

include_directories(lib/googletest/googletest/include)
add_subdirectory(lib/googletest)

set(CMAKE_CXX_STANDARD 14)

add_executable(Timus-1005 "1 - Basics/1005.cpp")
add_executable(Timus-1296 "1 - Basics/1296.cpp")
add_executable(Timus-2025 "1 - Basics/2025.cpp")

add_executable(Timus-1207 "2 - Sorting/1207.cpp")
add_executable(Timus-1604 "2 - Sorting/1604.cpp")
add_executable(Timus-1726 "2 - Sorting/1726.cpp")

add_executable(Timus-1494 "3 - Structures/1494.cpp")
add_executable(Timus-1521 "3 - Structures/1521.cpp")
add_executable(Timus-1628 "3 - Structures/1628.cpp")

add_executable(Timus-1080 "4 - Graph/1080.cpp")
add_executable(Timus-1160 "4 - Graph/1160.cpp")
add_executable(Timus-1450 "4 - Graph/1450.cpp")

target_link_libraries(Timus-1005 gtest)
target_link_libraries(Timus-1296 gtest)
target_link_libraries(Timus-2025 gtest)

target_link_libraries(Timus-1207 gtest)
target_link_libraries(Timus-1604 gtest)
target_link_libraries(Timus-1726 gtest)

target_link_libraries(Timus-1494 gtest)
target_link_libraries(Timus-1521 gtest)
target_link_libraries(Timus-1628 gtest)

target_link_libraries(Timus-1080 gtest)
target_link_libraries(Timus-1160 gtest)
target_link_libraries(Timus-1450 gtest)