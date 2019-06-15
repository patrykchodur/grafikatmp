cmake_minimum_required(VERSION 3.8)

project(rotate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_FLAGS "-O2")

#add_definitions(-DDISPLAY_MINIMIZER_INFO)

find_package(wxWidgets COMPONENTS core base REQUIRED)
find_package(GSL REQUIRED)

set(SOURCE_FILES rotate.cpp minimalize.cpp GUI.cpp GUIMyFrame1.cpp)

include("${wxWidgets_USE_FILE}")
include_directories(${wxWidgets_INCLUDE_DIRS} ${GSL_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${GSL_LIBRARIES})
