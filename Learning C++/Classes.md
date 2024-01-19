# Object Oriented Programming (OOP)

//TODO

# Class vs Struct

//TODO

# Public vs Private

//TODO

If not specified, everything in a C++ Class will be private and everything in a struct will be public. Which is why you'll often see something like this:
```
class example{
    int private_number = 0;

public:

    int get_number(){ return private_number; }
};
```
In this example, functions outside of the class won't be able to access the variable ```private_number```, but instead, call the function ```get_number()```.

# Hierarchy and Inheritance

//TODO

# Constructors and Destructors

//TODO

# Operator Overloads

//TODO