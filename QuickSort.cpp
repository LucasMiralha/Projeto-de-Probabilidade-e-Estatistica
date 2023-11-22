#include <cstdio>
#include <algorithm> 
#include <ctime>
#include <cmath>

using namespace std;

int partition(float arr[], int low, int high)
{
    float pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
	{
        if (arr[j] < pivot)
		{
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

float quickSort(float arr[], int low, int high)
{
	clock_t time_req;
	time_req = clock();
	
    if (low < high)
	{
        float pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    
    time_req = clock()- time_req;
	return (float)time_req/CLOCKS_PER_SEC;
}
