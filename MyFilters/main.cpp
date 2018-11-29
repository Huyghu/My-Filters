#include "MyFilters.h"
#include <iostream>

int main()
{
	MyFilters myFilters;
	try {
		myFilters.go();
	}
	catch (...) {
		std::cout << "An error occured." << std::endl;
	}
	return 0;
}