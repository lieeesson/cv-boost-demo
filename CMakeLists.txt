cmake_minimum_required(VERSION 3.16)
project(cv_boost_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Allow CMake 3.16+ to find Boost without CMake config files
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

add_executable(app src/main.cpp)
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(app PRIVATE
    OpenCV::opencv_core
    OpenCV::opencv_imgcodecs
    Boost::boost
)

# ── testing ──────────────────────────────────────────────────
enable_testing()
add_test(NAME app_basic NAME_REGULAR_EXPRESSION "^app$")
add_executable(app_test src/main.cpp)
target_link_libraries(app_test PRIVATE
    OpenCV::opencv_core
    OpenCV::opencv_imgcodecs
    Boost::boost
)
add_test(NAME app_test app_test)

install(TARGETS app RUNTIME DESTINATION bin)