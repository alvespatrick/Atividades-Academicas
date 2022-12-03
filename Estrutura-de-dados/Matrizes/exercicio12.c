/*
Faça um programa em C que fazendo o uso de loops aninhados (o uso de matrizes é
opcional), imprima a desenho abaixo:
*/

#include<stdio.h>
#define L 4
#define C 4

int main (void)
{
    int i, j;
    char matriz[L][C];
  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<C; j++ )
    {
      matriz[ i ][ j ] = '*';
    }
  }

  
  for ( i=0; i<L; i++ )
  {
    for ( j=0; j<=i; j++ )
    {
      printf ("%c ", matriz[ i ][ j ]);
    }
    printf("\n");
  }

  return(0);   

}