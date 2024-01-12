# Why OpenGL?

You've probably heard of DirectX/Vulkan if you're a gamer and ever looked at the graphics settings in a game. But besides the fact that OpenGL/DirectX/Vulkan are Graphics APIs and mutually exclusive, I really knew nothing about the APIs themselves. 
Vulkan and Direct3D[^1] are both low-level APIs that, by design, remove many abstractions compared to OpenGL. This allows for granular control over resource management (GPU/VRAM) but in practice makes it unlikely to be a good fit to first get into. That's why I chose OpenGL to start my learning process. Also, it's been a stable standard in gamedev for decades, so it's got some really great resources out there.

[^1]: DirectX is a collection of Microsoft's APIs that includes Direct3D, their Graphics API.

# How set up OpenGL?

To use OpenGL with a basic project, I set up C++ with CMake[^2] and the following dependencies: [glad](https://glad.dav1d.de), [glfw](https://www.glfw.org/download) and [glm](https://github.com/g-truc/glm/releases), such that I include "glad.h", "glfw3.h", and "glm.hpp" in my header file.
Glad requires KHR, which should come with your glad download. Glfw might require a glfw3.lib and glfw3.dll that you can get from the pre-compiled binaries [here](https://www.glfw.org/download).
OpenGL itself is imported in CMakelists.txt, like in the following example:
[^2]: I use the VSCode extensions CMake (for intellisense) and CMaketools (for compiling) for now, but you can easily setup CMake through the Visual Studio IDE or XCode, too.
```
cmake_minimum_required(VERSION 3.5)
project(Snake VERSION 1.0.0)
find_package(OpenGL REQUIRED)

set(SOURCE_FILES 
    src/main.cpp src/config.h 
    src/glad.c src/mesh.cpp 
    src/mesh.h
)

link_directories(Snake lib)
add_executable(Snake ${SOURCE_FILES})

target_include_directories(Snake PRIVATE dependencies)
target_link_libraries(Snake glfw3 OpenGL::GL)
```
Here, in ```find_package(OpenGL REQUIRED)``` we're doing just that, finding the OpenGL package. <br>
In this case, ```link_directories(Snake lib)``` points to the lib folder, in which I put the files from "lib-vs2022" from the pre-compiled glfw3 binaries.
```add_executable(Snake ${SOURCE_FILES})``` allows us to compile an .exe with all of the specified source files. <br>
In ```target_include_directories(Snake PRIVATE dependencies)``` are the dependencies that I stated earlier. <br>
Then, with ```target_link_libraries(Snake glfw3 OpenGL::GL)``` we're linking our program "Snake" to what it needs to compile, in this case glfw3 and the OpenGL package we searched for earlier.

To compile this, I'm running the Visual Studio Community 2022 release kit for amd64.

# OK, but how about how to *use* OpenGL?

That, my friend, I'm working on myself, currently.
