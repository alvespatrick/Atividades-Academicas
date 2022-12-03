/*
Elabore um programa em C que determine a matriz resultante do produto matricial de duas
matrizes 2x3 e 3x2.
*/

#include<stdio.h>
#define L 2
#define C 3

int main (void)
{
    int i, j, k, soma;
    int matrizA[L][C], matrizB[C][L], matriz_prod[L][L];

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
  
  for ( i=0; i<C; i++ )
  {
    for ( j=0; j<L; j++ )
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
    {
      soma = 0;
      for (k=0; k<C; k++)
      {
        soma = soma + matrizA[ i ][ k ] * matrizB[ k ][ j ];
      }
      matriz_prod[ i ][ j ] = soma;
    }
    printf("\n");
  }


  printf("\n\n******************* Produto das Matrizes A e B ********************* \n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<L; j++ )
    {
      printf (" %d\t", matriz_prod[ i ][ j ]);
    }
    printf("\n");
  }
  return(0);   

}