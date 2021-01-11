#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main ()
{
    int ;

    float a, b, x1, x2, h, erro, v1, v2, vi, vj, xmax, xi, xj;

    printf("*******************\n");

    printf("Otimizacao do volume de uma caixa\n");

    printf("*******************\n");

    printf("Digite uma das dimensoes da folha:\n ");

    scanf("%f" , &a);

    printf("Digite a outra dimensao da folha:\n ");

    scanf("%f" , &b);

    printf("Digite o valor de x1:\n ");

    scanf("%f" , &x1);

    printf("Digite o valor de x2:\n ");

    scanf("%f" , &x2);

    printf("Digite o valor da precisao necessaria:\n ");

    scanf("%f" , &erro);

    while( fabs(x1-x2) > erro ){

        h = fabs(x1-x2)/3;

        if( x1 < x2){
            xi = x1 + h;
            xj = x2 - h;
        } else{
            xi = x1 - h;
            xj = x2 + h;
        }

        vi = ( a - 2*xi )*( b - 2*xi )*xi;
        vj = ( a - 2*xj )*( b - 2*xj )*xj;

        if( vj > vi){
            x1 = xi;
        } else {
            x2 = xj;
        }

    }

    xmax = (x1 + x2)/2;

    printf("\nXmax vale: %f\n", xmax);

    system("pause");

    return 0;
}
