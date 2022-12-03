/*
Faça um algoritmo/programa que separe os valores pares e ímpares em duas matrizes
diferentes:
*/

#include<stdio.h>
#define L 3
#define C 3

int main (void)
{
    int i, j;
    int matriz[L][C];

  printf ("\nDigite valor para os elementos da matriz A\n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matriz[ i ][ j ]);
    }
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

  printf("\n\n******************* Impares ********************* \n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      if(matriz[ i ][ j ] % 2 == 1)
        printf ("%d\t", matriz[ i ][ j ]);
      else
        printf(".\t");
    }
    printf("\n");
  }

  printf("\n\n******************* Pares ********************* \n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      if(matriz[ i ][ j ] % 2 == 0)
        printf ("%d\t", matriz[ i ][ j ]);
      else
        printf(".\t");
    }
    printf("\n");
  }

  return(0);   

}