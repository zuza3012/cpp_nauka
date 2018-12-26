  cmake_minimum_required(VERSION 2.8)
  
  project(prog3)
  SET("OpenCV_DIR" "/usr/local/lib")
  #find_package( OpenCV REQUIRED )
	find_package(OpenCV 3.2.0 REQUIRED)
  MESSAGE(STATUS "Include dirs ${OpenCV_INCLUDE_DIRS}")
  MESSAGE(STATUS "LINK LIBRARIES ${OpenCV_LIBS}")

  add_executable(
	prog3
	program3.cpp)
  target_link_libraries(prog3 ${OpenCV_LIBS})
