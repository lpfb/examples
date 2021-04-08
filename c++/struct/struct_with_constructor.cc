#include <iostream>

struct TestStruct {
	int id;
	TestStruct() : id(42) {} // Struct constructor
};

int main() {
	TestStruct st;
	std::cout << "Id value: " << st.id << std::endl;
	return 0;
}
