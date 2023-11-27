#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "BubbleSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"

using namespace std;

int main()
{
	vector<float> dados;
	ifstream nums;
	//nomes dos arquivos e seus dados
	//num10k = 10 mil numeros float com 2 casas decimais aleatorios entre 0 e 1
	//num100k = 100 mil numeros float com 2 casas decimais aleatorios entre 0 e 1
	//num1kk = 1 milhao de numeros float com 2 casas decimais aleatorios entre 0 e 1
	nums.open("num100k.txt", ios::in);
	
	cout << "Processo de leitura iniciado." << endl;
	
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
	
	cout << "Processo de leitura finalizado." << endl << endl;
	
	//Criacao ou adicao dos resultados em um arquivo .csv
	ofstream results;
	results.open("Resultados_100k_intel5_11400H_16GBRAM.csv", ios::out | ios::app);
	
	//O bubbleSort e executado uma unica vez para fazer uma previa de tempo 
	//necessario para rodar todas as iteracoes de teste
	int ntimer = dados.size();
	float arrtimer[ntimer];
		
	cout << "Fazendo calculos de tempo..." << endl;
		
	for (int i = 0; i < ntimer; i++) 
	{
		arrtimer[i] = dados[i];
	}
	
	//Quantidade de vezes que os testes irao ocorrer
	//Recomendado 10000 para num10k para baixo
	//Recomendado 1000 para num100k para cima
	int iterations = 1000;
	//Variaveis para medir o tempo de teste total
	float tempo_unico = bubbleSort(arrtimer, ntimer);
	float tempo_esperado = tempo_unico*iterations;
	string medida_tempo;
	if(tempo_esperado < 60)
	{
		medida_tempo = "segundos";
	}
	else if(tempo_esperado > 60 && tempo_esperado < 3600)
	{
		tempo_esperado = tempo_esperado/60;
		medida_tempo = "minutos";
	}
	else
	{
		tempo_esperado = tempo_esperado/3600;
		medida_tempo = "horas";
	}
	
	//Criando Header do arquivo csv
	results << "BubbleSort" << ", " << "QuickSort" << ", " << "MergeSort" << "\n";
	
	for (int i = 0; i < iterations; i++) 
	{
		system("cls");
		cout << "Iteracoes total: " << iterations << endl;
		cout << "Iteracao atual : " << i+1 << endl;
		cout << "Tempo estimado de cada iteracao: " << tempo_unico << endl;
		cout << "Tempo esperado para conclusao  : " << tempo_esperado << " " << medida_tempo << endl;
		//Coleta da quantidade de valores do arquivo
		int n = dados.size();
		//Criacao dos arrays que vao armazenar os numeros do arquivo
		//Isso e feito para poder usa-los nos algoritmos de sort
		//Esse processo e repetido toda iteracao para manter a desordem
		float arr[n], arr1[n], arr2[n];
		
		for (int j = 0; j < n; j++) 
		{
			//Passando o vector para 3 arrays diferentes
			//Sao usados 3 arrays iguais para manter a mesma
			//desordem em todos os algoritmos de sort
			arr[j] = dados[j];
		    	arr1[j] = dados[j];
			arr2[j] = dados[j];
	    	}
		//Armazenamento de todos os dados no csv
		results << bubbleSort(arr, n) << ", " << quickSort(arr1, 0, n-1) << ", " << mergeSort(arr2, 0, n-1) << "\n";
   	}

	return 0;
}
