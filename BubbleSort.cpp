#include <cstdio>
#include <algorithm> 
#include <ctime>
#include <cmath>

using namespace std;

float bubbleSort(float arr[], int n)
{
	int i, j;
	clock_t time_req;
	time_req = clock();
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	time_req = clock()- time_req;
	return (float)time_req/CLOCKS_PER_SEC;
}

