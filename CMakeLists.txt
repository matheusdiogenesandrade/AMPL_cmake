cmake_minimum_required(VERSION 3.16)
project(AMPLCMake)

##### SETs
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/support)
set (CMAKE_BUILD_TYPE Release) 
set (CMAKE_CXX_STANDARD 20)
set (BUILD_SHARED_LIBS On)

##### Additional packages 

find_package (AMPL)

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
    )

