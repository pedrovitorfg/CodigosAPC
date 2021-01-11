        #include <stdio.h>
        #include <stdlib.h>

        struct aluno{

            int matricula;
            float prova[3], trabalho[2];

        };

        typedef struct aluno aluno;


        int main (int argc, char *argv[]){

            if (argc != 2)
            {
                printf("Numero de argumentos invalido!");
            }

            int N;
            int i;
            int j;
            FILE *fp;

            printf("Digite o numero de alunos:\n");
            scanf("%d", &N);

            aluno *estudante;

            estudante = (aluno *) malloc (N * sizeof(aluno));


            for(i = 0; i < N; i++){
                printf("Digite a matricula do aluno %d:\n", i+1);
                scanf("%d", &estudante[i].matricula);
                for(j = 0; j < 3; j++){
                    printf("Digite a nota da prova %d do aluno %d:\n", j + 1, i+1);
                    scanf("%d", &estudante[i].prova[j]);
                }
                for(j = 0; j < 2; j++){
                    printf("Digite a nota do trabalho %d do aluno %d:\n", j + 1, i+1);
                    scanf("%d", &estudante[i].trabalho[j]);
                }
                printf("\n");
            }

            fp =  fopen(argv[1], "w");

            fprintf(fp, "ALUNO \tMATRICULA \tTRABALHO 1 \tTRABALHO 2 \tPROVA 1 \tPROVA 2 \tPROVA 3\n\n");

             for (i = 0; i < N;i++)
            {
                fprintf(fp, "%d \t%d\t\t", i+1, estudante[i].matricula);
                
                for (j = 0; j < 3;j++)
                {
                    fprintf(fp, "%.2f \t\t", estudante[i].trabalho[j]);
                }
                
                for (j = 0; j < 2;j++)
                {
                    fprintf(fp, "%.2f \t\t", estudante[i].prova[j]);
                }
               
                fprintf(fp, "\n");
            }

            fclose(fp);

            free(estudante);

            system("PAUSE");

            return 0;

        }

        