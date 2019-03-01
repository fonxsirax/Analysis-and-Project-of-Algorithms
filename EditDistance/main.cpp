#include <stdio.h>
#include <string.h>
 #include <algorithm>
 #include <stdlib.h>
#include <iostream>
 using namespace std;
 
  		char a[2000];
		char b[2000];
		int n = 0;
int editDistance()
{
	int table[strlen(a) + 1][strlen(b) + 1];
	int minimun;
	int aux1 = 0;
	int aux2 = 0;
	int aux3 = 0;
	unsigned int i = 0;
	for (i=0;i<=strlen(a);i++) {
		table[i][0] = i;
	}
	unsigned int j = 0;
	for (j=0;j<=strlen(b);j++) {
		table[0][j] = j;
	}

	for (i=1;i<=strlen(a);i++) {
		for (j = 1; j <= strlen(b); ++j) {
			if (a[i - 1] == b[j - 1]) {
				table[i][j] = table[i - 1][j - 1];
			} else {
				aux1 = min(table[i][j - 1],table[i - 1][j]);
				aux2 = min(table[i][j - 1],table[i - 1][j - 1]);
				minimun = min(aux1,aux2);
				table[i][j] = 1 + minimun;
			}
		}
	}

	aux3 = table[strlen(a)][strlen(b)];
	return aux3;
}

int main()
{
	int T;
	cin>>T;
	while (T >0) {
		scanf("%s", a);
		scanf("%s", b);
		n = editDistance();
		cout<<n<<endl;
		T--;
	}
    return 0;
}