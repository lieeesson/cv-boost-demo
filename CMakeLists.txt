cmake_minimum_required(VERSION 3.16)
project(cv_boost_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Ubuntu's OpenCV puts config in a non-standard location
set(OpenCV_DIR "/usr/lib/x86_64-linux-gnu/cmake/opencv4")

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

add_executable(app src/main.cpp)
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(app PRIVATE
    opencv_core
    opencv_imgcodecs
    Boost::boost
)

enable_testing()
add_test(NAME app_test COMMAND app)

install(TARGETS app RUNTIME DESTINATION bin)