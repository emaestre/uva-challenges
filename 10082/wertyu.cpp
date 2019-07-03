#include <iostream>
#include <cstdio>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string teclado = "`1234567890-=QWERTYUIOP[]\\\ASDFGHJKL;'ZXCVBNM,./";
	char a;
	
	while(scanf("%c" ,&a) == 1)
	{
			if(a == ' ')
				cout << " ";
			else if(a == '\n')
				cout << endl;
			else
				cout << teclado[teclado.find_last_of(a) - 1];		
	}
	
	return 0;
}

