cmake_minimum_required(VERSION 3.16)
project(AMPLCMake)

##### SETs
set (Project_PATH "${PROJECT_SOURCE_DIR}")
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/support)
set (CMAKE_BUILD_TYPE Release) 
set (CMAKE_CXX_STANDARD 20)

set (BUILD_SHARED_LIBS On)

##### Includes
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup()

##### Additional packages 

find_package (AMPL)

##### Include Dirs 

include_directories(
    SYSTEM
    includes
    "${PROJECT_BINARY_DIR}"
    "${AMPL_LIBRARY}"
    )

##### Compile options 

add_compile_options(-Wall
    -DIL_STD
    -Wfatal-errors
    -pedantic
    -fopenmp
    -DDEBUG
    -fdiagnostics-color=always
    -lz
    -std=c++20
    -lm 
    #
    -lpthread 
    -ldl
    -Wno-sign-compare
    )

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(
    main 
    ${SOURCES} 
    ${AMPL_LIBRARY}
    )

target_link_libraries(
    main 
    ${AMPL_LIBRARY}
    ampl
    pthread 
    m 
    dl
    )

