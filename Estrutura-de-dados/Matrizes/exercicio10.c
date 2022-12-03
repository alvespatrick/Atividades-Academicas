/*
Faça um programa em linguagem C que determine a subtração de 2 matrizes A e B:
*/

#include<stdio.h>
#define L 3
#define C 2

int main (void)
{
    int i, j;
    int matrizA[L][C], matrizB[L][C], R[L][C];

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
      R[i][j] =  matrizA[i][j] - matrizB[i][j];
  }
  printf("\n\n******************* Subtração das Matrizes A e B ********************* \n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf (" %d\t", R[ i ][ j ]);
    }
    printf("\n");
  }
  return(0);   

}