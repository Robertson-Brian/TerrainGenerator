cmake_minimum_required(VERSION 3.2)

project(QGUI1 C CXX)

SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(BUILD_SHARED_LIBRARIES OFF)
#SET(CMAKE_EXE_LINKER_FLAGS "-static")

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

if("${VTK_QT_VERSION}" STREQUAL "")
  message(FATAL_ERROR "VTK was not built with Qt")
endif()

set( Srcs
	main.cxx
	GUI1.cxx)

set( Hdrs
	GUI1.h)

set( MOC_Hdrs
	GUI1.h)

set( UIs GUI1.ui )

# Use the include path and library for Qt that is used by VTK.
include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)


# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set ("${CMAKE_PREFIX_PATH};/opt/Qt5.5.0/5.5/gcc_64/lib/cmake")


#find_package(Qt5 COMPONENTS Widgets)
qt5_wrap_ui(UI_Srcs ${UIs})

add_executable(qgui1 MACOSX_BUNDLE  ${Srcs} ${Hdrs} ${UI_Srcs} ${MOC_Hdrs})
qt5_use_modules(qgui1 Core Gui Widgets Svg)

target_link_libraries(qgui1 ${VTK_LIBRARIES})
