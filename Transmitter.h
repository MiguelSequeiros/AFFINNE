#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <string>
#include <iostream>			

class Transmitter
{
private:

	int key;
	std::string alphabet;

	void adjust_indexes( int , int* );
	void adjust_str( std::string & );

	/*Generacion de claves*/


public:
	/*	Crypto Algorithms	*/
	
	void cesar_cipher( std::string & );
	void reverse_cipher( std::string & );
	void rcesar_cipher( std::string & );
	void rail_cipher( std::string & );
	void route_cipher( std::string & );
	void affinne_cipher( std::string & , u_int , u_int );

	Transmitter( int , std::string );

	/* Mode of use */

	~Transmitter();

};

#endif // TRANSMITTER_H
