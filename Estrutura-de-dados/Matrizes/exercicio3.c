/*
Faça um algoritmo/programa que determine o somatório e a média de todos os elementos da
matriz abaixo
*/

#include<stdio.h>
#define L 3
#define C 3

int main (void)
{
    int i, j;
    float matriz[L][C], soma = 0, media = 0.0;

  printf ("\nDigite valor para os elementos da matriz\n\n");
  
  for ( i=0; i<L; i++ )
    for ( j=0; j<C; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%f", &matriz[ i ][ j ]);
    }

  printf("\n\n******************* Matriz inserida ********************* \n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf (" %.2f\t", matriz[ i ][ j ]);
    }
    printf("\n");
  }

  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
      soma = soma + matriz[i][j];
  }  
  media = soma / (C * L);

  printf("\nSoma: %.2f \nMedia: %f\n", soma, media);
  return(0);   

}