/* Exemplo 2C de uso de Matriz

   Neste exemplo a impress�o das notas e o calculo da m�dia � totalmente
   adaptavel a quantidade de notas que o aluno tem, e que est� definido na constante
   simb�lica QUANT_NOTAS. Desta forma a manuten��o � centralizada em uma �nica linha.
   Uma �TIMA SOLU��O.

   Foram criadas fun��es para organizar melhor o c�digo, e feita a valida��o da
   entrada de notas.
*/

#include<conio.h>
#include<stdio.h>

#define QUANT_ALUNOS 3
#define QUANT_NOTAS  2

int   notas[QUANT_ALUNOS][QUANT_NOTAS], linha, coluna;
float media;

void listagem();
void leitura();

int main(){

     leitura();
	 listagem();

	 printf("\n\nDigite qualquer tecla para encerrar...");
	 getch();
	 return 0;
}

void leitura(){

     printf("\nEntrada de Notas da Turma\n\n");

	 for (linha = 0; linha < QUANT_ALUNOS; linha++){
		 for (coluna = 0; coluna < QUANT_NOTAS; coluna++){
			 do{

			   printf("Aluno %d, nota %d: ",linha+1,coluna+1);
			   notas[linha][coluna] = -1;
			   fflush(stdin);
			   scanf("%d",&notas[linha][coluna]);

			   if (notas[linha][coluna] < 0 || notas[linha][coluna] > 100){
                 printf("\n\aNota invalida! A nota deve ser entre 0 e 100.\n\n");
               }

             }while(notas[linha][coluna] < 0 || notas[linha][coluna] > 100);

		 }
		 printf("\n");
	 }
}

void listagem(){

     printf("\nListagem de Notas\n");

	 printf("\nAluno");
	 for (coluna = 0; coluna < QUANT_NOTAS; coluna++){
         printf("\tNota %d",coluna+1);
     }
	 printf("\tMedia");

	 for (linha = 0; linha < QUANT_ALUNOS; linha++){

         media = 0;
         for (coluna = 0; coluna < QUANT_NOTAS; coluna++){
             media  += notas[linha][coluna];
         }

		 media /= QUANT_NOTAS;

		 printf("\n%2d",linha+1);

		 for (coluna = 0; coluna < QUANT_NOTAS; coluna++){
         	 printf("\t%5d",notas[linha][coluna]);
         }

         printf("\t%5.2f",media);
	 }
}

