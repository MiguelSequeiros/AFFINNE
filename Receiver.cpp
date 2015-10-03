#include "Receiver.h"
#include "Useful.h"

Receiver::Receiver(int key , std::string alphabet)
{
	this -> key = key;
	this -> alphabet = alphabet;
};

void Receiver::cesar_decipher ( std::string & str )
{
	for( int i=0 ; i < str.size() ; i++ )
		str[i] = alphabet[ Useful::mod( int(alphabet.find( str[i] )) - key , alphabet.size() ) ];
};

void Receiver::reverse_decipher( std::string & str )
{
	for( int i=0 ; i<str.size() ; i++ )
		str[i] = alphabet[ alphabet.size() - int(alphabet.find( str[i] )) - 1 ];
};

void Receiver::rcesar_decipher( std::string & str )
{
	cesar_decipher(str);
	reverse_decipher(str);
};

void Receiver::adjust_limiters( int n , int *limiters )
{
	for(int i=1 ; i<n ;i++)
		limiters[i]++;
}

void Receiver::rail_decipher( std::string & str )
{

	//std::cout << "DESCIFRANDO" << std::endl;

	int seg = str.size()/(key-1);
	int rest = Useful::mod(str.size(),key-1);

	//std::cout << "resto : " << rest << std::endl;
	//std::cout << "seg : " << seg << std::endl;

	int * limiters = new int[key];

	if(Useful::isEven(seg))
	{
		limiters[1] = seg/2 + (rest!=0?1:0);

		for(int i=2 ; i<key ; i++)
			limiters[i] = limiters[i-1] + seg ;

		int c=1;
		for(int i=2 ; i<key && rest>1 && c<rest; i++)
			limiters[i]+=c;
	}
	else
	{
		limiters[1] = seg/2 + 1;
		for(int i=2 ; i<key ; i++)
			limiters[i] = limiters[i-1] + seg;

		for(int i=1 ; i<rest ; i++)
			limiters[key-i]++;
	}


	for(int i=0 ; i<key ; i++)
		std::cout << limiters[i] << std::endl;

	bool toRight = true;

	int cont=str.size();

	while(cont > 1)
	{
		if(toRight)
			for(int j=0 ; j<key-1 && cont > 1; j++)
			{	
				char tmp = str[limiters[j]];
				//std::cout << "To right : " << limiters[j] << " -> " << tmp << std::endl;
				str.erase(str.begin()+limiters[j]);
				str.insert(str.begin()+limiters[0],tmp);
				if(j!=0)
					limiters[0]++;
				limiters[j]++;
				adjust_limiters(j,limiters);
				cont--;
			}

		else
			for(int j=key-1 ; j>0 && cont > 1; j--)
			{
				char tmp = str[limiters[j]];
				//std::cout << "To left : " << limiters[j] << " -> " << tmp << std::endl;
				str.erase(str.begin()+limiters[j]);
				str.insert(str.begin()+limiters[0],tmp);
				limiters[0]++;
				limiters[j]++;
				adjust_limiters(j,limiters);
				cont--;
			}
	
		toRight = not toRight;

	}
	delete [] limiters;
};

void Receiver::route_decipher( std::string & str )
{
	std::string * matriz = new std::string[key];

	for(int i=0 ; i<key ; i++)
		matriz[i].append((str.size()/key) , ' ');

	bool sum = true;

	u_int it_y = key - 1;
	u_int it_x = str.size()/key - 1;

	u_int currentPos = 0;

	for(int i=0 ; i<key/2 ; i++)
	{
		for(int j=0 ; j<4 ; j++)
		{
			for(int k=0 ; Useful::isEven(j)?k<it_y:k<it_x ; k++)	
			{
				if(j==0)
					matriz[0][it_x] = str[currentPos++];
			}
		}
		it_x-=2;
		it_y-=2;
		
	}


};

void Receiver::affinne_decipher( std::string & str , int A_i , int B )
{
	for(int i=0 ; i<str.size() ; i++)
		str[i] = alphabet[ Useful::mod( (alphabet.find(str[i]) - B)*A_i, alphabet.size() )];
};

Receiver::~Receiver() {};