#include <iostream>
#include <string>
#include <utility>


#include "Useful.h"


bool isEven(int n)
{
	if(n&1 == 1)
		return false;
	return true;
}


int main()
{
	std::string alphabet("ABCDEFGHIJKLMN0PQRSTUVXYZ");
	std::string str("ABCDEFGHIJKlsaqw1212");
	std::string str1;
	u_int key = 5;

	u_int size = str.size();
	u_int contVallas = 0;

	for(int i=0 ; i<key ; i++)
		for(int j=0 ; j<size ; j++)
			str1 += str[(((i*size+j )*key) + i)%size];



	std::cout << std::endl;
	for(int i=0 ; i<key ; i++)
	{
		std::cout << "	";	
		for(int j=0 ; j<size ; j++)
		{
			std::cout << str1[i*size+j] << " ";
			if(i*size+j == i*size + key-1 || i*size+j == i*size + (key-1) + 2*key-2 )
				std::cout << "| ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;


	/*for( int i=key-1 ; i<size ; i=i+2*key-2 )
	{
		std::cout << str[i] << "  con  " << str1[size*(key-1)+i] << std::endl;
		contVallas++;
	}

	std::cout << "=======================================" << std::endl;

	for( int i=key-1 ; i<size ; i=i+2*key-2 )
	{
		for(int j=1 ; i==key-1 ? (j<key && i-j<size):(j<key-1 && i-j<size-1) ; j++)
		{
			std::cout << str[i-j] << "  con  " << str1[size*(key-1-j)+i-j] << std::endl;
			contVallas++;
		}

	std::cout << "=======================================" << std::endl;

		for(int j=1 ; j<key && i+j<size; j++)
		{
			std::cout << str[i+j] << "  con  " << str1[size*(key-1-j)+i+j] << std::endl;
			contVallas++;
		}

	std::cout << "=======================================" << std::endl;
	}

	if(contVallas<size)
	{
		u_int aux = size-contVallas;
		for(int i=size-1 ; i>=contVallas ; i--)
		{
			std::cout << str[i] << "  con  " << str1[aux*size+i] << std::endl;
			aux--;
		}
	}

	*/
	u_int last = 0;
	for( int i=key-1 ; i<size ; i+=2*key-2 )
	{
		last = i ;
		u_int currentPos = i;
		bool sum = true;
		char tmp;
		int vueltas = 0;

		for(int it = 0 ; vueltas < key/2 ; it=it+2)
		{
			for(int j=0 ; j<4 ; j++)
			{
				if( Useful::isEven(j) )
				{
					for( int k=0 ; k<key-1-it ; k++ )
					{
						//std::cout << currentPos << std::endl;
						std::cout << str1[currentPos] ;

						std::swap(tmp,str1[currentPos]);

						currentPos = sum ? currentPos + size : currentPos - size ; 
					}
				}
				else
				{
					for( int k=0 ; (i == key-1) ? (k<key-1-it) : (k<2*key-2-it -1) ; k++ )
					{
						//std::cout << currentPos << std::endl;
						std::cout << str1[currentPos] ;

						std::swap(tmp,str1[currentPos]);

						if(i == key-1)
							currentPos = sum ? (k==key-1-it -1 ? currentPos+size :currentPos+1) : currentPos-1 ;

						else
						{
							//std::cout << "He entrado aqui" << std::endl;
							currentPos = sum ? (( k==2*key-2-it-1 -1 ) ? currentPos+size : currentPos+1 ) : currentPos-1;
						}

					}
				}
				sum = (j==0 || j==1) ? false : true;  
				std::cout << std::endl;
			}
			vueltas++;
		}
		//std::cout << currentPos << std::endl;

		if( ! Useful::isEven(key))
		{
			for(int j=0 ; i==key-1 ? j<1 : j<key-1 ; j++)
			{
				std::swap(tmp,str1[currentPos]);

				std::cout << str1[currentPos--];
			}
		}

		str1[i] = tmp;

		std::cout << "=======================================" << std::endl;

	}



	std::cout << std::endl;
	for(int i=0 ; i<key ; i++)
	{
		std::cout << "	";	
		for(int j=0 ; j<size ; j++)
		{
			std::cout << str1[i*size+j] << " ";
			if(i*size+j == i*size + key-1 || i*size+j == i*size + (key-1) + 2*key-2 )
				std::cout << "| ";
		}
		std::cout << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////

	//std::cout << last << std::endl;

	if(last != size-1)
	{
		int i = size-1 ;
		u_int currentPos = i;
		bool sum = true;

		char tmp;

		int vueltas = 0;
		int numAux= size-last-1;
		isEven(numAux)?(numAux==0? numAux=1:numAux=numAux/2):(numAux=(numAux/2)+1);
		int contadorx = 0;
		int total = (size-last-1)*key;

		for(int it = 0 ; vueltas < numAux && contadorx < total ; it=it+2)
		{
			for(int j=0 ; j<4 && contadorx < total ; j++)
			{
				if( Useful::isEven(j) )
				{
					for( int k=0 ; k<key-1-it && contadorx < total ; k++ )
					{
						std::swap(tmp,str1[currentPos]);
						currentPos = sum ? currentPos + size : currentPos - size ; 
						contadorx++;
					}
				}
				else
				{
					for( int k=0 ; k<size-1-last-1-it && contadorx < total ; k++ )
					{
						std::swap(tmp,str1[currentPos]);
						currentPos = sum ? (( k==size-1-last -1-1-it ) ? currentPos+size : currentPos+1 ) : currentPos-1;
						contadorx++;
					}
				}
				sum = (j==0 || j==1) ? false : true;  
			}
			vueltas++;
		}

		if( ! Useful::isEven(key))
		{
			for(int j=0 ;  j<size-last && contadorx < total ; j++)
			{
				std::swap(tmp,str1[currentPos]);
				currentPos--;
				contadorx++;
			}
		}

		std::swap(tmp,str1[i]);
	}

	
	std::cout << std::endl;
	for(int i=0 ; i<key ; i++)
	{
		std::cout << "	";	
		for(int j=0 ; j<size ; j++)
		{
			std::cout << str1[i*size+j] << " ";
			if(i*size+j == i*size + key-1 || i*size+j == i*size + (key-1) + 2*key-2 )
				std::cout << "| ";
		}
		std::cout << std::endl;
	}
	//std::cout << strMatriz << std::endl;
	return 0;
}