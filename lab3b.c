#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void matrizGLCM (int *, int, int);

int main()
{
    int i, j;
    int lin, col, *mat;       // Dimensoes matriz original

    printf("Digite o numero de linhas da matriz:\n");
    scanf("%d",&lin);

    printf("Digite o numero de colunas da matriz:\n");
    scanf("%d",&col);

    srand(time(NULL));

    mat = (int*)malloc(lin*col*sizeof(int));

    for (i=0;i<lin;i++){
        for (j=0;j<col;j++){
            *(mat+col*i+j) = rand() %8;
        }
    }

    
    printf("\nMATRIZ: \n\n");
        for (i=0;i<lin;i++){
            for (j=0;j<col;j++)
        {
            printf("%d \t", *(mat+col*i+j));
        }
        printf("\n");
    }

    matrizGLCM(mat, lin, col);

    free(mat);

    return 0;
}

void matrizGLCM (int *M, int LIN, int COL){
    int i, j;
    int a, b;
    int N = 0;
    int *G;
    float energia = 0;
    float entropia = 0;
    float contraste = 0;
    float homogeneidade = 0;

    for (i=0;i<LIN; i++){
        for (j=0;j<COL;j++){
            if(*(M+COL*i+j) > N){
                N = *(M+COL*i+j);
            }
        }
    }

    G = (int*)malloc((N+1)*(N+1)*sizeof(int));

    for (i=0;i<LIN; i++){
        for (j=0;j<COL;j++){
            *(G+(N+1)*i+j) = 0;
        }
    }

    for (i=0;i<LIN;i++){
        for (j=0;j<COL-1;j++){
            a = *(M+COL*i+j);
            b = *(M+COL*i+j+1);
            *(G+(N+1)*a+b)+=1;
        }
    }

    printf("\nGLCM: \n\n");
        for (i=0;i<LIN;i++){
            for (j=0;j<COL;j++)
        {
            printf("%d \t", *(G+(N+1)*i+j));
        }
        printf("\n");
    }

    for (i=0;i<LIN; i++){
        for (j=0;j<COL;j++){
            energia += (*(G+(N+1)*i+j))*(*(G+(N+1)*i+j));
        }
    }

    for (i=0;i<LIN; i++){
        for (j=0;j<COL;j++){
            entropia += -log(*(G+(N+1)*i+j))*(*(G+(N+1)*i+j));
        }
    }

    for (i=0;i<LIN; i++){
        for (j=0;j<COL;j++){
            contraste += (*(G+(N+1)*i+j))*(i-j)*(i-j);
        }
    }

      for (i=0;i<LIN; i++){
        for (j=0;j<COL;j++){
            homogeneidade += (*(G+(N+1)*i+j))/(1+(i-j)*(i-j));
        }
    }

    printf("\nenergia: \n", energia);
    printf("\nentropia: \n", entropia);
    printf("\ncontraste: \n", contraste);
    printf("\nhomogeneidade: \n",homogeneidade);

}  