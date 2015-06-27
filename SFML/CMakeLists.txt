project(%{ProjectName})
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(SFML 2 REQUIRED graphics window system)

set(HDRS

)

set(SRCS
    main.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})