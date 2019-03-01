#include <stdio.h>
using namespace std;
#include<iostream>
using std::cout;
int main() {
int Merge(int arr[], int p, int q, int r);
int MergeSort(int arr[], int p, int q, int r);
int qtd = 0;
int i,aaaaaaa;
//while (scanf("%d", &qtd) == 1 && qtd > 0){
	scanf("%d",&qtd);
	int vetor[qtd];
    for(i = 0; i < qtd; i++){
		scanf("%d", &vetor[i]);
	}
	aaaaaaa = MergeSort(vetor,0,qtd-1,qtd);
	cout <<aaaaaaa;
return 0;
}
int Merge(int vet[], int p, int r) {
	int k = 0;
	int q = (p+r)/2;
	int R[r+1];
	int i, j, inversoes =0;
	i = p;
	j = q+1;
	while(i <= q && j <= r) {
		if(vet[i] <= vet[j])
			R[k++] = vet[i++];
		
		else {
			R[k++] = vet[j++];
			inversoes += q-i+1;
		}
	}
	while(j <= r){
		R[k] = vet[j];
		k++;
		j++;
	}
	while(i <= q){
		R[k] = vet[i];
		k++;
		i++;
	}
	
	for(int i = 0; i < k; i++) {
		vet[p] = R[i];
		p++;
	}
	return inversoes;
}

int MergeSort(int vet[], int p, int r,int a) {
	if(p >= r){ return 0;}

	int q = (p+r)/2;
	int inversoes = 0;
	inversoes = MergeSort(vet, p, q,q)+ MergeSort(vet, q+1, r,q)+Merge(vet, p, r);
	return inversoes;
}
