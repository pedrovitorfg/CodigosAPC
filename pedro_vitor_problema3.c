        #include <stdio.h>
        #include <stdlib.h>
        #include <math.h>
        #include <ctype.h>
        #include <string.h>
        #define MAX1 100
        #define MAX2 5
        #define MAX 3

        struct taluno{

        int nr;
        char nome[MAX1];
        char departamento[MAX2];
        float nota[3];
        float media;

        };

        int main (){

        struct taluno aluno[MAX];
        int i, j, cont1, cont2;
        float mediaturma = 0, soma = 0, menornotap1 = 10, maiormedia = 0, alunosreprovados = 0;
        char alunomaiormedia[MAX1];

        for( i = 0; i < MAX; i++) {

            cont1 = 0;
            cont2 = 0;

            printf("Digite o numero do aluno:\n");
            scanf("%d", &aluno[i].nr);

            printf("Digite o nome do aluno:\n");
            getchar();
            gets(aluno[i].nome);

            printf("Digite o departamento:\n");
            scanf("%s", aluno[i].departamento);

            aluno[i].media = 0;

            for( j = 0; j < 3; j++){
                printf("Digite a nota %d do aluno %d: \n", j+1, i+1);
                scanf("%f", &aluno[i].nota[j]);

                aluno[i].media += (aluno[i].nota[j])/3;
            }

            while ( cont1 < strlen(aluno[i].nome)) {
                aluno[i].nome[cont1] = tolower(aluno[i].nome[cont1]);
                cont1 ++;
            }

            for ( cont1 = 0; cont1 < strlen(aluno[i].nome); cont1++) {
                if ( aluno[i].nome[cont1] == 32) {
                    aluno[i].nome[cont1 + 1] = toupper(aluno[i].nome[cont1 + 1]);
                }
            }

              while ( cont2 < strlen(aluno[i].departamento)) {
                aluno[i].departamento[cont2] = toupper( aluno[i].departamento[cont2]);
                cont2 ++;
            }

            aluno[i].nome[0] = toupper( aluno[i].nome[0] );

            if ( aluno[i].nota[0] <= menornotap1){
                menornotap1 = aluno[i].nota[0];
            }

            if ( aluno[i].media > maiormedia ) {
                maiormedia = aluno[i].media;
                strcpy(alunomaiormedia, aluno[i].nome);
            }

        }

        for ( i = 0; i < MAX; i++) {
            for ( j = 0; j < 3; j++) {
                soma += aluno[i].nota[j];
            }
        }

        mediaturma = soma / 9;

        for( i = 0; i < MAX; i++){
            printf("aluno[%d].nr : %d \n", i, aluno[i].nr);
            printf("aluno[%d].nome : %s \n", i, aluno[i].nome);
            printf("aluno[%d].curso : %s \n", i, aluno[i].departamento);
            for ( j = 0; j < 3; j++){
                    printf("aluno[%d].nota[%d] : %.2f \n", i, j, aluno[i].nota[j]);
            }
            printf("aluno[%d].media : %.2f \n", i, aluno[i].media);
        }

        printf("media da turma : %.2f \n", mediaturma);
        printf("menor nota P1 : %.2f \n", menornotap1);
        printf("aluno com maior media : %s \n", alunomaiormedia);

        for(i = 0; i < MAX; i++){
            if ( aluno[i].media < mediaturma) {
                printf("o aluno %s esta abaixo da media da turma\n", aluno[i].nome);
            }
            if ( aluno[i].media < 5) {
                printf("o aluno %s esta reprovado\n", aluno[i].nome);
                alunosreprovados++;
            }
        }

        if ( alunosreprovados == 0 )
            printf("nao ha alunos reprovados");

        system("PAUSE");

        return 0;

        }



