#include "../Useful.h"
#include "../Euclides.h"
#include "../KeyGenerator.h"
#include "../Transmitter.h"
#include "../Receiver.h"

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string alphabet("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	int opt;

	std::cout << "Alfabeto por defecto? si(1) no(0)  ";
	std::cin>>opt;

	if(opt==0)
		std::cin>>alphabet;

	int key;
	std::cout << "Ingrese clave   " << std::endl;
	std::cin >> key;

	/*Instancia de objetos*/
	Transmitter alice(key,alphabet);
	Receiver bob(key,alphabet);

	std::cout << "Ingrese una palabra clave para el generador de clave :" << std::endl;
	std::cin.ignore();

	std::string clave;
	std::getline(std::cin,clave);

	std::cout << "cifrar(1) decifrar(2)" << std::endl;
	std::cin>>opt;

	if(opt==1)
		{
			std::cout << "Su clave es : " << std::endl;
			alice.rcesar_cipher(clave);
			std::cout << clave << std::endl;
		}

	else if(opt==2)
		{
			std::cout << "Su clave es : " << std::endl;
			bob.rcesar_decipher(clave);
			std::cout << clave << std::endl;
		}

	u_int A,B=0;


	clock_t start = clock();
	    
	try
	{
		KeyGenerator::keyGenerator_RailAndRoutes(alphabet , clave , key , A , B);
	}
	catch(const char* error)
	{
		std::cerr << error << std::endl;
	}

	std::cout << "Time Generation: " << double(clock() - start)/CLOCKS_PER_SEC << std::endl;

	std::cout << " Clave A : " << A << std::endl;
	std::cout << " Clave B : " << B << std::endl;

	int A_i = Euclides::extended_inv( A , alphabet.size());

	std::cout << " Clave A_i : " << Useful::mod(A_i,alphabet.size()) << std::endl;


	std::cout << "Ingrese el texto a tratar: " << std::endl;
	std::string msg;
	std::getline(std::cin,msg);

	std::cout << " Cifrar (1)  Decifrar (2)  Test(3) " ;
	std::cin >> opt;

	if(opt==1)
		alice.affinne_cipher(msg,A,B);

	else if (opt==2)
		bob.affinne_decipher(msg,A_i,B);

	else
	{

		start = clock();
		alice.affinne_cipher(msg,A,B);
		std::cout << "Time cipher: " << double(clock() - start)/CLOCKS_PER_SEC << std::endl;

		std::cout << msg << std::endl;
		start = clock();
		bob.affinne_decipher(msg,A_i,B);
		std::cout << "Time decipher: " << double(clock() - start)/CLOCKS_PER_SEC << std::endl;

	}

	std::cout << msg << std::endl;


	return 0;
}