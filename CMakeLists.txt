# CMakeList.txt : CMake project for RayLibTestProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(EMSCRIPTEN)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_GLFW=3 -s AUTO_JS_LIBRARIES -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -s USE_GLFW=3 -s AUTO_JS_LIBRARIES -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s LLD_REPORT_UNDEFINED")
    message("using emscripten!")
else()
    message("NOT using emscripten!")
endif()

# Output directory for libraries in Debug configuration
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${OUTPUT_DEBUG})
# Output directory for libraries in Release configuration
project("RayLibTestProject")

file(GLOB SOURCES src/core/app.cpp
        src/core/main.cpp
        src/core/util/timer.cpp
        src/core/window.cpp
        src/core/drawable.cpp
        src/core/scene.cpp
        src/core/gui/circle.cpp
        src/core/states/renderState.cpp
        src/core/states/mainMenuState.cpp
        src/core/gui/button.cpp
        src/core/states/linkedListState.cpp
        src/core/states/linkedListState.cpp
        src/linkedList/node.cpp
        src/linkedList/linkedList.cpp
        src/core/object.cpp
        )
# FIXME?
include_directories("${PROJECT_SOURCE_DIR}/src/linkedList")
include_directories("${PROJECT_SOURCE_DIR}/src/hashTables")
include_directories("${PROJECT_SOURCE_DIR}/src/algorithms")
include_directories("${PROJECT_SOURCE_DIR}/src/map")
include_directories("${PROJECT_SOURCE_DIR}/src/priorityQueue")
include_directories("${PROJECT_SOURCE_DIR}/src/queue")
include_directories("${PROJECT_SOURCE_DIR}/src/set")
include_directories("${PROJECT_SOURCE_DIR}/src/stack")
include_directories("${PROJECT_SOURCE_DIR}/src/trees")
include_directories("${PROJECT_SOURCE_DIR}/src/vector")
include_directories(("${PROJECT_SOURCE_DIR}/src/core"))
include_directories("${PROJECT_SOURCE_DIR}/src/core/gui")
include_directories("${PROJECT_SOURCE_DIR}/src/core/states")
include_directories("${PROJECT_SOURCE_DIR}/src/core/util")

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
add_subdirectory(vendor/raylib-3.5.0)

# Add source to this project's executable.
if(EMSCRIPTEN)
    add_executable (RayLibTestProject ${SOURCES} )
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set_target_properties(RayLibTestProject PROPERTIES COMPILE_FLAGS "-O2")
    set_target_properties(RayLibTestProject PROPERTIES LINK_FLAGS "--emrun --profiling")
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
else()
    add_executable (RayLibTestProject ${SOURCES} src/linkedList/LinkedListModel.cpp src/linkedList/LinkedListModel.hpp src/linkedList/LinkedListController.cpp src/linkedList/LinkedListController.hpp src/linkedList/LinkedListView.cpp src/linkedList/LinkedListView.hpp src/core/ModelsStorage.cpp src/core/ModelsStorage.hpp)
    #set_target_properties(RayLibTestProject PROPERTIES COMPILE_FLAGS )
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
endif()



