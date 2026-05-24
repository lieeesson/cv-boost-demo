cmake_minimum_required(VERSION 3.16)
project(cv_boost_demo LANGUAGES CXX)

# 1. 把 C++ 标准改成 17，匹配 Conan 编译 OpenCV 时的标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 2. 把 Conan 自动推导出的生成器目录，加入 CMake 的全局搜索路径
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_BINARY_DIR}/generators")

# 3. 这时候再调用 find_package，CMake 就能顺藤摸瓜找到 OpenCVConfig.cmake
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

add_executable(app src/main.cpp)
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(app PRIVATE
    OpenCV::opencv_core
    OpenCV::opencv_imgcodecs
    Boost::boost
)

enable_testing()
add_test(NAME app_test COMMAND app)

install(TARGETS app RUNTIME DESTINATION bin)