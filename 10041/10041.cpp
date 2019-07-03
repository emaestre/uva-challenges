#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

int main(void)
{
	int cases, relatives, streets, pos_median, ary, arx;
	
	scanf("%d\n", &cases);
	while(cases > 0)
	{
		scanf("%d ", &relatives);
		vector<int> array;
		int median = 0;
		
		for(int i = 0; i < relatives; i++)
		{	
			scanf("%d ", &streets);
			array.push_back(streets);
		}
		
		sort(array.begin(), array.end());
		
		if(relatives == 1)
			printf("0\n");
		else if(relatives == 2)
		{	
			median = array[1] - array[0];
			printf("%d\n", median);
		}
		else
		{
			pos_median = relatives / 2;
			for(int i = 0; i < pos_median; i++)
			{
				ary = array[i];
				arx = array[pos_median];
				median = median + (arx - ary);
			}
			for(int i = relatives - 1; i > pos_median; i--)
			{	
				ary = array[i];
				arx = array[pos_median];
				median = median + (ary - arx);
			}
			printf("%d\n", median);	
		}

		cases--;
	}
	return 0;
}
