#include <stdio.h>
#include <string.h>
#include <vector>
#include<iostream>
using std::cout;


    struct pessoa {
    int pontos;
	char nome[16];
	}jogadores[1000] ;
typedef struct pessoa pessoa ;

using namespace std;
void ordenaalfabetico(pessoa vet[], int tamanho)
{
	int i,m;
	int aaa=0;
	pessoa aux[tamanho-1];
	pessoa lixo;
	pessoa sentinela;
	for(i=0;i<16;i++){
		lixo.nome[i] = 'z';
		}
	sentinela.pontos = 0;
	lixo.pontos = 0;
	m = 0;
	while(m<tamanho){
		for(i=0;i<16;i++){
		sentinela.nome[i] = 'z';
		}
	sentinela.pontos = 0;
	for(i=0;i<tamanho;i++)
	{
		if(vet[i].pontos > sentinela.pontos){
			if(strcmp(sentinela.nome,vet[i].nome)>0){
				sentinela.pontos = vet[i].pontos;
				for(aaa=0;aaa<16;aaa++){
				sentinela.nome[aaa] = vet[i].nome[aaa];
				}
			}
		}
	}
//	for(i=0;i<tamanho;i++)
//	{
//		if(vet[i].pontos == maior){
//			if(strcmp(sentinela.nome,vet[i].nome)>0){
//				sentinela.pontos = maior;
//				for(aaa=0;aaa<16;aaa++){
//				sentinela.nome[aaa] = vet[i].nome[aaa];
//				}
//			}
//		}
//	}
	for(i=0;i<tamanho;i++)
	{
		if((vet[i].pontos==sentinela.pontos) && (strcmp(vet[i].nome,sentinela.nome)==0)){
			aux[m].pontos = vet[i].pontos;
			for(aaa=0;aaa<16;aaa++){
				aux[m].nome[aaa] = vet[i].nome[aaa];
			}
			vet[i].pontos = lixo.pontos;
			for(aaa=0;aaa<16;aaa++){
				vet[i].nome[aaa] = lixo.nome[aaa];
				}
			break;
		}
	}
	m ++;
}
	for(i=0;i<tamanho;i++){
		vet[i] = aux[i];
	}
}


int main() {

    int i,j,maior,menor,total,qtd,valor,testes;
	unsigned int l;
	string nome[16];
    testes = 0;
while (scanf("%d", &qtd) == 1 && qtd > 0){
	testes ++;
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
	ordenaalfabetico(jogadores, qtd);
	cout << "Teste" <<" " << testes;
	int inc = 1;
	int var = 0;
	for(l=0;l<qtd;l++){
	if(l > 0){
		if(jogadores[l].pontos == jogadores[l-1].pontos){
			printf("\n");
			var++;
			cout << inc << " " << jogadores[l].pontos << " " << jogadores[l].nome;
		}
		else{
			inc = inc + var;
			inc++;
		printf("\n");
		cout << inc << " " << jogadores[l].pontos << " " << jogadores[l].nome;
		var = 0;
		}
	}
	else{
		printf("\n");
		cout << inc << " " << jogadores[l].pontos << " " << jogadores[l].nome;
	}
	}
}
return 0;

}