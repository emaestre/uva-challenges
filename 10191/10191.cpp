#include <cstdio>
#include <iostream>
#include <string>

using std::cin;
using std::getline;
using std::string;

typedef struct 
{
	int minutos_t1;
	int minutos_t2;	
} Hora;

void BubbleSort(Hora array[], int size, int index)
{ 
	Hora swap; 
    for (int c = 0 ; c < size - 1; c++)
    {
    	for (int d = 0 ; d < size - c - 1; d++)
    	{
    		if(array[d].minutos_t1 > array[d + 1].minutos_t2) 
    		{
				swap = array[d];
    			array[d] = array[d + 1];
    			array[d + 1] = swap;
    		}
    	}
    }

    printf("Day sorted #%d\n", index);
    for (int i = 0; i < size; i++)
    	printf("%d:%d %d:%d\n", array[i].minutos_t1 % 60, array[i].minutos_t1 / 60, array[i].minutos_t2 % 60, array[i].minutos_t2 / 60);
    printf("\n");
}

int main(void)
{
	int cases, i, j, x, y, index = 1;
	char c;
	
	while(scanf("%d\n", &cases) == 1)
	{
		int size = cases;
		Hora array[cases + 2], hora_inicio, hora_fin;
		hora_inicio.minutos_t1 = hora_inicio.minutos_t2 = 10 * 60;
		hora_fin.minutos_t1 = hora_fin.minutos_t2 = 18 * 60;
		array[0] = hora_inicio;
		array[size + 1] = hora_fin;
		int m = 1;
		while(cases > 0)
		{
			string cad1;
			Hora test;
			scanf("%d:%d %d:%d ", &i, &j, &x, &y);
			getline(cin, cad1, '\n');
			
			test.minutos_t1 = (i * 60) + j;
			test.minutos_t2 = (x * 60) + y;
			array[m] = test;
			m++;
			cases--;
		}

		BubbleSort(array, size + 2, index);
		
		int min = 0, dif = 0, res1, res2;
		if(size == 1)
		{
			if(array[1].minutos_t1 - array[0].minutos_t2 > array[size + 1].minutos_t1 - array[size].minutos_t2)
				if(array[1].minutos_t1 - array[0].minutos_t2 < 60)
					printf("Day #%d: the longest nap starts at %d:0%d and will last for %d minutes.\n", index, array[0].minutos_t1 % 60, array[0].minutos_t1 / 60, array[1].minutos_t1 - array[0].minutos_t2);
				else
					printf("Day #%d: the longest nap starts at %d:0%d and will last for %d hours and %d minutes.\n", index, array[0].minutos_t1 % 60, array[0].minutos_t1 / 60, array[1].minutos_t1 - array[0].minutos_t2 % 60, array[1].minutos_t1 - array[0].minutos_t2 / 60);			
			else
				if(hora_fin.minutos_t1 - array[size - 1].minutos_t2 < 60)
					printf("Day #%d: the longest nap starts at %d:0%d and will last for %d minutes.\n", index, array[size - 1].hora2, array[size - 1].minuto2, hora_fin.minutos_t1 - array[size - 1].minutos_t2);
				else
					printf("Day #%d: the longest nap starts at %d:0%d and will last for %d hours and %d minutes.\n", index, array[size - 1].hora2, array[size - 1].minuto2, (hora_fin.minutos_t1 - array[size - 1].minutos_t2)/60, (hora_fin.minutos_t1 - array[size - 1].minutos_t2)%60);
		}	
		else
		{
			int band;
			for(int i = 0; i < size - 1; i++)
			{	
				band = 1;
				for(int j = i + 1; j < size and band; j++)
				{
					if(array[j].hora1 > array[i].hora2)
					{
						dif = array[j].minutos_t1 - array[i].minutos_t2;
						if(min < dif)
						{
							min = dif;
							res1 = array[i].hora2;
							res2 = array[i].minuto2; 
						}
						band = 0;
					}
				}
			}
			
			if(min < array[0].minutos_t1 - hora_inicio.minutos_t2)
			{	
				min = array[0].minutos_t1 - hora_inicio.minutos_t2;
				if(min < hora_fin.minutos_t1 - array[size - 1].minutos_t2)
				{
					if(array[size - 1].minuto2 < 10)
					{	
						if(hora_fin.minutos_t1 - array[size - 1].minutos_t2 < 60)
							printf("Day #%d: the longest nap starts at %d:0%d and will last for %d minutes.\n", index, array[size - 1].hora2, array[size - 1].minuto2, hora_fin.minutos_t1 - array[size - 1].minutos_t2);
						else
							printf("Day #%d: the longest nap starts at %d:0%d and will last for %d hours and %d minutes.\n", index, array[size - 1].hora2, array[size - 1].minuto2, (hora_fin.minutos_t1 - array[size - 1].minutos_t2)/60, (hora_fin.minutos_t1 - array[size - 1].minutos_t2)%60);
					}
					else
					{
						if(hora_fin.minutos_t1 - array[size - 1].minutos_t2 < 60)
							printf("Day #%d: the longest nap starts at %d:%d and will last for %d minutes.\n", index, array[size - 1].hora2, array[size - 1].minuto2, hora_fin.minutos_t1 - array[size - 1].minutos_t2);
						else
							printf("Day #%d: the longest nap starts at %d:%d and will last for %d hours and %d minutes.\n", index, array[size - 1].hora2, array[size - 1].minuto2, (hora_fin.minutos_t1 - array[size - 1].minutos_t2)/60, (hora_fin.minutos_t1 - array[size - 1].minutos_t2)%60);
					}
				}
				else
				{
					if(array[0].minutos_t1 - hora_inicio.minutos_t2 < 60)
						printf("Day #%d: the longest nap starts at %d:0%d and will last for %d minutes.\n", index, hora_inicio.hora2, hora_inicio.minuto2, array[0].minutos_t1 - hora_inicio.minutos_t2); 
					else
						printf("Day #%d: the longest nap starts at %d:0%d and will last for %d hours and %d minutes.\n", index, hora_inicio.hora2, hora_inicio.minuto2, (array[0].minutos_t1 - hora_inicio.minutos_t2)/60, (array[0].minutos_t1 - hora_inicio.minutos_t2)%60);
				}
			}
			else if(min < hora_fin.minutos_t1 - array[size - 1].minutos_t2)
			{
				if(array[size - 1].minuto2 < 10)
				{	
					if(hora_fin.minutos_t1 - array[size - 1].minutos_t2 < 60)
						printf("Day #%d: the longest nap starts at %d:0%d and will last for %d minutes.\n", index, array[size - 1].hora2, array[size - 1].minuto2, hora_fin.minutos_t1 - array[size - 1].minutos_t2);
					else
						printf("Day #%d: the longest nap starts at %d:0%d and will last for %d hours and %d minutes.\n", index, array[size - 1].hora2, array[size - 1].minuto2, (hora_fin.minutos_t1 - array[size - 1].minutos_t2)/60, (hora_fin.minutos_t1 - array[size - 1].minutos_t2)%60);
				}
				else
				{
					if(hora_fin.minutos_t1 - array[size - 1].minutos_t2 < 60)
						printf("Day #%d: the longest nap starts at %d:%d and will last for %d minutes.\n", index, array[size - 1].hora2, array[size - 1].minuto2, hora_fin.minutos_t1 - array[size - 1].minutos_t2);
					else
						printf("Day #%d: the longest nap starts at %d:%d and will last for %d hours and %d minutes.\n", index, array[size - 1].hora2, array[size - 1].minuto2, (hora_fin.minutos_t1 - array[size - 1].minutos_t2)/60, (hora_fin.minutos_t1 - array[size - 1].minutos_t2)%60);
				}
			}
			else
			{
				if(res2 < 10)
					if(min < 60)
						printf("Day #%d: the longest nap starts at %d:0%d and will last for %d minutes.\n", index, res1, res2, min);
					else
						printf("Day #%d: the longest nap starts at %d:0%d and will last for %d hours and %d minutes.\n", index, res1, res2, min/60, min%60);
				else
					if(min < 60)
						printf("Day #%d: the longest nap starts at %d:%d and will last for %d minutes.\n", index, res1, res2, min);
					else
						printf("Day #%d: the longest nap starts at %d:%d and will last for %d hours and %d minutes.\n", index, res1, res2, min/60, min%60);
			}	
		}
		index++;
	}
	return 0;
}
