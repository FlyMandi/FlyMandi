# Object Oriented Programming (OOP)

//TODO

# Class vs Struct

//TODO

# Public vs Private

Public and private are 2 keywords that indicate whether or not a property can be accessed outside of the definition of the class or struct.
If not specified, everything in a C++ Class will be private and everything in a struct will be public. Which is why you'll often see something like this:
```
class example{
    int private_number = 0;
public:
    int get_number(){ return private_number; }
};
```
This is identical to:
```
class example{
private:
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
You can think of an operator overload like a contextual operator. When we add two integers, say 1 and 2, we just use the ```+``` operator and do ```1 + 2 = 3```. Now, what if we wanted to add two fractions, say $10\over3$ and $7\over4$? We can't use use our ```+``` operator here. However, if we still wanted to use the same operator for both operations in our code, we'd need to use an operator overload. Essentially, when defining an operator overload, you're defining an additional behaviour that the operator can have, depending on its context. We could tell the ```+``` operator to behave differently when dealing with fractions. <br>
For this example, I've defined a class that just has two properties, a numerator and a denominator. If the ```+``` operator now sees that it's dealing with a ```fraction``` class, then it'll read our operator overload and behave accordingly.

//TODO