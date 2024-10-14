# Why Godot?

Godot is a fairly capable engine with support for C++, which I'm going to be using to build my games. There are possibilities of using GDScript, VisualScript or C#, but personally, I like control over a lot of the performance, hence I'm going to be using C++ with GDNative, which is their way of integrating C and C++ code into Godot projects.

# Setting up a project with C++

When setting up a new project, you're asked to choose a renderer. Given the following three options, these are the APIs they correspond to:

- `Forward+`: Vulkan
- `Mobile`: OpenGL ES 2.0 or 3.0
- `Compatibility`: OpenGL ES 2.0

Because I'm rooting for performance, Vulkan is my choice here.

Now, let's set up our devenv[^1] and get ready to write C++ in Godot. For that, I've listed an enumerated guide below to help make this as easy to look at as possible.

## 1: Install CMake & Compiler

To install `CMake`, head to [the CMake download page](https://cmake.org/download/?form=MG0AV3). Then, run `cmake --version` in a command prompt to make sure you have the version you want. I'll be working with `3.30.x`.

The compiler I've chosen to work with is `MinGW`, since it's optimized for windows. For linux, I'd recommend `GCC` and for MacOS, `Clang`. Installing MinGW goes as follows:

1. Download and install from [the official WinLibs website](https://winlibs.com/). WinLibs is the pre-made installation I'll be using. 

2. Add `mingw64/bin` (from wherever you've installed mingw to) to `PATH`[^2].

3. Verify installation by running `gcc --version` in a command prompt and making sure that it's working and it's the right version.

## 2: Install Godot headers

## 3: Create Source files

## 4: Link C++ to Godot via GDNative

[^1]: devenv: short for 'development environment', used to describe the suite of tools, such as a text editor, compiler, linker, etc. that are made use of to build a project. The digital equivalent of an office desk.

[^2]: adding something to `PATH` on windows, see [why and how](https://www.eukhost.com/kb/how-to-add-to-the-path-on-windows-10-and-windows-11/).