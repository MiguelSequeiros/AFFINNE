#include "Transmitter.h"
#include "Receiver.h"
#include "Useful.h"
#include "Euclides.h"
#include "KeyGenerator.h"

#include <iostream>

int main(int argc, char const *argv[])
{
	int key;
	std::cin>>key;

	Transmitter alice(key,"");
	Receiver bob(key,"");

	std::string msg;
	std::cin >> msg;

	alice.rail_cipher(msg);
	std::cout << msg << std::endl;

	bob.rail_decipher(msg);
	std::cout << msg << std::endl;

	std::cout << "=======================================" << std::endl;

	return 0;
}