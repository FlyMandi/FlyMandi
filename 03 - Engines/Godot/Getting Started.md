# Why Godot?

Godot is a fairly capable engine with support for C++, which I'm going to be using to a simple snake game. It's important to understand that even though C++ is 'officially supported' by Godot, you can't actually control the game logic with it. There are reasons, for instance, not having to recompile the entire engine. What you can do, however, is create `GDExtension` Nodes that _are_ controlled by C++, then utilize those Nodes within Godot with either `GDScript` or `C#`. I've settled on creating custom nodes with C++ and working with them via `GDScript`.

Note: the `GDExtension` system replaces the `GDNative` implementation of earlier versions (pre 4.0).

# Setting up a Godot project

When setting up a project, you're asked to set a Project Name and Project Path. It's going to try to create it in your Documents folder for windows, but I recommend setting up a separate folder somewhere else. The actual project folder will be named after your Project Name, as you can see.

![alt text](image.png)

I personally like creating a separate folder, then calling the Godot project by the build name. For example, instead of having

```../Games/SnakeClone``` with Project Name 'SnakeClone', it'd be
```..Games//SnakeClone/prototype``` with Project Name 'prototype'. Different build, different godot project.

Second, you're asked to choose a renderer. Given the following three options, these are the APIs they correspond to:

- `Forward+`: Vulkan
- `Mobile`: OpenGL ES 2.0 or 3.0
- `Compatibility`: OpenGL ES 2.0

Because I'm rooting for performance, Vulkan is my choice here.

Lastly, you're asked whether you want to have version control metadata. I'd recommend selecting `Git` if you use Git or otherwise don't know yet. It just makes life a bit easier down the road if you decide to track changes with Git.

Now, let's set up our devenv[^1] and get ready to write C++ in Godot. For that, I've listed an enumerated guide below to help make this as easy to look at as possible.

### 1: Install CMake & Compiler

I'll be using `CMake`, rather than Godot's recommended way of building with `SCons`, their own weird little building, because it's limiting, slow and headache-inducing.

1. To install `CMake`, head to [the CMake download page](https://cmake.org/download/?form=MG0AV3). 

2. Then, run `cmake --version` in a command prompt to make sure you have the version you want. I'll be working with `3.30.x`.

3. Make a `CMakeLists.txt` file and configure it:
```CMake
cmake_minimum_required(VERSION 3.30)
project(gdextension-gameplay)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(FetchContent)

FetchContent_Declare(
        GDExtension
        GIT_REPOSITORY https://github.com/godotengine/godot-cpp.git
        GIT_TAG godot-4.3-stable
)

FetchContent_MakeAvailable(GDExtension)

add_subdirectory(gameplay)
```

//TODO: expand

More info about using Godot and CMake [here](https://thatonegamedev.com/cpp/cmake/godot-4-gdextension-for-c-using-cmake/?form=MG0AV3).

The compiler I've chosen to work with is `MinGW`, since it's optimized for windows. For linux, I'd recommend `GCC` and for MacOS, `Clang`. Installing MinGW goes as follows:

1. Download and install from [the official WinLibs website](https://winlibs.com/). WinLibs is the pre-made installation I'll be using. 

2. Add `mingw64/bin` (from wherever you've installed minGW to) to `PATH`[^2].

3. Verify installation by running `gcc --version` in a command prompt and making sure that it's working and it's the right version.

### 2: Install Godot headers

Clone the GitHub repository for `godot-cpp` into your top-level project folder, so that the `godot-cpp` folder lands in the same folder as your godot project. Look below for reference paths. If you are versioning your project using Git, it's a good idea to add them as Git submodules.[^3] The .gitignore[^4] files for Godot are already configured, so no need to create any by hand. 

We'll create a folder called `src/`, which is going to be our directory for the code we're writing - all our `.cpp` and `.h` files. You could separate the header files into a different folder, but I'm not going to be doing that.

You should now have a project folder that looks something like this:
```
SnakeClone/
|
+---godot-cpp/
|    |
|    +---(all the godot cpp dependencies)
|
+---prototype/
|    |
|    +---.godot/
|        |
|        +---(bunch of godot files)
|
+---src/
|    |
|    +---(code files)
|
+---CMakeLists.txt
```


### 3: Link C++ to Godot via GDExtension

Porting our Game Logic to C++ is not as easy as it might seem, since up until here, everything has been super straight forward. However, one look at [the GDExtension example](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html) reveals that it isn't quite the case. Godot functions by using nodes, for example one for `AnimatedSprite2D` or `CollisionShape2D` which are easy to work with and modify inside godot. You can then import them into your game logic by simply controlling them via `GDScript`. As I mentioned in the intro, you can't actually port the game logic loop to C++. That's fine by me for now, but can be a dealbreaker for some.

//TODO: expand

### 4: Finally writing some C++ code

//TODO

[^1]: devenv: short for 'development environment', used to describe the suite of tools, such as a text editor, compiler, linker, etc. that are made use of to build a project. The digital equivalent of an office desk.

[^2]: adding something to `PATH` on windows, see [why and how](https://www.eukhost.com/kb/how-to-add-to-the-path-on-windows-10-and-windows-11/).

[^3]: To do so, you'll need to run `git init` and `git submodule add https://github.com/godotengine/godot-cpp`. If you cloned into the project folder manually, run `git submodule update --init --recursive` after having done so. For more info, [read here](https://docs.godotengine.org/en/3.5/tutorials/scripting/gdnative/gdnative_cpp_example.html).

[^4]: a `.gitignore` file is exactly what it sounds like, it's a list of paths that should be ignored by git. Specify here which files should not have changes to them tracked and/or uploaded to github alongside your project folder.