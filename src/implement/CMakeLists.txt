cmake_minimum_required(VERSION 3.18)

file(GLOB SOURCE_FILES "*.cpp")

foreach(FILE_NAME ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${FILE_NAME} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${FILE_NAME})
endforeach()