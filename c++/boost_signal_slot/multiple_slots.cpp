/*
* Referência: https://www.boost.org/doc/libs/1_47_0/doc/html/signals2/tutorial.html
*
*/
#include <iostream>
#include <boost/signals2.hpp>

struct Hello
{
	void operator()() const
	{
		std::cout << "Hello";
	}
};

struct World
{
	void operator()() const
	{
		std::cout << ", World!" << std::endl;
	}
};

int main() {
	// Signal with no arguments and a void return value
	boost::signals2::signal<void ()> sig;

	// Connect Hello and World slot
	sig.connect(Hello());
	sig.connect(World());

	// Call all of the slots
	sig();

    return 0;
}
