#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "BubbleSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"

//#include <pqxx/pqxx>

using namespace std;

int main()
{
	vector<float> dados;
	ifstream nums;
	ofstream results;
	nums.open("num10k.txt", ios::in);
	
	float x;
	
	while (1) 
	{         
        nums >> x;              
        if(nums.eof())  
		{        
            break;                                
	    }
	    dados.push_back(x);
	}
	
	int n = dados.size();
	float arr[n], arr1[n], arr2[n];
	
    for (int i = 0; i < n; i++) 
	{
        arr[i] = dados[i];
        arr1[i] = dados[i];
        arr2[i] = dados[i];
    }
    
	results.open("Resultados_10k_intel5_11G_16GBRAM.csv", ios::out | ios::app);
	
	int iterations = 10000;
	for (int iterations = 0; iterations < n; iterations++) 
	{
		cout << mergeSort(arr2, 0, n-1) << endl;
		//results << bubbleSort(arr, n) << ", " << quickSort(arr1, 0, n-1) << ", " << mergeSort(arr2, 0, n-1) << "\n";
    }
	
	return 0;
}