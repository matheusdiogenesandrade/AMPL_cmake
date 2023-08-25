cmake_minimum_required(VERSION 3.16)
project(AMPLCMake)

##### SETs
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/support)
set (CMAKE_BUILD_TYPE Release) 
set (CMAKE_CXX_STANDARD 20)
set (BUILD_SHARED_LIBS On)

## Conan includes
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup()

##### Additional packages 

find_package (AMPL)
find_package (range-v3 REQUIRED)

##### Includes


include_directories(
    SYSTEM
    includes
    "${PROJECT_BINARY_DIR}"
    )

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(
    main 
    ${SOURCES} 
    )

target_link_libraries(
    main 
    ampl
    range-v3::range-v3
    )

