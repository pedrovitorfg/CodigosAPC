#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main ()
{
    int coef3, coef2, coef1, coef0, coefsin, coeflog;

    float x1, x2, xm, f1, f2, fm, erro, raiz = 0;

    printf("*******************\n");

    printf("Resolucao de equacoes polinomiais de ordem menor ou igual a 3, com ou sem a funcao seno e a funcao logaritmo natural\n");

    printf("*******************\n");

    printf("Digite o coeficiente de x^3:\n ");

    scanf("%d" , &coef3);

    printf("Digite o coeficiente de x^2:\n ");

    scanf("%d" , &coef2);

    printf("Digite o coeficiente de x:\n ");

    scanf("%d" , &coef1);

    printf("Digite o coeficiente linear:\n ");

    scanf("%d" , &coef0);

    printf("Digite o coeficiente de sen(x):\n ");

    scanf("%d" , &coefsin);

    printf("Digite o coeficiente de ln(x):\n ");

    scanf("%d" , &coeflog);

    printf("Digite o valor de x1:\n ");

    scanf("%f" , &x1);

    printf("Digite o valor de x2:\n ");

    scanf("%f" , &x2);

    printf("Digite o valor da precisao necessaria:\n ");

    scanf("%f" , &erro);

    while ( fabs(x1-x2) > erro && raiz != xm ){

        xm = (x1 + x2)/2;

        if( x1 != 0 && x2 != 0){

            f1 = coef3 * pow(x1,3) + coef2 * x1 * x1 + coef1 * x1 + coef0 + coefsin * sin(x1) + coeflog * log(x1);

            f2 = coef3 * pow(x2,3) + coef2 * x2 * x2 + coef1 * x2 + coef0 + coefsin * sin(x2) + coeflog * log(x2);

            fm = coef3 * pow(xm,3) + coef2 * xm * xm + coef1 * xm + coef0 + coefsin * sin(xm) + coeflog * log(xm);

        } else{

            f1 = coef3 * pow(x1,3) + coef2 * x1 * x1 + coef1 * x1 + coef0 + coefsin * sin(x1);

            f2 = coef3 * pow(x2,3) + coef2 * x2 * x2 + coef1 * x2 + coef0 + coefsin * sin(x2);

            fm = coef3 * pow(xm,3) + coef2 * xm * xm + coef1 * xm + coef0 + coefsin * sin(xm);
        }

        if ( f1 < 0 && f2 > 0 ){

            if( fm < 0 ) {

                x1 = xm;
                x2 = x2;

            } else if ( fm > 0 ){

                x1 = x1;
                x2 = xm;

            } else {
                raiz = xm;
            }

        }
        else
            {

              if( fm < 0 ) {

                x1 = x1;
                x2 = xm;

            } else if ( fm > 0 ){

                x1 = xm;
                x2 = x2;

            } else {
                raiz = xm;
            }

        }

    }

    raiz = xm;

    printf("\nA raiz vale: %f\n", raiz);

    system("pause");

    return 0;
}
