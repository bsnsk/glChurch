cmake_minimum_required(VERSION 3.3)
project(glChurch)


set(SOURCE_FILES ${PROJECT_NAME}/main.cpp ThirdParty/GLM_NR/glm.cpp ThirdParty/GLM_NR/glm.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


IF (APPLE)
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/glChurch
        ${GLEW_INCLUDE_DIRS}
)
ENDIF(APPLE)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

IF(APPLE)
# Third Party
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)

# Frameworks: OpenGL, GLUT


    include_directories (/System/Library/Frameworks)
    find_library (GLUT_LIBRARY GLUT)
    find_library (OpenGL_LIBRARY OpenGL)
    mark_as_advanced (GLUT_LIBRARY
            OpenGL_LIBRARY)
    set(EXTRA_LIBS ${GLUT_LIBRARY} ${OpenGL_LIBRARY})


# GLEW (install first)

add_definitions(-DGLEW_STATIC)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I ${GLEW_INCLUDE_DIRS}")
    set(EXTRA_LIBS ${EXTRA_LIBS} ${GLEW_LIBRARIES})
endif()
ENDIF(APPLE)

IF(WIN32)
    set(EXTRA_LIBS
            "F:\\\\MinGW\\\\lib\\\\libglu32.a"
            "F:\\\\MinGW\\\\lib\\\\libopengl32.a"
            "F:\\\\MinGW\\\\lib\\\\libfreeglut.a"
            "F:\\\\MinGW\\\\lib\\\\libfreeglutdll.a"
            )

ENDIF(WIN32)

target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})