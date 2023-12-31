#include <cstdio>
#include <algorithm> 
#include <ctime>
#include <cmath>

using namespace std;

void merge(float array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new float[subArrayOne], *rightArray = new float[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
		{
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
	{
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    
    while (indexOfSubArrayTwo < subArrayTwo)
	{
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

float mergeSort(float array[], int const begin, int const end)
{
	clock_t time_req;
	time_req = clock();
	
    if (begin >= end)
    {
    	return 0;
    }
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
    
    time_req = clock()- time_req;
	return (float)time_req/CLOCKS_PER_SEC;
}
