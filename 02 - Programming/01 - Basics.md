These are the bare bones of programming. If you don't understand something that's written here, don't worry, there's an extremely large variety of free mediums that teach these topics.

# What's a programming language?

You can think of a programming language as a language that's used to talk to a computer. Programming is simply the act of translating what we want the software (game or tool or otherwise) to do, from a human language to something a computer can understand and carry out.

//TODO

## High-level vs. low-level

A high level programming language is a language that removes the _need_ for you to do stuff like manual memory management and resource allocation, but also removes the _possibility_ to do that. This would be like driving an automatic vs a manual car. Sure, a manual gives you much more granular control over your engine, but an automatic is quicker and easier to learn when you're starting out and don't know how an engine connects to your wheels. High level means abstracted and (usually) easy to implement, while low-level usually means hard to learn and use, but very powerful and customizable.

This is a matter of perspective and mostly a tool of comparison. For example, when looking from the perspective of assembly, the language C is a high-level language, since it's much more abstracted. However, when compared to Python, C is definitely a low-level language because of the same principle. Again, Python abstracts a lot more concepts. Generally, the lower level something is, the harder it is to learn and to write, but the easier it is for the machine to compile & run. The reverse is true, since when you write code in a high-level language, it might be much easier, but the compiling/interpreting/running can take a lot more time, since memory/resource management is not the focus, but instead ease of use and speed of coding.

## Text Editor

## Compiler

#### JIT vs AOT (no, not the anime)

JIT (Just-In-Time) and AOT (Ahead-of-Time) compilation are the two major ways of compiling code.

//expand

## Linker

//TODO

## Interpreter

//TODO

## IDE

An IDE, Integrated Development Environment, includes everything that you'd need to build a project in a given programming language. Microsoft's Visual Studio is a great example. Eclipse is another one. Typically, an IDE has a text editor, a compiler and a linker (or their functional equivalents) all integrated.

# What are variables?

A variable is, as the name implies, something that can change. Sometimes they're called mutables. For example, you need to store values "a" and "b" for later use. For now, just know that "int" indicates a whole number. a, b and sum are the names of the variables here. 

We store things in variables because, if we had say 100+ different calculations with numbers a and b and we need to change b, then instead of changing those 100 lines of code, we just change the one that defines what "b" is equal to.

```cpp
int a = 2;
int b = 3;

int sum = a + b;
```

## Variables vs Constants

In Programming, a variable indicates a value that's expected to be modified and a constant is, well, constant.

For example, you want to calculate the final acceleration of a fall of a person. Well, you'd need to store the height of the fall, the weight and the acceleration of gravity. The height of our fall can change, so can our weight, but does gravity? The answer is no, which is why we store it in a constant.

A constant is basically something that makes sure that we handle anything that tries to modify the constant as an error in the program. Gravity is defined by us for our program and we do not want the program to define grativy for us.

Let's use the metric system, cm for height, g for weight and cm/s$^2$ for gravity. No calculations, we just want to store the variables for now.

```cpp
int height = 312;
int weight = 69420;
const int gravity = 980; 
```
In C++ specifically, constants are declared by the word _const_ in front of the variable type, followed by the variable name.
Types are defined as follows.

## What are (variable) Types?

A type is, as the name might give away, a classification of a variable by type. We're telling our program what _type_ of number we're storing here, so that it can interpret it appropriately. If we store the divison $10 \over 3$ in an integer, we don't get the "3.3333..." that you might expect, but we simply get the number 3. That's because we've told the program to ignore everything that doesn't pertain to a _whole number_ so it ignores everything after the decimal point.

The most common types in C++ include "int" for integer, (whole numbers), "float" for floating point numbers and "char" for character (any single letter, number or symbol).

"float" and int can be used now, if we want to store our weight/height in metres and kg and gravity in m/s$^2$.

As you can see, "float" allows us to be both more precise and more readable with our code here.

```cpp
float height = 3.12;
float weight = 69.42;
const float gravity = 9.8067; 
```

### Booleans

Booleans are the simplest type of variable. They can have two values: `true` or `false`. They function the same as a logical bit, a `0` or a `1`. They're typically used as switches, but due to their small size and incredible efficiency, they can be used to improve performance, even when it might seem unintuitive to store things in a boolean.

A switch example might be a variable that stores whether an action has been performed:
```cpp
action_performed = true;
```

