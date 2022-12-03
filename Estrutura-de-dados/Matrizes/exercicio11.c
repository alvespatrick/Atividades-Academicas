/*
Faça um programa em linguagem C que determine a subtração de 2 matrizes A e B:
*/

#include<stdio.h>
#define L 5
#define C 5

int main (void)
{
    int i, j;
    int matriz[L][C], diag_principal = 0, diag_secundaria = 0;

  printf ("\nDigite valor para os elementos da matriz 5x5\n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matriz[ i ][ j ]);
    }
  }
  
  printf("\n\n******************* Matriz A inserida ********************* \n\n");
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      printf (" %d\t", matriz[ i ][ j ]);
    }
    printf("\n");
  }

  for ( i=0; i<L; i++ )
  {
    diag_principal = diag_principal + matriz[ i ][ i ];
  }

  for ( i=0; i<L; i++ )
  {
    diag_secundaria = diag_secundaria + matriz[ i ][ L - i -1 ];
  }

  printf("\nDiag. Principal...: %d\nDiag. Secundaria.: %d\n", diag_principal, diag_secundaria);

  return(0);   

}