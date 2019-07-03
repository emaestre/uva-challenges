#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>         

using std::bitset;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::abs;

int esta(vector<int> myvector, int n, int &x)
{
	int band = 0;

	for(int i = 0; i < myvector.size(); i++)
	{
		if(myvector[i] == n)
		{
			band = 1;
			x = i;
		}
	}

	return band;
}

int main(void)
{
	int n, a;
	
	while(cin >> n and n > 0 and n <= 3000)
	{
		int x, cont = 0, b, band = 1;
		vector<int> myvector, sol;
		bitset<3000> bits;

		for(int i = 0; i < n; i++)
		{
			cin >> a;
			myvector.push_back(a);
		}

		for(int i = 0; i < n - 1; i++)
			sol.push_back(i + 1);
		
		for(int i = 0; i < n - 1 and band; i++)
		{
			b = esta(sol, abs(myvector[i] - myvector[i + 1]), x);
			if(b == 1)
			{
				if(bits[x] == 0)
				{
					bits.set(x, 1);
					cont++;
				}
			}
			else
				band = 0;
		}
		
		if(band == 0)
			cout << "Not jolly" << endl;
		else if(cont == n - 1)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
		
	}

	return 0;
} 

