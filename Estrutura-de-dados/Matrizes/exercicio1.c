/*
Faça um algoritmo/programa que imprima os dados da matriz abaixo na forma como ela está
disposta: em linhas em colunas, com um espaço em branco entre uma coluna e outra e com
uma quebra de linha '\n' entre as linhas:
*/

#include<stdio.h>
#define L 3
#define C 3

int main (void)
{
    int matriz[L][C],i, j; 

  printf ("\nDigite valor para os elementos da matriz\n\n");
  
  for ( i=0; i<L; i++ )
    for ( j=0; j<C; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matriz[ i ][ j ]);
    }
  
  printf("\n\n******************* Matriz inserida ********************* \n\n");
  
  for ( i=0; i<3; i++ )
  {
    for ( j=0; j<3; j++ )
    {
      printf (" %d\t", matriz[ i ][ j ]);
    }
    printf("\n");
  }
  
  return(0);   

}