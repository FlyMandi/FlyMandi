# Prerequisites

This document won't make any sense to read if you're new to programming or know nothing about C++/OOP.
But, if you're like me, know your way around some basic C++ but have never built anything substantial before, then this might be for you.
I've been following along w/ [GetIntoGameDev's playlist](https://www.youtube.com/playlist?list=PLn3eTxaOtL2PHxN8EHf-ktAcN-sGETKfw) to get me started and set up with a basic project. You can choose to do so to, and hopefully, I've ran into the same hurdles that you're currently on and I can clear up some of your doubts. [Here's his github repo](https://github.com/amengede/OpenGL-for-Beginners/tree/main) to go along with it.

# Why OpenGL?

You've probably heard of DirectX/Vulkan if you're a gamer and ever looked at the graphics settings in a game. But besides the fact that OpenGL/DirectX/Vulkan are Graphics APIs and mutually exclusive, I really knew nothing about the APIs themselves. 
Vulkan and Direct3D[^1] are both low-level APIs that, by design, remove many abstractions compared to OpenGL. This allows for granular control over resource management (GPU/VRAM) but in practice makes it unlikely to be a good fit to first get into. That's why I chose OpenGL to start my gamedev/graphics learning process. Also, it's been a stable standard in gamedev for decades, so it's got some really great learning resources out there.

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

# How to draw a Window to the Screen

Let's start by drawing a window to the screen. Pretty straightforward. Takes about 25 lines of code.
This is what Andrew had in his main function:
```
GLFWwindow* window;

if (!glfwInit()) {
    return -1;
}

window = glfwCreateWindow(640, 480, "Hello Window!", NULL, NULL);
glfwMakeContextCurrent(window);

if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Couldn't load opengl" << std::endl;
    glfwTerminate();
    return -1;
}

glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}
glfwTerminate();
return 0;
```
Some of this should come very intuitive here. ```window = glfwCreateWindow(640, 480, "Hello Window!", NULL, NULL);```, for instance. Create a 640x480p window, name it "Hello Window" and the last 2 parameters are monitor selection and context sharing. Andrew glanced over those for now, so I'm going to, too. They'll not be needed for something so rudimentary as opening a window.
```glfwMakeContextCurrent(window);``` is needed, because we created a window, but that's just a variable called window, so we need to tell OpenGL that that's actually the window we want to draw to the screen. 
These small if blocks of
```
if (!glfwInit()) {
    return -1;
}
```
and
```
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Couldn't load opengl" << std::endl;
    glfwTerminate();
    return -1;
}
```
are just some handy dandy error handling. Returning -1 should be self-explanatory[^3]. ```glfwInit()``` is literally a boolean function to tell you if the thing even started. 
The second one is more complicated. What it does is fairly simple, which is to return -1 when OpenGL itself can't load, but the if statement is initially confusing. I'll get back to you on that :3

[^3]: If not, I can give you a quick rundown. An int main() function is the main function of a program (duh lmao), it's basically the core logic of what you're trying to build. It's a function that returns an integer and expects to be returned a 0 (at some point) when the program has ended and not run into any errors. That's why 99% of C++ programs end on a "return 0" line of code. Now, returning anything other than 0 is known as an exit or error code. '-1' is usually used for things not initializing, but technically the value itself doesn't matter, as long as it isn't 0.

# What's a shader?

Good question. It's the same one I'm having right now.