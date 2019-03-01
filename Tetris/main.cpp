#include <stdio.h>
#include <string.h>
#include <vector>
#include<iostream>
using std::cout;
    struct pessoa {
    int pontos;
	char nome[17];
	}jogadores[1000] ;
typedef struct pessoa pessoa ;


void merge(pessoa vet[], int p, int q, int r) 
{ 
    int i =0, j =0, k =p; 
    int n1 = q - p + 1; 
    int n2 =  r - q; 

    pessoa L[n1];
	pessoa R[n2]; 
    for (i = 0; i < n1; i++){
		L[i] = vet[p + i]; 
	}
    for (j = 0; j < n2; j++){ 
		R[j] = vet[q + 1+ j];
	} 
    i =0; j = 0;  k = p;  
    while (i < n1 && j < n2) 
    { 
        if (L[i].pontos > R[j].pontos) 
        { 
            vet[k] = L[i]; 
            i++; 
        }
		else if(L[i].pontos == R[j].pontos)
		{
			
			if(strcmp(L[i].nome,R[j].nome)>0)
				{
				vet[k] = R[j];
				j++;
				}
			else{
				vet[k] = L[i]; 
				i++;
				}
		}		
		else{
			
            vet[k] = R[j]; 
            j++; 
			} 
        k++; 
    } 
	while (j < n2) 
    { 
        vet[k] = R[j]; 
        j++; 
        k++; 
    }
  while (i < n1) 
    { 
        vet[k] = L[i]; 
        i++; 
        k++; 
    } 
} 
void mergeSort(pessoa arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = ((r-l)/2) + l; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 
int main() {

    int i,j,maior,menor,total,qtd,valor,testes,aaaaaa,classificacao;
	char nome[16];
    testes = 1;
while (scanf("%d", &qtd) == 1 && qtd > 0){
    for(i = 0; i < qtd; i++){
		scanf("%s", jogadores[i].nome);
		//std::getline (std::cin,nome);
		menor = 99999;
		maior = 0;
		total = 0;
        for(j = 0; j < 12; j++){
            scanf("%d", &valor);
            if(valor < menor){
                menor = valor;
            }
            if(valor > maior){
                maior = valor;
            }
			total = total + valor;
			jogadores[i].pontos = total - menor - maior;
		}
    }
	mergeSort(jogadores,0,qtd-1);
	aaaaaa = 999999; // =valor q n vai ser usado
	  cout<<"Teste "<<testes<<"\n";
	  testes++;
      for (i = 0; i < qtd; i++)
	{
	  if (jogadores[i].pontos != aaaaaa)
	    classificacao = i + 1;
		cout<<classificacao<<" "<<jogadores[i].pontos<<" "<<jogadores[i].nome<<"\n";
		aaaaaa = jogadores[i].pontos;
	}
      cout<<"\n";
    }
return 0;
}
