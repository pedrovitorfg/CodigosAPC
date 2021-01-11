#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

        float pop1, pop2, tx1, tx2;
        int tempo;

        printf("Digite o valor inicial da populacao A: ");
        scanf("%f", &pop1);


        printf("Digite o valor inicial da populacao B: ");
        scanf("%f", &pop2);


        printf("Digite a taxa de crescimento da populacao A (em porcento): ");
        scanf("%f", &tx1);


        printf("Digite a taxa de crescimento da populacao B (em porcento): ");
        scanf("%f", &tx2);

        tempo = 0;

        while ( pop1 < pop2 ){

            tempo++;

            pop1 = pop1*(1+tx1/100);

            pop2 = pop2*(1+tx2/100);

        }

        printf("%d anos.\n", tempo);

        system("pause");

        return 0;

}
