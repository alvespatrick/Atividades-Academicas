/*
Faça um programa em C que fazendo o uso de loops aninhados (o uso de matrizes é
opcional), imprima a desenho abaixo:
*/

#include<stdio.h>
#define L 4
#define C 10

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
    for ( j=0; j<C; j++ )
    {
      if((i%(L-1) == 0))
        printf ("%c ", matriz[ i ][ j ]);
      else if((j%(C-1) == 0))
        printf ("%c ", matriz[ i ][ j ]);
      else  
        printf("  ");
    }
    printf("\n");
  }

  return(0);   

}