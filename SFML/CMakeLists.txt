project(%{ProjectName})
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(SFML 2 REQUIRED graphics window system)

include_directories(${SFML_INCLUDE_DIR})

set(HDRS

)

set(SRCS
    main.cpp
)

add_executable(${PROJECT_NAME} ${HDRS} ${SRCS})

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})