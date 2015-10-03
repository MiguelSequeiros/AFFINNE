#include "Transmitter.h"
#include "Useful.h"
#include "Euclides.h"

Transmitter::Transmitter(int key , std::string alphabet)
{
	this -> key = key;
	this -> alphabet = alphabet;
};

void Transmitter::adjust_indexes( u_int x , u_int* n )
{
	for(int i=x ; i<key ; i++)
		n[i]++;
};

void Transmitter::adjust_str(std::string & str)
{
	// ajustaremos en caso que mod sea diferente de 0 , sino lo es regresa como estaba
	int mod=Useful::mod(str.size(),key);
	if(mod!=0)
	{
		const int adj = key- Useful::mod(str.size(),key);
		for(int i=0 ; i < adj ; i++)
			str+="x";
	}
}

void Transmitter::cesar_cipher ( std::string & str )
{
	for( int i=0 ; i < str.size() ; i++ )
		str[i] = alphabet[ Useful::mod( alphabet.find( str[i] ) + key , alphabet.size() ) ];
};

void Transmitter::reverse_cipher( std::string & str )
{
	for( int i=0 ; i<str.size() ; i++ )
		str[i] = alphabet[ alphabet.size() - alphabet.find( str[i] ) - 1 ];
};

void Transmitter::rcesar_cipher( std::string & str )
{
	reverse_cipher(str);
	cesar_cipher(str);
};

void Transmitter::rail_cipher( std::string & str )
{
	u_int * n = new u_int[key];
	const int seg = key-1;

	bool upFlag = false;

	u_int currentPos = 0;

	for( int i=0 ; i<=str.size()/seg && currentPos<str.size() ; i++ )
	{	
		for( int j=0 ; j<seg && currentPos<str.size() ; j++ )
		{
			//const int idx = i*seg + j
			char tmp = str[currentPos];

			str.erase(str.begin() + currentPos);
			str.insert(str.begin() + n[ upFlag ? seg - Useful::mod(currentPos,seg) : Useful::mod(currentPos,seg) ], tmp );

			adjust_indexes( upFlag ? seg - Useful::mod(currentPos,seg): Useful::mod(currentPos,seg) , n );
			currentPos++;
		}
		upFlag = not upFlag;
	}

	delete [] n;
};

void Transmitter::route_cipher( std::string & str )
{
	adjust_str(str);
	std::string str1;

	unsigned int size = str.size();
	unsigned int contVallas = 0;
	//usamos contadorx para rstringrir que solo ingrese size veces al programa
	unsigned int contadorx=0;
	for(int i=0 ; i<key ; i++)
		for(int j=0 ; j<size/key ; j++)
			str1 += str[ (((i*(size)+j )*key) + i)%(size)];

	std::string str2;

	int i=(size/key)-1; 
	unsigned int currentPos = i;
	bool sum = true;
	
	int vueltas = 0;
	//lo demas es muy parecido al key generator solo varia key por size/key
	for(int it = 0 ; vueltas < (key/2) ; it=it+2)
	{
		for(int j=0 ; j<4 ; j++)
		{
			if( Useful::isEven(j) )
				for( int k=0 ; k<key-1-it  && contadorx < size; k++ )
				{
					str2 += str1[currentPos];
					currentPos = sum ? currentPos + (size/key) : currentPos - (size/key) ; 
					contadorx++;
				}
			else
				for( int k=0 ; k <(size/key)-1-it && contadorx < size; k++ )
				{
					str2 += str1[currentPos];
					currentPos = sum ? (k==(size/key)-1-it-1 ? currentPos+(size/key) :currentPos+1) : currentPos-1 ;
					contadorx++;
				}
			sum = (j==0 || j==1) ? false : true;  
		}
		vueltas++;
	}
	
	//usamos el buen conocido key cuando es impar y mejor al size/key
	if( ! Useful::isEven(key) )
		for(int j=0 ;  j<((size/key)/2) && contadorx<size; j++)
		{
			str2 += str1[currentPos];
			currentPos--;
			contadorx++;
		}

	str = str2;
};


void Transmitter::affinne_cipher( std::string & str , u_int A , u_int B)
{
	for(int i=0 ; i<str.size() ; i++)
		str[i] = alphabet[ Useful::mod( alphabet.find(str[i]) * A + B , alphabet.size() )];
}

Transmitter::~Transmitter(){};