A creative approach exapmle might be an [array](Basics.md#arrays) of booleans that stores whether the number in the index is prime. That way, you can pass on the array itself or even just the function used to create it at runtime. It will be much more efficient than working with an array that stores all the integers themselves, since the space allocation for each element in the array is much larger.


Note: Many languages translate the numbers `0` and `1` into bits, so you can inconsequentially use them in a while() loop. This means that the expression `while(number){}` can be interpreted as "while the variable 'number' is not zero". It's very recommended to learn about how the language translates integers to booleans and other specifics before using this approach, though. Like, how does it handle negative values?

### Integers

### Floating Points

### Vectors

## Strongly vs Weakly Typed

Most modern programming languages can be put into two categories: Strongly Typed and Weakly Typed. 

This, while being independent of high-level vs. low-level, usually corresponds with this relation. Lower level languages tend to be strongly typed, while higher level languages and interpreted languages tend to be weakly typed.

# What are functions?

//TODO

## Loops

The idea of a loop is to take a task that would otherwise require dozens, hundreds or thousands of hard-coded[^1] lines and boil them down to just a couple, with the help of repetition logic.

For instance, if we wanted to print all the numbers from 1 through 10 in the console, we _could_ write this:
```cpp
std::printf("1\n");
std::printf("2\n");
std::printf("3\n");
std::printf("4\n");
std::printf("5\n");
std::printf("6\n");
std::printf("7\n");
std::printf("8\n");
std::printf("9\n");
std::printf("10\n");
```
But, even with copy-pasting each line and altering the number, this very quickly becomes not just slow to write, but also unreadable and just prone to typos.

Alternatively, we can write a loop.
```cpp
for (int i = 1; i < 11; ++i){
    std::printf("%d \n", i);
}
```

It might look a little weirdly written at first, but we'll look at the anatomy of a `for(){}` loop in a bit. More importantly, these two examples will both output the same result, but I think even intuitively you can tell why loops are a thing. Loops are almost infinitely faster to write and to read than hard-coding very big blocks of code. They're also faster to compile and come with _almost_ no performance downgrade. There are other types of loops, not just the `for(){}` one we've just looked at.

## Types of Loops & use cases

### For Loop

Here's our for loop example, once again:
```cpp
for (int i = 1; i < 11; ++i){
    std::printf("%d \n", i);
}
```

A C++ `for(){}` loop takes three arguments: a condition and two lines of code. In fact, if you have an eye for C++ Syntax you might have noticed that these aren't traditional arguments. They're functional lines of code, separated by a `;`. So, you can replace them with anything else, if needed. Anyhow, the first line of code is executed _once_ in the beginning, in this case `int i = 1`, which we use to [initialize](../02.5%20-%20Language%20Specifics/C++/Basics.md#c++-variables) our variable `i`. The second line is the condition which is checked against, every time the loop is run. In this case, `i < 11`, or in words, "is `i` smaller than 11?" So, if we were to have `i` be bigger than (or equal to) 11 to begin with, the loop would execute 0 times. The last line is what's executed at the end of the loop, before beginning the next instance. So, `i` gets increased to a value of 2 before the second pass.

Other implementations of the for loop differ in their anatomy, but have the same use cases. For example, a Python for loop looks like this:
```py
for i in range(1, 11):
    print(i)
```
And again, produces the same result as all other previous examples.

### While Loop

A `while(){}` loop takes a single argument: a condition. This means that the code portion written in `{}` will be executed for as long as the condition in `()` is true.
```cpp
int i = 1;
while(i < 11){
    std::printf("%d \n", i);
    ++i;
}
```
Note: `++i` just increases the value of `i` by 1.

All we did here was write our loop in a different way, you say. And yes, this does achieve the same result as [this for loop](Loops.md#for-loop). But, while loops do have a justification for existing. Say you want to run a line of code until something happens. 

If we don't know how many times we want to loop something, not even in relation to a variable, then all we'd end up writing is this:
```cpp
for(; condition_check; ){
    //code
}
```
Because we can't rely on our counter `i` this time. And doesn't that ever look ugly. Why not write:
```cpp
while(condition_check){
    //code
}
```
Note: both loops will continue until our [boolean](Basics.md#booleans) value `condition_check` is `false`. They are functionally the same, but the former example is just... ugly. Also, not every language is like C++ and would let you write a for loop that is functionally a while loop, so in those cases you're forced to use `while(){}`.

### Do-While Loop

## Performance

## Infinite Loops

# What are Data types?

//TODO

## Arrays

# What are pointers?

//TODO

# Equality, Assignment, etc.

//TODO