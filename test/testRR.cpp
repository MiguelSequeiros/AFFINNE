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

	std::string alphabet("abcdefghijklmnopqrstuvwxyz");
	Transmitter alice(key,alphabet);
	Receiver bob(key,alphabet);

	std::cin.ignore();

	std::string clave;
	std::getline(std::cin,clave);

	std::cout << clave << std::endl;

	u_int A,B=0;

	try
	{
		KeyGenerator::keyGenerator_RailAndRoutes(alphabet , clave , key , A , B);
	}
	catch(const char* error)
	{
		std::cerr << error << std::endl;
	}

	std::cout << A << "  " << B << std::endl;

	int A_i = Euclides::extended_inv( A , alphabet.size());

	std::cout << A_i << std::endl;

	std::cout << " clave con modifi " << clave << std::endl;

	//std::cin.ignore();

	std::string msg;
	std::getline(std::cin,msg);
/*
	alice.rail_cipher(msg);
	std::cout << msg << std::endl;

	alice.route_cipher(msg);
	std::cout << msg << std::endl;
*/
	alice.affinne_cipher(msg,A,B);
	std::cout << msg << std::endl;
	bob.affinne_decipher(msg,A_i,B);
	std::cout << msg << std::endl;	
/*

	bob.route_decipher(msg);
	std::cout << msg << std::endl;

	bob.rail_decipher(msg);
	std::cout << msg << std::endl;
*/
	return 0;
}