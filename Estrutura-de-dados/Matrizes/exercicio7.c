/*
DUP que efetue a multiplicação de uma matriz por um escalar
*/

#include<stdio.h>
#define L 2
#define C 3

int main (void)
{
    int i, j;
    int matrizA[L][C], matrizB[L][C], matriz_soma[L][C];

  printf ("\nDigite valor para os elementos da matriz A\n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matrizA[ i ][ j ]);
    }
  }

  printf ("\nDigite valor para os elementos da matriz B\n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matrizB[ i ][ j ]);
    }
  }
  
  printf("\n\n******************* Matriz A inserida ********************* \n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf (" %d\t", matrizA[ i ][ j ]);
    }
    printf("\n");
  }

  printf("\n\n******************* Matriz B inserida ********************* \n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf (" %d\t", matrizB[ i ][ j ]);
    }
    printf("\n");
  }

  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
      matriz_soma[i][j] =  matrizA[i][j] + matrizB[i][j];
  }
  printf("\n\n******************* Soma das Matrizes A e B ********************* \n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf (" %d\t", matriz_soma[ i ][ j ]);
    }
    printf("\n");
  }
  return(0);   

}