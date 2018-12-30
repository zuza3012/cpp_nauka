cmake_minimum_required(VERSION 3.0) 
PROJECT (generator)
#SET("OpenCV_DIR" "/usr/local/lib")
#find_package(OpenCV 3.2.0 REQUIRED)
#	MESSAGE(STATUS "Include dirs ${OpenCV_INCLUDE_DIRS}")
#	MESSAGE(STATUS "LINK LIBRARIES ${OpenCV_LIBS}")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++17")

set( NAME_SRC
	src/main.cpp
    src/random.cpp
    src/uniform.cpp
    src/gauss.cpp
    src/poisson.cpp
   )

set( NAME_HEADERS       
    include/random.h
    include/uniform.h
    include/gauss.h
    include/poisson.h
   )

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( generator ${NAME_SRC} ${NAME_HEADERS} )
#target_link_libraries(generator ${OpenCV_LIBS})


