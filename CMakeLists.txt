cmake_minimum_required(VERSION 3.16)
project(pixelshop LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(
	pixelshop 
	src/main.cpp 
	src/ui/sidebar.cpp
	src/ui/components/panel_bordered.cpp

	app.rc)
target_link_libraries(pixelshop ${wxWidgets_LIBRARIES})
target_include_directories(pixelshop PRIVATE
	${wxWidgets_INCLUDE_DIRS}
	${wxWidgets_LIB_DIR}/${wxWidgets_CONFIGURATION}
)
