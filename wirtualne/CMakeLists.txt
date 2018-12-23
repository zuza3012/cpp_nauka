cmake_minimum_required(VERSION 3.0) 
PROJECT (praca)
find_package(OpenCV REQUIRED )

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++17")

set( NAME_SRC
    src/main.cpp 
    src/pracownik.cpp
    src/kierownik.cpp
    src/wizytowka.cpp  
    src/robotnik.cpp 
    
)

set( NAME_HEADERS       
     include/kierownik.h
     include/pracownik.h
     include/wizytowka.h
     include/robotnik.h
)

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( praca ${NAME_SRC} ${NAME_HEADERS} )

#target_link_libraries( sample_pcTest ${OpenCV_LIBS} )
#set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++17")
