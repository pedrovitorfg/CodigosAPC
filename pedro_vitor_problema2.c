#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float calculaComp( float *, float , float , float , int);

int main ()
{
    int i, N;
    float *coef;
    float x0, x1, precisao;
    float comprimento;

    printf("Digite o grau de seu polinomio:\n ");
    scanf("%d" , &N);

    coef = (float *) malloc((N+1)*sizeof(float));

    for( i = 0; i < (N+1); i++)
    {
        printf("Digite coeficiente de grau %d de seu polinomio:\n ", N-i);
        scanf("%f" , coef + N - i);
    }

    printf("Digite o limite inferior de seu polinomio:\n ", N-i);
    scanf("%f" , &x0);

    printf("Digite o limite superior de seu polinomio:\n ", N-i);
    scanf("%f" , &x1);

    printf("Digite o valor da precisao desejada:\n ", N-i);
    scanf("%f" , &precisao);

    comprimento = calculaComp(coef, x0, x1, precisao, N+1);

    printf("\nComprimento vale: %f\n", comprimento);

    free(coef);

    system("pause");

    return 0;
}


float calculaComp( float *a, float x0, float x1, float e, int N)
{
    float f0 = 0;
    float f1 = 0;
    float d1 = 0, d2 = 20;
    int i, j;
    int n = 2;
    float h;

    // x1 = x0 + h;
    
    while( fabs(d1-d2) > e )
    {
        
        d2 = d1;
        h = (x0-x1)/n;

        for( i = 0; i < n; i++)
        {
            x1 = x0 + h;

            for( j = 0; i < N; i++)
            {
                f0 += a[i]*pow(x0,i);
                f1 += a[i]*pow(x1,i);
            }

            d1 += sqrt( pow(f1-f0,2) + pow(x1-x0,2));

            x0 = x1;
        
        }

        n *= 2;

    }

    return d1;
}
