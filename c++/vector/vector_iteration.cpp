#include <iostream>
#include <vector>

int main() {
	std::vector<int> id = {10, 20 , 30};

    int teste = id.at(0);

	// Using auto, similar to python for
	for (auto i : id) {
		std::cout << "Auto, value of id = " << std::to_string(i) << std::endl;
	}

	// Using iterator to iterate over vector values
	std::vector<int>::iterator v = id.begin();
	while( v != id.end()) {
		std::cout << "Iterator, value of id = " << *v << std::endl;
		v++;
	}
   return 0;
}
