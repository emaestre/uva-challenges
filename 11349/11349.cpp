#include <cstdio>

#define INT_MAX 101

int main(void)
{
	long long matriz[INT_MAX][INT_MAX], value;
	int casos, n, cont = 1;
	char N, igual;
	
	scanf("%d ", &casos);
	
	while(casos > 0)
	{
		scanf("%c %c %d ", &N, &igual, &n);
		int xx = 0, yy = 0, band = 1;
	
		while(xx != n)
		{
			while(yy != n)
			{
				scanf("%lld ", &value);
				matriz[xx][yy] = value;
				if(value < 0)
					band = 0;
				yy++;
			}
			yy = 0;
			xx++;
		}

		if(band == 0)
			printf("Test #%d: Non-symmetric.\n", cont);
		else
		{
			for(int i = 0; i < n && band; i++)
			{
				for (int j = 0; j < n && band; j++)
				{
					if(matriz[i][j] != matriz[n - 1 - i][n - 1 - j])
						band = 0;
				}
			}
			if(band == 0)
				printf("Test #%d: Non-symmetric.\n", cont);
			else
				printf("Test #%d: Symmetric.\n", cont);
		}
		casos--;
		cont++;
	}
	return 0; 
}