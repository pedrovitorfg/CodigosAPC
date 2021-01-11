        #include <stdio.h>
        #include <stdlib.h>
        #include <math.h>
        #define PI 3.14159

        struct complexo{

            float x, y;
            char formato;

        };

        void convComplexo(struct complexo *, char); // Conversao

        void complexOp(char, struct complexo, struct complexo, struct complexo *, char); // Operacao


        int main ()
        {

            struct complexo A, B, R;
            char conversion, operacao, FS;
            char opcao;

            printf("*********************************\n");
            printf("Calculadora de numeros complexos:\n");
            printf("*********************************\n");
            printf("Elaborada por: Pedro Vitor Ferreira Goncalves\n");
            printf("*********************************\n");

            printf("Escolha uma opcao:\n");
            printf("1) C => Conversao de coordenadas\n2) O => Operacao entre numeros complexos\n3) Z => Fim do programa\n");
            scanf("%c", &opcao);
            printf("*********************************\n");

            while (opcao != 'Z')
            {

                if(opcao == 'O')
                {

                    getchar();

                    printf("Sistema de coordenadas de seu primeiro numero:\n C => Cartesiana E => Exponencial\n");
                    scanf("%c", &A.formato);

                    if( A.formato == 'C')
                    {
                        printf("Parte real de seu primeiro numero:\n");
                        scanf("%f", &A.x);
                        printf("Parte imaginaria de seu primeiro numero:\n");
                        scanf("%f", &A.y);
                    }
                    else if( A.formato == 'E')
                    {
                        printf("Modulo de seu primeiro numero:\n");
                        scanf("%f", &A.x);
                        printf("Fase de seu primeiro numero:\n");
                        scanf("%f", &A.y);
                    } else
                        printf("Opcao invalida.\n");

                    getchar();

                    printf("Sistema de coordenadas de seu segundo numero:\n C => Cartesiana E => Exponencial\n");
                    scanf("%c", &B.formato);

                    if( B.formato == 'C')
                    {
                        printf("Parte real de seu segundo numero:\n");
                        scanf("%f", &B.x);
                        printf("Parte imaginaria de seu segundo numero:\n");
                        scanf("%f", &B.y);
                    }
                    else if( B.formato == 'E')
                    {
                        printf("Modulo de seu segundo numero:\n");
                        scanf("%f", &B.x);
                        printf("Fase de seu segundo numero:\n");
                        scanf("%f", &B.y);
                    } else
                        printf("Opcao invalida.\n");

                    printf("Digite a operacao desejada:\n");
                    getchar();
                    scanf("%c", &operacao);

                    printf("Digite o formato de saida desejado:\n");
                    getchar();
                    scanf("%c", &FS);

                    complexOp(operacao, A, B, &R, FS);



                    if ( FS == 'E')
                    {
                            printf("\nModulo: %.2f\n", R.x);
                            printf("Fase: %.2f radianos\n", R.y);
                            printf("Fase: %.2f graus.\n", R.y * 180 / PI);
                            printf("Formato: %c\n", R.formato);
                    }
                    else if ( FS == 'C')
                    {
                            printf("\nParte real: %.2f\n", R.x);
                            printf("Parte imaginaria: %.2f\n", R.y);
                            printf("Formato: %c\n", R.formato);
                    }

                    printf("*********************************\n");
                    getchar();
                    printf("Escolha uma opcao:\n");
                    printf("1) C => Conversao de coordenadas\n2) O => Operacao entre numeros complexos\n3) Z => Fim do programa\n");
                    scanf("%c", &opcao);

                } else if(opcao == 'C')
                {
                    getchar();

                    printf("Sistema de coordenadas de seu numero:\n C => Cartesiana E => Exponencial\n");
                    scanf("%c", &R.formato);

                    if( R.formato == 'C')
                    {
                        printf("Parte real de seu primeiro numero:\n");
                        scanf("%f", &R.x);
                        printf("Parte imaginaria de seu primeiro numero:\n");
                        scanf("%f", &R.y);
                    }
                    else if( R.formato == 'E')
                    {
                        printf("Modulo de seu primeiro numero:\n");
                        scanf("%f", &R.x);
                        printf("Fase de seu primeiro numero:\n");
                        scanf("%f", &R.y);
                    } else
                    {
                        printf("Opcao invalida.\n");
                        exit(1);
                    }

                    printf("Digite o formato de saida desejado:\n");
                    getchar();
                    scanf("%c", &FS);

                    convComplexo(&R, FS);



                    if ( FS == 'E')
                    {
                            printf("\nModulo: %.2f\n", R.x);
                            printf("Fase: %.2f radianos\n", R.y);
                            printf("Fase: %.2f graus.\n", R.y * 180 / PI);
                            printf("Formato: %c\n", R.formato);
                    }
                    else if ( FS == 'C')
                    {
                            printf("\nParte real: %.2f\n", R.x);
                            printf("Parte imaginaria: %.2f\n", R.y);
                            printf("Formato: %c\n", R.formato);
                    }

                    printf("*********************************\n");
                    getchar();
                    printf("Escolha uma opcao:\n");
                    printf("1) C => Conversao de coordenadas\n2) O => Operacao entre numeros complexos\n3) Z => Fim do programa\n");
                    scanf("%c", &opcao);

                
                }
            
            }


            system("PAUSE");

            return 0;

        }

        void convComplexo(struct complexo *Z, char CONVERSAO){

            float a, b;
            char c;

            if( CONVERSAO != (*Z).formato){
                if ( CONVERSAO == 'C'){
                    a = (*Z).x*cos((*Z).y); // parte real
                    b = (*Z).x*sin((*Z).y); // parte imaginaria
                    c = 'C';
                }
                else if ( CONVERSAO == 'E'){
                    a = sqrt(pow((*Z).x, 2) + pow((*Z).y, 2)); // modulo
                    b = atan((*Z).y/(*Z).x); // fase
                    c = 'E';
                }
            }
            else
            {
                a = (*Z).x;
                b = (*Z).y;
                c = (*Z).formato;
            }

            (*Z).x = a;
            (*Z).y = b;
            (*Z).formato = c;


        }

        void complexOp(char operacao, struct complexo Za, struct complexo Zb, struct complexo *Y, char FS){

            if ( operacao == 'M'){
                convComplexo(&Za, 'E');
                convComplexo(&Zb, 'E');
                (*Y).x = Za.x * Zb.x;
                (*Y).y = Za.y + Zb.y;
                (*Y).formato = 'E';
            }
            else if ( operacao == 'D' ){
                convComplexo(&Za, 'E');
                convComplexo(&Zb, 'E');
                (*Y).x = Za.x / Zb.x;
                (*Y).y = Za.y - Zb.y;
                (*Y).formato = 'E';
            }
            else if ( operacao == 'A' ){
                convComplexo(&Za, 'C');
                convComplexo(&Zb, 'C');
                (*Y).x = Za.x + Zb.x;
                (*Y).y = Za.y + Zb.y;
                (*Y).formato = 'C';
            }
            else if ( operacao == 'S' ){
                convComplexo(&Za, 'C');
                convComplexo(&Zb, 'C');
                (*Y).x = Za.x - Zb.x;
                (*Y).y = Za.y - Zb.y;
                (*Y).formato = 'C';
            }

            // Zres.x = Y.x;
            // Zres.y = Y.y;
            // Zres.formato = Y.formato;

            if( FS == 'C' )
                convComplexo(Y, 'C');
            else if( FS == 'E' )
                convComplexo(Y, 'E');

        }
