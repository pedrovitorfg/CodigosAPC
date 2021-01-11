#include <stdlib.h>
#include <stdio.h>

int main(){

    int a, b, c, DV;

    printf("Digite o primeiro algarismo (mais a esquerda): ");
    scanf("%d", &a);

    printf("Digite o segundo algarismo (central): ");
    scanf("%d", &b);


    printf("Digite o terceiro algarismo (mais a direita): ");
    scanf("%d", &c);


    DV = 11 - ( 2*c + 3*b + 4*a )%11;

    printf("O digito verificador vale: %d \n", DV);

    system("pause");

    return 0;

}
