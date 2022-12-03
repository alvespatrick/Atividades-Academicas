/*
Elabore um programa em C que determine a soma das colunas e das linhas da matriz abaixo
*/

#include<stdio.h>
#define L 4
#define C 3

int main (void)
{
  int i, j, soma_linhas, soma_colunas;
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
      printf (" %d ", matriz[ i ][ j ]);
    }
    printf("\n");
  }

  printf("\nSoma das linhas\n");
  for ( i=0; i<L; i++ )
  {
    soma_linhas = 0;
    for ( j=0; j<C; j++ )
    {
      soma_linhas = soma_linhas + matriz[ i ][ j ];
    }
    printf("%d\n", soma_linhas);
  }
  
  printf("\nSoma das colunas\n");
  for ( i=0; i<C; i++ )
  {
    soma_colunas = 0;
    for ( j=0; j<L; j++ )
    {
      soma_colunas = soma_colunas + matriz[ j ][ i ];
    }
    printf("%d ", soma_colunas);
  }
  printf("\n");

  return(0);   

}