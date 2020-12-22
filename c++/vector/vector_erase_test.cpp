#include <algorithm>  // remove and remove_if
#include <iostream>
#include <vector>  // the general-purpose vector container

bool IsOdd(int i) { return i & 1; }

struct vec_st {
	int a;
	int b;
};

void Print(const std::vector<vec_st>& vec) {
	for (const auto& i : vec) {
		std::cout << "a: " << i.a << ", b: " << i.b << std::endl;
	}
}


int main() {
	// Initializes a vector that holds numbers from 0-9.
	std::vector<vec_st> v;

	for(int i = 0; i < 5; ++i) {
		vec_st vec_struct;
		vec_struct.a = i;
		vec_struct.b = i+1;
		v.push_back(vec_struct);

	}
	Print(v);
	std::cout << "==========" << std::endl;

	vec_st vec_struct;
	vec_struct.a = 0;
	vec_struct.b = 1;

    v.erase(
        std::remove_if(v.begin(), v.end(), [&](vec_st const & vec) {
            return true;
        }),
        v.end());

	Print(v);
	//
	// // Removes all odd numbers.
	// v.erase(std::remove_if(v.begin(), v.end(), IsOdd), v.end());
	// Print(v);
}
