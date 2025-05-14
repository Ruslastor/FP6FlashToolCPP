cmake_minimum_required(VERSION 3.16)
project(FP6FlashToolCPP)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(FILE_HANDLER_DIR ${SRC_DIR}/file_handler)


file(GLOB FILE_HANDLER_SOURCES
    ${FILE_HANDLER_DIR}/*.cpp
)

add_executable(FlashTool
    ${SRC_DIR}/main.cpp
    ${FILE_HANDLER_SOURCES}
)

target_include_directories(FlashTool PRIVATE
    ${FILE_HANDLER_DIR}
)