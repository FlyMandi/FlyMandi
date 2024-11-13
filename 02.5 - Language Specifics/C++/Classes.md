# Class vs Struct

A C++ Struct is essentially a Class, except we use it differently. A Struct has all members public by default and also inherits publicly by default. If not specified, everything in a C++ Class will be private and everything in a struct will be public. Which is why you'll often see something like this:
```cpp
class example{
    int private_number = 0;
public: //everything before this keyword is private
    int get_number(){ return private_number; }
};
```
This is identical to:
```cpp
class example{
private:
    int private_number = 0;
public:
    int get_number(){ return private_number; }
};
```
In this example, functions outside of the class won't be able to access the variable ```private_number```, but instead, call the function ```get_number()```.

A struct would be used for simpler, plainer data structures that don't require encapsulation, inheritance, polymorphism, etc.

# Hierarchy and Inheritance

//TODO

# Constructors and Destructors

//TODO

# Operator Overloads
You can think of an operator overload like a contextual operator. When we add two integers, say 1 and 2, we just use the ```+``` operator and do ```1 + 2 = 3```. Now, what if we wanted to add two fractions, say $10\over3$ and $7\over4$? We can't use use our ```+``` operator here. However, if we still wanted to use the same operator for both operations in our code, we'd need to use an operator overload. Essentially, when defining an operator overload, you're defining an additional behaviour that the operator can have, depending on its context. We could tell the ```+``` operator to behave differently when dealing with fractions. <br>
For this example, I've defined a class that just has two properties, a numerator and a denominator. If the ```+``` operator now sees that it's dealing with a ```fraction``` class, then it'll read our operator overload and behave accordingly.

//TODO