cmake_minimum_required(VERSION 2.8.9)
project (lattice)

set (CMAKE_CXX_STANDARD 11)
include_directories(include)
list(APPEND LINK_LIBS gmp m ntl)
file(GLOB SOURCES "src/*.cpp")

add_executable(test_ntl tests/test_ntl.cpp)
target_link_libraries(test_ntl ${LINK_LIBS})

add_executable(test_lll tests/test_lll.cpp)
target_link_libraries(test_lll ${LINK_LIBS})

add_executable(test_cjloss tests/test_cjloss.cpp ${SOURCES})
target_link_libraries(test_cjloss ${LINK_LIBS})
add_executable(test_svp tests/test_svp.cpp ${SOURCES})
target_link_libraries(test_svp ${LINK_LIBS})