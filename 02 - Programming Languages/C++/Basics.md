# Getting started with C++

C++ is a compiled language, which means you'll need either a suitable [IDE]() or some combination of [Text Editor](), [Compiler]() and [Linker](). If you're familiar with another language, there's probably a way to tweak your setup to fit C++, but if not, I would recommend [Visual Studio](https://visualstudio.microsoft.com/vs/community/) as an IDE. Or you could do what I do, which is to use [VSCode](https://code.visualstudio.com) as a text editor and Visual Studio itself as a linker/compiler combo.
If you're <del>a deranged lunatic</del> using macOS, I've heard XCode and Clang is a good combo.


# Syntax

## Namespaces

A namespace in C++ is used to discern between different versions of names and resolving name conflicts. For the purposes of getting started, you should understand a few key things about namespaces. First of all, if you have _ever_ seen a C++ beginner tutorial, you've probably come across the infamous ```using namespace std;``` line. This line basically means "for every unresolved name in the code, use the std namespace", where std means "standard" and nothing else. :suspect:
As tempting as it may be, you should get used to write the namespace, scope operator and name like so: ```std::string``` instead of just ```string``` and defining the used namespace elsewhere. You might want to distinguish between a standard library string, ```std::string``` and your own namespace string, ```cus::string``` where ```cus``` stands for custom, a namespace that you've built yourself.
Even if this feature seems useless to you now, it doesn't cost you much to use best practices, before you end up spending countless hours of troubleshooting because a function that's written somewhere in your code is using a namespace you didn't intend it to.
You can read further documentation [here](https://en.cppreference.com/w/cpp/language/namespace).

## C++ Variables
Variables are declared as follows:
```
type variable_name = value;
```
For example:
```
int counter = 0;
```

There's a difference between _initializing_ and _declaring_ a variable or function in C++. What we saw was an _initialization_ with a starting value. What is also legal C++, however, is the following:
```
int unknown;

//code block

unknown = 0;
```
This code block can contain as much code as you want.
However, it's important to note that if the variable ```unknown``` is accessed any time before it was _initialized_ (this would be anywhere in the code block in this example) this value will be unpredictable[^1] and this behaviour should be avoided.
[^1]: From [en.cppreference.com:](https://en.cppreference.com/book/uninitialized#:~:text=To%20create%20a%20variable%20without%20an%20initial%20value%2C%20simply%20don,time%20the%20program%20is%20run.) "The value in an uninitialized variable can be anything – it is unpredictable, and may be different every time the program is run. Reading the value of an uninitialized variable is undefined behaviour – which is always a bad idea. It has to be initialized with a value before you can use it."

## C++ Functions
A function is constructed as follows:
```
returnType function_name (argumentType argument_name){
    //whatever the function does
    return result
}
```
For example:

//TODO

### Return Types

Return types can be any legal C++ type. They indicate what type of value your function is expected to return. A sum() function would usually take two ```int``` parameter values and return a single ```int``` value, for example. A concatenate_string() function might take two separate ```std::string``` values and return another ```std::string```. Or maybe a convert_to_string() takes a character array (```char[]```) and converts it to a ```std::string``` via its return type.

There is, however, a return type that's usually exclusive to functions[^2], namely, the type "void". A void function is used to declare a function that doesn't return anything, it simply does stuff. Like printing to the console, for example. The following function would print "Hello World!" to the console, followed by the newline "\n" character. We don't need the function itself to return a value, because we simply want to print these words every time the function is called.

[^2]: [learn.microsoft.com](https://learn.microsoft.com/en-us/cpp/cpp/void-cpp?view=msvc-170) describes that a void type can't be assigned to a variable and is used in either functions, to specify no specific return result, or in pointers, for uses such as converting it to any type of data pointer.

```
void hello_world(){
    std::cout << "Hello World!\n";
}
```

# Pointers and References

In C++, there is differentiation between a pointer and a reference. While these two might seem similar or identical at first, they aren't.

The pointer operator, ```*```, is used for storage of the memory address of an object, while the reference operator, ```&```, is used for creating an alias for an object. 

In short, a pointer is a number that corresponds to the memory address of an object and can therefore be ```NULL```, a ```nullptr```. A pointer can be re-assigned while a reference cannot. A reference can also _never_ be ```NULL``` and a null reference means some bad, stinky code was written. A reference also doesn't hold a value in itself, it simply refers to an object, which is why it can't be ```NULL```.

For example, if we wanted a quick way to access an important element of a list, we would create a pointer. Because we proabably would want to be able to change that element.
But, if we wanted to create a function and one of the arguments is a before established variable (like gravity), we'd simply use a reference to our value, which saves memory space and makes sure that we don't try to change the value from within the function _and_ we make sure that by changing our gravity variable from before, our changes carry over. In case we were suddenly calculating a fall on the moon. Or Mars.

Correctly using both pointers and references can save a lot of runtime, but also makes the written code more legible and stable.

More on the difference between a pointer and a reference [here](https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable).

# Type Casting

//TODO 