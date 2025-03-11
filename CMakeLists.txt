cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES CXX VERSION 1.0  )
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
    src/Board.cpp
    src/DataStructures.cpp
    src/Piece.cpp
    src/main.cpp

)
add_executable(MyProject ${SOURCES})

# Manually include the JsonCpp headers
include_directories(/usr/include/jsoncpp)

target_include_directories(MyProject PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Manually link the JsonCpp library (assuming it's installed in /usr/lib)
link_directories(/usr/local/lib/cmake/jsoncpp)

target_link_libraries(MyProject jsoncpp)
