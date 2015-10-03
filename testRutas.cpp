#include "Useful.h"
#include "Euclides.h"
#include "KeyGenerator.h"
#include "Transmitter.h"
#include "Receiver.h"

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	int key;
	std::cin>>key;

	Transmitter alice(key,"");
	Receiver bob(key,"");

	std::string msg;
	std::cin>>msg;

	alice.route_cipher(msg);
	std::cout << msg << std::endl;

	bob.route_decipher(msg);
	std::cout << msg << std::endl;

	return 0;
}