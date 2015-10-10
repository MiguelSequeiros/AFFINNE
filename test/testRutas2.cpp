#include <iostream>
#include <string>
#include "Useful.h"

int key;

void adjust_str(std::string & str)
{
	const int adj = key-Useful::mod(str.size(),key);

	for(int i=0 ; i < adj ; i++)
		str+="x";
}

int main(int argc, char const *argv[])
{

	std::string str("abcdefghijklmnopqrstuvwxyzabcd");
	key = 5;

	//adjust_str(str);

	std::string str1;

	u_int size = str.size();
	u_int contVallas = 0;

	for(int i=0 ; i<key ; i++)
		for(int j=0 ; j<size/key ; j++)
			str1 += str[ (((i*(size)+j )*key) + i)%(size)];


	std::cout << str1 << std::endl;

	std::string str2;

		int i=(size/key)-1; 

		u_int last = i ;
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

						str2 += str1[currentPos];

						currentPos = sum ? currentPos + (size/key) : currentPos - (size/key) ; 
					}
				}
				else
				{
					for( int k=0 ; k <(size/key)-1-it ; k++ )
					{
						//std::cout << currentPos << std::endl;
						std::cout << str1[currentPos] ;

						str2 += str1[currentPos];

						if(i == key-1)
							currentPos = sum ? (k==key-1-it -1 ? currentPos+size :currentPos+1) : currentPos-1 ;

						else
						{
							//std::cout << "He entrado aqui" << std::endl;
							currentPos = sum ? currentPos+size  currentPos+1 ) : currentPos-1;
						}

					}
				}
				sum = (j==0 || j==1) ? false : true;  
				std::cout << std::endl;
			}
			vueltas++;
		}
		//std::cout << currentPos << std::endl;

/*		if( ! Useful::isEven(key))
		{
			for(int j=0 ; i==key-1 ? j<1 : j<key-1 ; j++)
			{
				str2 += str1[currentPos];

				std::cout << str1[currentPos--];
			}
		}

		str1[i] = tmp;

		std::cout << "=======================================" << std::endl;
*/
	

	std::cout << str2 << std::endl;

	/* code */
	return 0;
}