        #include <stdio.h>
        #include <stdlib.h>
        #define MAX 10

        char fneuronio(float *, float *, float, int);

        int main() {

            float ENTRADAS[MAX], PESOS[MAX], T;
            int i;
            char resposta;

            for ( i = 0; i < MAX; i++){
                printf("Digite a componente %d do vetor entradas:\n", i+1);
                scanf("%f", &ENTRADAS[i]);
            }

            for ( i = 0; i < MAX; i++){
                printf("Digite a componente %d do vetor pesos:\n", i+1);
                scanf("%f", &PESOS[i]);
            }

            printf("Digite o valor do limiar:\n");
            scanf("%f", &T);

            resposta = fneuronio( ENTRADAS, PESOS, T, MAX);

            if ( resposta == 1)
                printf("O neuronio esta ativado.\n");
            else if ( resposta == 0)
                printf("O neuronio esta inibido.\n");

            return 0;
        }

        char fneuronio(float *E, float *W, float T,int N) {

            int i;
            float SOMAP = 0;
            char y;

            for ( i = 0; i < N; i++){
                SOMAP += E[i]*W[i];
            }

            if ( SOMAP > T)
                y = 1;
            else
                y = 0;

            return y;
        }
