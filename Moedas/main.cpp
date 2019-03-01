#include <stdio.h>
#include <string.h>
#include <iostream> 
#include <vector> 
#define SENTINEL 999999
using namespace std; 

int main() {
	void mochilarecursiva(int Total, int precos[], int quantidadeMoedas, int moedas[]);
	vector<int> moedaspossiveis;
    int Total, numeroMoedas;
    int i;
    int moedas[100];
    int precos[50000];
	moedaspossiveis.resize(100); 
	memset(precos,SENTINEL,sizeof(precos));
	cin>>Total;
    //enquanto houverem mercadorias gogogoog
    while(Total > 0) {
		cin>>numeroMoedas;
        memset(precos,SENTINEL,sizeof(precos));
//
		for (i = 0; i < numeroMoedas; i++){
        moedaspossiveis.push_back(i); 
		}
//
        for (i = 0; i < numeroMoedas; i++){
			cin>>moedas[i];
			precos[moedas[i]] = 1;
		}
        mochilarecursiva(Total, precos, numeroMoedas, moedas);
        if(precos[Total]>SENTINEL) {
			cout <<"Impossivel"<<endl;

        } else {
			cout<<precos[Total]<<endl;
        }
		cin>>Total;
    }
    
    return 0;
}
//sono

void mochilarecursiva(int Total,int precos[], int quantidadeMoedas, int moedas[]) {
	int  j=0;
	int i = 1;
		while(i <= Total){
			if(precos[i] >SENTINEL ){
						if(i-1<=Total)i++;
						continue;
			}
            for (j = 0; j < quantidadeMoedas; j++){
                if (i + moedas[j] > Total) {
					j++;
                    break;
                }
				//cout<<precos[i + moedas[j]];
				//cout<<precos[i];
                if (precos[i + moedas[j]] >= SENTINEL) {
                    precos[i + moedas[j]] = precos[i] + 1;
                } 
				else {
					if (precos[i + moedas[j]] < precos[i] + 1) {
						precos[i + moedas[j]] = precos[i + moedas[j]];
					}
					else if (precos[i + moedas[j]] > precos[i] + 1){
						precos[i + moedas[j]] = precos[i] + 1;
					}
					else{continue;} 
                }
            }

		if(i-1<=Total){
		i++;
		}
		}
    }