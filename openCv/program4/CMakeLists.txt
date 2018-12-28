cmake_minimum_required(VERSION 3.0) 
PROJECT (program4)
SET("OpenCV_DIR" "/usr/local/lib")
find_package(OpenCV 3.2.0 REQUIRED)
	MESSAGE(STATUS "Include dirs ${OpenCV_INCLUDE_DIRS}")
	MESSAGE(STATUS "LINK LIBRARIES ${OpenCV_LIBS}")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++17")

set( NAME_SRC
    src/program4.cpp 
   )

set( NAME_HEADERS       
     include/
   )

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( program4 ${NAME_SRC} ${NAME_HEADERS} )
target_link_libraries(program4 ${OpenCV_LIBS})


