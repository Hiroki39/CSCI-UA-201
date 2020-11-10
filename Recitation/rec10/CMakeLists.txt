cmake_minimum_required (VERSION 3.15)

project (rec10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-Wall -std=c11 -g)

# Find all c files and store in list mains
file(GLOB mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
foreach(mainfile IN LISTS mains)
    if(testRoll.c STREQUAL ${mainfile})
        add_executable(testRoll testRoll.c Rolldice.c Rolldice.h)
    else()
        # Get file name without directory
        get_filename_component(mainname ${mainfile} NAME_WE)
        add_executable(${mainname} ${mainfile})
    endif()
endforeach()
