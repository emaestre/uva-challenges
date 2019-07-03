#include <iostream>
#include <locale>
#include <vector>
#include <cstdio>

#define INT_MAX 60

using std::cin;
using std::cout;
using std::locale;
using std::isupper;
using std::tolower;
using std::vector;
using std::endl;

int waldorf(int i, int j, int x, int y, char matriz[INT_MAX][INT_MAX], vector<char> cadena)
{
	int band = 0;
	
	if(cadena[1] == matriz[i][j + 1])
	{	
		int var1 = i, var2 = j, cont = 0;
		for(int ii = 0; ii < cadena.size(); ii++)
		{
			if(cadena[ii] == matriz[var1][var2])
				cont++;
			var2++;
		}
		if(cont == cadena.size())
			band = 1;
	}
	if(cadena[1] == matriz[i][j - 1] and band == 0)
	{
		int var1 = i, var2 = j, cont = 0;
		for(int ii = 0; ii < cadena.size(); ii++)
		{
			if(cadena[ii] == matriz[var1][var2])
				cont++;
			var2--;
		}
		if(cont == cadena.size())
			band = 1;
	}
	if(cadena[1] == matriz[i + 1][j] and band == 0)
	{
		int var1 = i, var2 = j, cont = 0;
		for(int ii = 0; ii < cadena.size(); ii++)
		{
			if(cadena[ii] == matriz[var1][var2])
				cont++;
			var1++;
		}
		if(cont == cadena.size())
			band = 1;
	}
	if(cadena[1] == matriz[i - 1][j] and band == 0)
	{
		int var1 = i, var2 = j, cont = 0;
		for(int ii = 0; ii < cadena.size(); ii++)
		{
			if(cadena[ii] == matriz[var1][var2])
				cont++;
			var1--;
		}
		if(cont == cadena.size())
			band = 1;
	}
	if(cadena[1] == matriz[i + 1][j + 1] and band == 0)
	{
		int var1 = i, var2 = j, cont = 0;
		for(int ii = 0; ii < cadena.size(); ii++)
		{
			if(cadena[ii] == matriz[var1][var2])
				cont++;
			var1++;
			var2++;
		}
		if(cont == cadena.size())
			band = 1;
	}
	if(cadena[1] == matriz[i + 1][j - 1] and band == 0)
	{
		int var1 = i, var2 = j, cont = 0;
		for(int ii = 0; ii < cadena.size(); ii++)
		{
			if(cadena[ii] == matriz[var1][var2])
				cont++;
			var1++;
			var2--;
		}
		if(cont == cadena.size())
			band = 1;
	}
	if(cadena[1] == matriz[i - 1][j + 1] and band == 0)
	{
		int var1 = i, var2 = j, cont = 0;
		for(int ii = 0; ii < cadena.size(); ii++)
		{
			if(cadena[ii] == matriz[var1][var2])
				cont++;
			var1--;
			var2++;
		}
		if(cont == cadena.size())
			band = 1;
	}
	if(cadena[1] == matriz[i - 1][j - 1] and band == 0)
	{
		int var1 = i, var2 = j, cont = 0;
		for(int ii = 0; ii < cadena.size(); ii++)
		{
			if(cadena[ii] == matriz[var1][var2])
				cont++;
			var1--;
			var2--;
		}
		if(cont == cadena.size())
			band = 1;
	}
	
	return band;
}

int main(void)
{
	char matriz[INT_MAX][INT_MAX];
	locale loc;
	int casos, m, x, y;
	char a;
	
	cin >> casos;
	while(casos > 0)
	{
		cin >> x >> y;
		int xx = 0, yy = 0;
		
		while(xx != x)
		{
			while(yy != y)
			{
				cin >> a;
				if(isupper(a,loc)) 
					a = tolower(a,loc);
				
				matriz[xx][yy] = a;
				yy++;
			}
			yy = 0;
			xx++;
		}
		scanf("%d ", &m);
		while(m > 0)
		{
			vector<char> cadena;
			char nombres;
			int band = 0, find = 1;
			while(scanf("%c" , &nombres) and nombres != '\n')
			{
				if(isupper(nombres,loc)) 
					nombres = tolower(nombres,loc);
				
				cadena.push_back(nombres);
			}
			for(int i = 0; i < x and find; i++)
			{
				for(int j = 0; j < y and find; j++)
				{
					if(cadena[0] == matriz[i][j])
					{
						if(cadena.size() == 1)
						{
							find = 0;
							//cout << i + 1 << " " << j + 1 << endl;
							printf("%d %d\n", i + 1, j + 1);	
						}
						else
						{
							band = waldorf(i, j, x, y, matriz, cadena);
							if(band == 1)
							{
								find = 0;
								//cout << i + 1 << " " << j + 1 << endl;
								printf("%d %d\n", i + 1, j + 1);
							}
						}
					}
				}
			}
			m--;
		} 
		casos--;
		if(casos != 0)
			cout << endl;
	}
	
	return 0; 
}