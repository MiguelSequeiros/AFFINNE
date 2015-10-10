#include "../Transmitter.h"
#include "../Receiver.h"
#include "../Useful.h"
#include "../Euclides.h"
#include "../KeyGenerator.h"

#include <iostream>

int main(int argc, char const *argv[])
{
	std::string alphabet("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	int opt;

	std::cout << "Alfabeto por defecto? si(1) no(0)  ";
	std::cin>>opt;

	if(opt==0)
		std::cin>>alphabet;

	int key;
	std::cout << "Ingrese la clave : " ;
	std::cin>>key;

	Transmitter alice(key,alphabet);
	Receiver bob(key,alphabet);

	std::cout << "=======================================" << std::endl;
	std::cout << "Ingrese la el mensaje a probar : " << std::endl;
	std::cin.ignore();
	std::string msg;
	std::getline(std::cin,msg);

	std::cout << "=======================================" << std::endl;
	std::cout << "CESAR" << std::endl;
	alice.cesar_cipher(msg);
	std::cout << "CIFRADO   -> " << msg << std::endl;
	bob.cesar_decipher(msg);
	std::cout << "DECIFRADO -> " << msg << std::endl;
	std::cout << "=======================================" << std::endl;


	std::cout << "=======================================" << std::endl;
	std::cout << "REVERSE" << std::endl;
	alice.reverse_cipher(msg);
	std::cout << "CIFRADO   -> " << msg << std::endl;
	bob.reverse_decipher(msg);
	std::cout << "DECIFRADO -> " << msg << std::endl;
	std::cout << "=======================================" << std::endl;

	std::cout << "=======================================" << std::endl;
	std::cout << "CESAR MODIFICADO" << std::endl;
	alice.rcesar_cipher(msg);
	std::cout << "CIFRADO   -> " << msg << std::endl;
	bob.rcesar_decipher(msg);
	std::cout << "DECIFRADO -> " << msg << std::endl;
	std::cout << "=======================================" << std::endl;

	std::cout << "=======================================" << std::endl;
	std::cout << "VALLAS" << std::endl;
	alice.rail_cipher(msg);
	std::cout << "CIFRADO   -> " << msg << std::endl;
	bob.rail_decipher(msg);
	std::cout << "DECIFRADO -> " << msg << std::endl;
	std::cout << "=======================================" << std::endl;

	std::cout << "=======================================" << std::endl;
	std::cout << "RUTAS" << std::endl;
	alice.route_cipher(msg);
	std::cout << "CIFRADO   -> " << msg << std::endl;
	bob.route_decipher(msg);
	std::cout << "DECIFRADO -> " << msg << std::endl;
	std::cout << "=======================================" << std::endl;

	return 0;
}