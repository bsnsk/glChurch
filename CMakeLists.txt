cmake_minimum_required(VERSION 3.3)
project(openGL_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    openGL_test/main.cpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/openGL_test
)

add_definitions(-DGLEW_STATIC)

add_executable(openGL_test ${SOURCE_FILES})

IF (APPLE)
    include_directories (/System/Library/Frameworks)
    find_library (GLUT_LIBRARY GLUT)
    find_library (OpenGL_LIBRARY OpenGL)
    mark_as_advanced (GLUT_LIBRARY
            OpenGL_LIBRARY)
    set(EXTRA_LIBS ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
ENDIF (APPLE)


target_link_libraries(openGL_test ${EXTRA_LIBS})
