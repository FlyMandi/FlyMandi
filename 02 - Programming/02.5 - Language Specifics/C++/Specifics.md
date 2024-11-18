## Class vs Struct

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

## Hierarchy and Inheritance

//TODO

## Constructors and Destructors

//TODO

## Operator Overloads
You can think of an operator overload like a contextual operator. When we add two integers, say 1 and 2, we just use the ```+``` operator and do ```1 + 2 = 3```. Now, what if we wanted to add two fractions, say $10\over3$ and $7\over4$? We can't use use our ```+``` operator here. However, if we still wanted to use the same operator for both operations in our code, we'd need to use an operator overload. Essentially, when defining an operator overload, you're defining an additional behaviour that the operator can have, depending on its context. We could tell the ```+``` operator to behave differently when dealing with fractions. <br>
For this example, I've defined a class that just has two properties, a numerator and a denominator. If the ```+``` operator now sees that it's dealing with a ```fraction``` class, then it'll read our operator overload and behave accordingly.

## Class Example

```cpp
#include <iostream>
#include <string>

const std::string unk = "unknown";
const std::string prefix = "copy-of-";

class Human {

	std::string _name = "";
	int _height = 0;
	int _age = 0;
	
public: 

	Human();
	Human(const std::string& name, const int& height, const int& age);
	Human(const Human& right);
	Human& operator = (const Human& right);
	~Human();
	void print() const;
	
};

Human::Human() : _name(unk), _height(0), _age(0) {
	puts("Default Constructor");
}

Human::Human(const std::string& name, const int& height, const int& age)
	: _name(name), _height(height), _age(age) {
	puts("Constructor w/ arguments");
}

Human::Human(const Human& right) {
	puts("Copy Constructor");
	_name = prefix + right._name;
	_height = right._height;
	_age = right._age;
}

Human& Human::operator = (const Human& right) {
	puts("Copy Operator!");
	if (this != &right) {
		_name = prefix + right._name;
		_height = right._height;
		_age = right._age;
	}
}

Human::~Human() {
	printf("Destructor: %s ", _name.c_str());
}

void Human::print() const {
	printf("Hello, I'm %s, %dcm tall and %d years old.\n", _name.c_str(), _height, _age);
}

int main() {
	Human Mandi ("FlyMandi", 176, 20);
	Mandi.print();

	const Human copy = Mandi;
	copy.print();
}
```

## File Structure

//TODO: headers, header guards, how it all works

`human.h`:
```cpp
#pragma once

class Human {

	std::string _name = "";
	int _height = 0;
	int _age = 0;
	
public: 

	Human();
	Human(const std::string& name, const int& height, const int& age);
	Human(const Human& right);
	Human& operator = (const Human& right);
	~Human();
	void print() const;
	
};
```

`human.cpp`:
```cpp
#include <iostream>
#include <string>
#include <human.h>

const std::string unk = "unknown";
const std::string prefix = "copy-of-";

Human::Human() : _name(unk), _height(0), _age(0) {
	puts("Default Constructor");
}

Human::Human(const std::string& name, const int& height, const int& age)
	: _name(name), _height(height), _age(age) {
	puts("Constructor w/ arguments");
}

Human::Human(const Human& right) {
	puts("Copy Constructor");
	_name = prefix + right._name;
	_height = right._height;
	_age = right._age;
}

Human& Human::operator = (const Human& right) {
	puts("Copy Operator!");
	if (this != &right) {
		_name = prefix + right._name;
		_height = right._height;
		_age = right._age;
	}
}

Human::~Human() {
	printf("Destructor: %s ", _name.c_str());
}

void Human::print() const {
	printf("Hello, I'm %s, %dcm tall and %d years old.\n", _name.c_str(), _height, _age);
}

int main() {
	Human Mandi ("FlyMandi", 176, 20);
	Mandi.print();

	const Human copy = Mandi;
	copy.print();
}
```

## STL stuff

The Standard Template Library (STL) in C++ is a handy thing.

//TODO

note: please don't ever use `using namespace std;` unless you're just starting out. It'll save you a couple headaches down the line.

#### std::vector

//TODO

#### std::filesystem (C++17 onwards)
When you're trying to join a path from user input, it's not enough to simply add to a `string`. Because, if we have a partial path and we tried taking the rest of the path from user input, it would only work if the user adds no extra slashes.
```cpp
std::string ourPath = "../example_path/" + input
```
With `input = /xyz.file`, `ourPath` is now `../example_path//xyz.file`, which is not valid. Also, if we tried using this path in an operating system that uses `\` instead of `/`, we'd also run into trouble.

Instead of having to worry about working with `strings` when trying to manipulate variables that are file paths, like concatenating/joining paths or reading from user input, there's this handy thing in the STL called `std::filesystem::path`.
```cpp
std::filesystem::path ourPath = std::filesystem::path("../example_path") / input
```
This will actually normalize the path, get rid of double `//` and it's cross-platform, meaning it'll automatically translate to `\` when necessary.
