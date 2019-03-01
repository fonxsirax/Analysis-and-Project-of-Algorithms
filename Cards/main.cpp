#include <stdio.h>
#include <string.h>
// funciona como um album de cartas, cada a posição do vetor indica a ausencia ou n da carta => 1 ou 0.
// It works like an album of cards, each of them indicates an absence or not of the card => 1 or 0.
int albumalice[100001];
int albumbeatriz[100001];

int main(int argc, char const *argv[])
{
    int alice = 0;
    int beatriz = 0;
    int scan, ali, bea;
    int i, j, k;
    while (scanf("%d %d", &alice, &beatriz) && (alice || beatriz))
    {
        memset(albumalice, 0, sizeof(albumalice));
        memset(albumbeatriz, 0, sizeof(albumbeatriz));

        // a posicao do vetor indica se tem ou n a carta

        for (i = 0; i < alice; ++i)
        {
            scanf("%d", &scan);
            if(albumalice[scan] == 0){
            albumalice[scan] = 1;
            }
        }

        for (j = 0; j < beatriz; ++j)
        {
            scanf("%d", &scan);
            if(albumbeatriz[scan] == 0){
            albumbeatriz[scan] = 1;
          }
        }
      
        ali = 0, bea = 0;
        for (k = 0; k < 100001; ++k)
        {
            //quais alice tem q bea n tem
            if (albumalice[k] == 1 && albumbeatriz[k] == 0)
                ali++;
            // quais bea tem que alice n tem
            if (albumalice[k] == 0 && albumbeatriz[k] == 1)
                bea++;
        }

        if (ali < bea)
            printf("%d\n", ali);        
        else
            printf("%d\n", bea);
    }
    
    
    return 0;
}