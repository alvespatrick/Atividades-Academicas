/*
DUP que efetue a soma de uma matriz com um escalar
*/

#include<stdio.h>
#define L 2
#define C 3

int main (void)
{
    int i, j, escalar;
    float matriz[L][C], matriz_nova[L][C];

  printf ("\nDigite valor para os elementos da matriz\n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%f", &matriz[ i ][ j ]);
    }
  }
  
  printf("\nEscalar: ");
  scanf("%d", &escalar);

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
      matriz_nova[i][j] =  escalar + matriz[i][j];
  }
  printf("\n\n******************* Matriz nova ********************* \n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf (" %.2f\t", matriz_nova[ i ][ j ]);
    }
    printf("\n");
  }
  return(0);   

}