#include <stdio.h>
#include <stdlib.h>

float* BubbleSort(float* , int );
float Mediana (float* , int );

int main ()
{
    float *a;
    float elm, mediana;
    int size = 0, i;

    a = (float*)malloc(sizeof(float));

    do {
        printf("Digite um numero entre 0 e 10:\n");
        printf("Encerrar => 11\n ");
        scanf("%f", &elm);
        if(elm >= 0 && elm <= 10)
        {
        size++;
        a = (float*)realloc(a, size*sizeof(float));
        a[size - 1] = elm;
        }
        else if(elm != 11)
            printf("\nNumero invalido! Somente permitido numeros entre 0 e 10!\n\n");

    }
    while(elm != 11);

    printf("\nSequencia digitada: ");

    for (i=0; i < size; i++)
    {
        printf("%.2f\t ", a[i]);
    }
    printf("\n");

    a = BubbleSort(a, size);

    printf("\nSequencia ordenada: ");

    for (i=0; i < size; i++)
    {
        printf("%.2f ", a[i]);
    }
    printf("\n");

    mediana = Mediana(a,size);

    printf("\nMediana: %.2f\n", mediana);


    return 0;
}

float* BubbleSort(float* vetor, int size)
{
    int i, j;
    float t;

    for (i=0; i < size;i++)
    {
        for (j=0; j < size - 1;j++)
        {
            if(vetor[j] > vetor [j+1])
            {
                t = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = t;
            }
        }
    }
    return vetor;
}

float Mediana (float* ptr, int size)
{
    int i, j;
    float mediana, a, b;

    if (size%2 == 0)
    {
        a = ptr[size/2];
        b = ptr[(size/2)-1];
        mediana = (a + b)/2;
    }
    else
        mediana = ptr[(size/2)];

    return mediana;
}