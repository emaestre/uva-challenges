#include <iostream>

using std::cout;
using std::cin;
using std::endl;

long int conjeture(long int n)
{
	long int cont = 0;

	while(n != 1)
	{
		if(n % 2 == 0)
			n = n / 2;
		else
			n = (3 * n) + 1;
		
		cont++;
	}

	return cont + 1;
}

int main(void)
{
	long int i, ii, j, jj, conje, x, aux;

	while(cin >> i >> j and i > 0 and i < 1000000 and j > 0 and j < 1000000)
	{
		long int max = 0;
		ii = i;
		jj = j;

		if(i > j)
		{	
			aux = i;
			i = j;
			j = aux;
		}
	
		for(int x = i; x <= j; x++)
		{
			conje = conjeture(x);
			if(conje > max)
				max = conje;
		}

		cout << ii << " " << jj << " " << max << endl;
	}

	return 0;
}