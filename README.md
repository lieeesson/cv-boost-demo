# cv-boost-demo

OpenCV + Boost 示例项目，基于 CMake + Conan 管理依赖，支持 Windows（MSVC）和 Linux（GCC）双平台构建与测试。

## 环境要求

| 工具 | 版本 | 说明 |
|------|------|------|
| CMake | ≥ 3.16 | |
| Conan | ≥ 2.x | 依赖管理器 |
| Ninja | 最新 | 跨平台构建工具 |
| C++ 标准 | C++17 | 编译器需支持 C++17 |

---

## Windows

### 1. 安装依赖

**Visual Studio Build Tools**

下载 [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio)，勾选「使用 C++ 的桌面开发」。

**Python + Conan**

```powershell
pip install conan
conan profile detect --force
```

**Ninja**

```powershell
winget install Ninja-build.Ninja
```

### 2. 编译

```powershell
cd cv-boost-demo

conan install . --build=missing -s build_type=Release -s os=Windows -s arch=x86_64 -o opencv/*:with_ffmpeg=False -c tools.cmake.cmaketoolchain:generator=Ninja --output-folder=build

cmake --preset conan-release
cmake --build --preset conan-release --parallel

ctest --preset conan-release --output-on-failure
```

> ⚠️ 注意：Windows 下请使用 **PowerShell**，不要用 CMD。

---

## Linux（Ubuntu/Debian）

### 1. 安装依赖

```bash
sudo apt-get update
sudo apt-get install -y build-essential python3-pip ninja-build

pip install conan
conan profile detect --force
```

### 2. 编译

```bash
cd cv-boost-demo

conan install . --build=missing -s build_type=Release -s os=Linux -s arch=x86_64 \
  -o opencv/*:with_ffmpeg=False -o opencv/*:with_gtk=False \
  -c tools.cmake.cmaketoolchain:generator=Ninja --output-folder=build

cmake --preset conan-release
cmake --build --preset conan-release --parallel

ctest --preset conan-release --output-on-failure
```

---

## 依赖版本

| 依赖 | 版本 |
|------|------|
| OpenCV | 4.5.5 |
| Boost | 1.87.0 |

---

## GitHub CI

项目使用 GitHub Actions 自动化构建和测试，工作流配置见 [.github/workflows/cmake.yml](.github/workflows/cmake.yml)。

- **Ubuntu**（GCC + Ninja）— Conan 缓存加速
- **Windows**（MSVC + Ninja）— Conan 缓存加速

CI 流程：
1. 安装 Conan + Ninja + 编译器
2. Conan 依赖安装（结果缓存）
3. CMake Configure + Build + Test