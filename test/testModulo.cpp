#include "Useful.h"
#include <iostream>

 int main(int argc, char const *argv[])
{
	for(int i=-9 ; i< 10 ; i++)
	{
		std::cout << Useful::mod(i,3) << std::endl;
	}
	return 0;
}