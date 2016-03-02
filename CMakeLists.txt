cmake_minimum_required(VERSION 3.3)
project(openGL_test)

set(SOURCE_FILES
    openGL_test/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/openGL_test
        ${GLEW_INCLUDE_DIRS}
)


add_executable(openGL_test ${SOURCE_FILES})

# Frameworks: OpenGL, GLUT

IF (APPLE)
    include_directories (/System/Library/Frameworks)
    find_library (GLUT_LIBRARY GLUT)
    find_library (OpenGL_LIBRARY OpenGL)
    mark_as_advanced (GLUT_LIBRARY
            OpenGL_LIBRARY)
    set(EXTRA_LIBS ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
ENDIF (APPLE)

# GLEW (install first)

add_definitions(-DGLEW_STATIC)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${GLEW_INCLUDE_DIRS}")
    set(EXTRA_LIBS ${EXTRA_LIBS} ${GLEW_LIBRARIES})
endif()


target_link_libraries(openGL_test ${EXTRA_LIBS})
