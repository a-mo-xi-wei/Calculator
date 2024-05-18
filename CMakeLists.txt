cmake_minimum_required(VERSION 3.10)

project(Calculator VERSION 1.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC on) 

set(CMAKE_AUTOUIC on)

set(CMAKE_AUTORCC on)

set(cmake_cxx_standard 17)

set(cmake_cxx_standard_required on)

find_package(Qt6 REQUIRED Widgets UiTools)

#file(GLOB SRC_CPP ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

#add_executable(${PROJECT_NAME} ${SRC_CPP} "Resource.qrc" "Calculator.ui")

set(PROJECT_SOURCE WIN32
	main.cpp
	Calculator.cpp
	Calculator.ui
	Resource.qrc
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::UiTools) 
