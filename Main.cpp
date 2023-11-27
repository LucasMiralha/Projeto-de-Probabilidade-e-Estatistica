#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include "BubbleSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"

using namespace std;

int main()
{
	vector<float> dados;
	ifstream nums;
	ofstream results;
	//nomes dos arquivos e seus dados
	//num10k = 10 mil numeros float com 2 casas decimais aleatorios entre 0 e 1
	//num100k = 100 mil numeros float com 2 casas decimais aleatorios entre 0 e 1
	//num1kk = 1 milhao de numeros float com 2 casas decimais aleatorios entre 0 e 1
	nums.open("num100k.txt", ios::in);
	
	float x;
	//Leitura de dados do arquivo .txt
	while (1) 
	{       
		//Alocando o numero do arquivo
        	nums >> x;              
		//Se tiver chegado no fim do arquivo ocorre um break antes de 
		//colocar o numero no vector de fato, para nao ocorrer de alocar 
		//um numero nao existente no arquivo dentro do vector
        	if(nums.eof())  
		{        
            		break;                                
	    	}
		//Alimentado o vector com os numeros do arquivo
		dados.push_back(x);
	}
	//Coleta da quantidade de valores do arquivo
	int n = dados.size();
	//Criacao dos arrays que vao armazenar os numeros do arquivo
	//Isso e feito para poder usa-los nos algoritmos de sort
	float arr[n], arr1[n], arr2[n];
	
    	for (int i = 0; i < n; i++) 
	{
		//Passando o vector para 3 arrays diferentes
		//Sao usados 3 arrays iguais para manter a mesma
		//desordem em todos os algoritmos de sort
	        arr[i] = dados[i];
	        arr1[i] = dados[i];
	        arr2[i] = dados[i];
    	}

	//Criacao ou adicao dos resultados em um arquivo .csv
	results.open("Resultados_100k_intel5_11G_16GBRAM.csv", ios::out | ios::app);

	//Criando Header do arquivo csv
	results << "BubbleSort" << ", " << "QuickSort" << ", " << "MergeSort" << "\n";
	int iterations = 10000;
	for (int i = 0; i < iterations; i++) 
	{
		//Armazenamento de todos os dados no csv
		results << bubbleSort(arr, n) << ", " << quickSort(arr1, 0, n-1) << ", " << mergeSort(arr2, 0, n-1) << "\n";
    	}
	
	return 0;
}
