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