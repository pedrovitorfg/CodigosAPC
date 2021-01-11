#include <stdlib.h>
#include <stdio.h>

int main(){

    float a, b, c;

    printf("Digite o valor do primeiro lado: ");
    scanf("%f", &a);

    printf("Digite o valor do segundo lado: ");
    scanf("%f", &b);

    printf("Digite o valor do terceiro lado: ");
    scanf("%f", &c);

    if( a < b+c && b < a+c && c < a+b){

        if( a == b && a== c){

            printf("Triangulo Equilatero\n");

        } else if( a != b && a!= c && b != c){

            printf("Triangulo Escaleno\n");

        } else {

            printf("Triangulo Isoceles\n");

        }

    } else {

        printf("Nao existe triangulo com esses valores.\n");

    }

    system("pause");

    return 0;

}
