# cv-boost-demo

OpenCV + Boost 示例项目，基于 CMake + Conan 管理依赖。

## 环境要求

- CMake ≥ 3.16
- C++17
- [Conan](https://docs.conan.io/) ≥ 2.x
- [Ninja](https://ninja-build.org/)（跨平台构建工具）
- C++ 编译器：MSVC（Windows）、GCC/Clang（Linux）

---

## Windows

### 1. 安装依赖

#### Visual Studio Build Tools
下载 [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio)，勾选「使用 C++ 的桌面开发」。

#### Python + Conan
```powershell
# 用 pip 安装 Conan
pip install conan

# 初始化 Conan 配置（自动检测 MSVC）
conan profile detect --force
```

#### Ninja
```powershell
# 下载 Ninja
winget install Ninja-build.Ninja

# 或者手动：把 ninja.exe 放到 PATH 任意目录
```

### 2. 编译

```powershell
# 进入项目根目录
cd cv-boost-demo

# 安装依赖 + 生成 CMake Preset
conan install . --build=missing -s build_type=Release -s os=Windows -s arch=x86_64 -o opencv/*:with_ffmpeg=False -c tools.cmake.cmaketoolchain:generator=Ninja --output-folder=build

# 配置 + 编译
cmake --preset conan-release
cmake --build --preset conan-release --parallel

# 运行测试
ctest --preset conan-release --output-on-failure
```

> 注意：Windows 下用 **PowerShell** 运行，不要用 CMD。

---

## Linux（Ubuntu/Debian）

### 1. 安装依赖

```bash
# 系统编译工具
sudo apt-get update
sudo apt-get install -y build-essential python3-pip ninja-build

# 安装 Conan
pip install conan

# 初始化 Conan 配置
conan profile detect --force
```

### 2. 编译

```bash
# 进入项目根目录
cd cv-boost-demo

# 安装依赖 + 生成 CMake Preset
conan install . --build=missing -s build_type=Release -s os=Linux -s arch=x86_64 -o opencv/*:with_ffmpeg=False -o opencv/*:with_gtk=False -c tools.cmake.cmaketoolchain:generator=Ninja --output-folder=build

# 配置 + 编译
cmake --preset conan-release
cmake --build --preset conan-release --parallel

# 运行测试
ctest --preset conan-release --output-on-failure
```

---

## 依赖版本

| 依赖 | 版本 |
|------|------|
| OpenCV | 4.5.5 |
| Boost | 1.87.0 |

## GitHub CI

项目使用 GitHub Actions自动化构建和测试，工作流配置见 [.github/workflows/cmake.yml](.github/workflows/cmake.yml)，支持：
- **Ubuntu**（GCC + Ninja）
- **Windows**（MSVC + Ninja）