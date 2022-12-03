/*
Faça um algoritmo/programa que imprima os dados da matriz abaixo de forma invertida,
conforme o exemplo:
*/

#include<stdio.h>
#define L 2
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
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf (" %d\t", matriz[ i ][ j ]);
    }
    printf("\n");
  }

  printf("\n\n******************* Matriz transposta ********************* \n\n");
  
  for ( i=0; i<C; i++ )
  {
    for ( j=0; j<L; j++ )
    {
      printf (" %d\t", matriz[ j ][ i ]);
    }
    printf("\n");
  }
  
  return(0);   

}