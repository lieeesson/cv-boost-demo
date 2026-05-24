cmake_minimum_required(VERSION 3.16)
project(cv_boost_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ── vcpkg manifest mode ──────────────────────────────────────
include(${CMAKE_CURRENT_SOURCE_DIR}/vcpkg.json OPTIONAL)

# find_package via vcpkg (manifest mode auto-injects toolchain)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

add_executable(app src/main.cpp)
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(app PRIVATE
    OpenCV::opencv_core
    OpenCV::opencv_imgcodecs
    Boost::boost
)

# ── install ──────────────────────────────────────────────────
install(TARGETS app RUNTIME DESTINATION bin)