#include <stdlib.h>
#include <stdio.h>

int BinarySearch (int , int *, int , int );
int* BubbleSort(int *, int);

int main ()

{
    int i, N;
    int *vetor;
    int p; //numero a ser buscado
    int y;

    printf("Digite a quantidade de elementos de seu vetor:\n");
    scanf("%d", &N);

    vetor = (int *) malloc(N*sizeof(int));

    for(i = 0; i < N; i++)
    {
        printf("Digite o valor %d de seu vetor:\n", i+1);
        scanf("%d", (vetor+i));
    }

    vetor = BubbleSort(vetor, N);

    printf("Digite o valor a ser encontrado no vetor:\n");
    scanf("%d", &p);

    y = BinarySearch(p, vetor, 0, N-1);

    
    if (y == -1)
        printf("O numero %d nao esta no vetor.\n", p);
    else
        printf("O numero %d esta na posicao %d.\n", p, y + 1);


    free(vetor);

    return 0;
}

int BinarySearch (int target, int *array, int p0, int pN)
{
    int pM;

    pM = (p0 + pN)/2;

    if( *(array + pM) == target)
    {
        return pM;
    }
    else if( p0 >= pN)
    {
        return -1;
    }
    else
    {
        if (array[pM] < target)
            return BinarySearch(target, array, pM+1, pN);
        else
            return BinarySearch(target, array, p0, pM-1);
    }
    
}

int* BubbleSort(int* elm, int tamanho)
{
    int i, j;
    int t;

    for (i=0; i < tamanho; i++)
    {
        for (j=0; j < tamanho - 1; j++)
        {
            if(elm[j] > elm [j+1])
            {
                t = elm[j];
                elm[j] = elm[j+1];
                elm[j+1] = t;
            }
        }
    }
    return elm;
}