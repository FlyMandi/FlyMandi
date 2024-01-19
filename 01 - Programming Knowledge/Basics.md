These are the bare bones of programming. If you don't understand something that's written here, don't worry, there's an extremely large variety of free mediums that teach these topics.

# What's a programming language?

//TODO

## Compilers

//TODO

## Linkers

//TODO

## Interpreters

//TODO

## IDEs

An IDE, Integrated Development Environment, includes 

## High-level vs. low-level

This is a matter of perspective and mostly a tool of comparison. For example, when looking from the perspective of assembly, the language C is a high-level language, since it's much more abstracted. However, when compared to Python, C is definitely a low-level language because of the same principle. Again, Python abstracts a lot more concepts. Generally, the lower level something is, the harder it is to learn and to write, but the easier it is for the machine to compile & run. The reverse is true, since when you write code in a high-level language, it might be much easier, but the compiling/interpreting/running can take a lot more time, since memory/resource management is not a primary concern.


# What are variables?

A variable is, as the name implies, something that can change. Sometimes they're called mutables. For example, you need to store values "a" and "b" for later use. For now, just know that "int" indicates a whole number. a, b and sum are the names of the variables here. 

We store things in variables because, if we had say 100+ different calculations with numbers a and b and we need to change b, then instead of changing those 100 lines of code, we just change the one that defines what "b" is equal to.

```
int a = 2;
int b = 3;

int sum = a + b;
```

## Variables vs Constants

In Programming, a variable indicates a value that's expected to be modified and a constant is, well, constant.

For example, you want to calculate the final acceleration of a fall of a person. Well, you'd need to store the height of the fall, the weight and the acceleration of gravity. The height of our fall can change, so can our weight, but does gravity? The answer is no, which is why we store it in a constant.

A constant is basically something that makes sure that we handle anything that tries to modify the constant as an error in the program. Gravity is defined by us for our program and we do not want the program to define grativy for us.

Let's use the metric system, cm for height, g for weight and cm/s$^2$ for gravity. No calculations, we just want to store the variables for now.

```
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

```
float height = 3.12;
float weight = 69.42;
const float gravity = 9.8067; 
```

## Strongly vs Weakly Typed

Most modern programming languages can be put into two categories: Strongly Typed and Weakly Typed. 

This, while being independent of high-level vs. low-level, usually corresponds with this relation. Lower level languages tend to be strongly typed, while higher level languages and interpreted languages tend to be weakly typed.

# What are functions?

//TODO

# What are pointers?

//TODO
