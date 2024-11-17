# Why C++?

C++, the object-oriented version of C, is a very versatile language that's fairly [low-level](../../02%20-%20Programming/Basics.md#high-level-vs-low-level) and can grant you a lot of control over performance, like access to memory management and sophisticated pointer setups. No problem if you don't know what those two things mean, just know C++ is a very capable language.

# Getting started with C++

C++ is a compiled language, which means you'll need either a suitable [IDE](../../02%20-%20Programming/Basics.md#IDE) or some combination of [Text Editor](../../02%20-%20Programming/Basics.md#text-editor), [Compiler](../../02%20-%20Programming/Basics.md#compiler) and [Linker](../../02%20-%20Programming/Basics.md#linker). If you're familiar with another language, there's probably a way to tweak your setup to fit C++, but if not, I would recommend [Visual Studio](https://visualstudio.microsoft.com/vs/community/) as an IDE. Or you could do what I do, which is to use [VSCode](https://code.visualstudio.com) as a text editor and Visual Studio itself as a linker/compiler combo.
If you're <del>a deranged lunatic</del> using macOS, I've heard XCode and Clang is a good combo.

# Syntax

## Namespaces

A namespace in C++ is used to discern between different versions of names and resolving name conflicts. For the purposes of getting started, you should understand a few key things about namespaces. First of all, if you have _ever_ seen a C++ beginner tutorial, you've probably come across the infamous ```using namespace std;``` line. This line basically means "for every unresolved name in the code, use the std namespace", where std means "standard" and nothing else. :suspect:
As tempting as it may be, you should get used to write the namespace, scope operator and name like so: ```std::string``` instead of just ```string``` and defining the used namespace elsewhere. You might want to distinguish between a standard library string, ```std::string``` and your own namespace string, ```cus::string``` where ```cus``` stands for custom, a namespace that you've built yourself.
Even if this feature seems useless to you now, it doesn't cost you much to use best practices, before you end up spending countless hours of troubleshooting because a function that's written somewhere in your code is using a namespace you didn't intend it to.
You can read further documentation [here](https://en.cppreference.com/w/cpp/language/namespace).

## C++ Variables
Variables are declared as follows:
```cpp
type variable_name = value;
```
For example:
```cpp
int counter = 0;
```

There's a difference between _initializing_ and _declaring_ a variable or function in C++. What we saw was an _initialization_ with a starting value. What is also legal C++, however, is the following:
```cpp
int unknown;

//code block

unknown = 0;
```
This code block can contain as much code as you want.
However, it's important to note that if the variable ```unknown``` is accessed any time before it was _initialized_ (this would be anywhere in the code block in this example) this value will be unpredictable[^1] and this behaviour should be avoided.
[^1]: From [en.cppreference.com:](https://en.cppreference.com/book/uninitialized#:~:text=To%20create%20a%20variable%20without%20an%20initial%20value%2C%20simply%20don,time%20the%20program%20is%20run.) "The value in an uninitialized variable can be anything – it is unpredictable, and may be different every time the program is run. Reading the value of an uninitialized variable is undefined behaviour – which is always a bad idea. It has to be initialized with a value before you can use it."

## C++ Functions
A function is constructed as follows:
```cpp
returnType function_name (argumentType argument_name){
    //whatever the function does
    return result;
}
```
For example:


```cpp
int calc_sum (int firstNumber, int secondNumber){
    int resulting_sum = firstNumber + secondNumber;
    return resulting_sum;
}
```


But, to save a little time & space, you can often write part of the function in the `return` statement.
```cpp
int calc_sum (int firstNumber, int secondNumber){
    return (firstNumber + secondNumber);
}
```

### Return Types

Return types can be any legal C++ type. They indicate what type of value your function is expected to return. A sum() function would usually take two ```int``` parameter values and return a single ```int``` value, for example. A concatenate_string() function might take two separate ```std::string``` values and return another ```std::string```. Or maybe a convert_to_string() takes a character array (```char[]```) and converts it to a ```std::string``` via its return type.

There is, however, a return type that's usually exclusive to functions[^2], namely, the type "void". A void function is used to declare a function that doesn't return anything, it simply does stuff. Like printing to the console, for example. The following function would print "Hello World!" to the console, followed by the newline "\n" character. We don't need the function itself to return a value, because we simply want to print these words every time the function is called.

[^2]: [learn.microsoft.com](https://learn.microsoft.com/en-us/cpp/cpp/void-cpp?view=msvc-170) describes that a void type can't be assigned to a variable and is used in either functions, to specify no specific return result, or in pointers, for uses such as converting it to any type of data pointer.

```cpp
void hello_world(){
    std::cout << "Hello World!\n";
}
```

## i++ and ++i

//TODO

# Pointers and References

//TODO

# Type Casting

//TODO 


## Example Bit adder

```cpp
#include <iostream>

int main() {
    bool a[]  = {0, 1, 1, 1, 1, 1, 1, 0};
    bool b[]  = {1, 0, 1, 1, 1, 1, 1, 1};
    bool c[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int r = sizeof(a);
    bool carry = false;
    for (int i = 0; i < r; ++i){
        c[i] = (a[i] xor b[i]) xor carry;
        carry = a[i]&&b[i];
    }
    if (carry) { c[sizeof(c) - 1] = true; }
    for (int i = 0; i < r + 1; ++i) {
        std::cout << c[i];
    }
}
```