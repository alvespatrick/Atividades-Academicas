#include <stdio.h>
#include <stdlib.h>
#define K 100

void troca(int *a, int *b) {
  int aux;

  aux = *a;
  *a = *b;
  *b = aux;
}

void bolha(int *vetor, int n) {
  int i, j;
  for(i = 0; i < n-1; i++) {
    for(j = 1; j < n-i; j++) {
      if(vetor[j] < vetor[j-1])
        troca(&vetor[j-1], &vetor[j]);
    }
  }
}

void bolhaMelhorado(int *vetor, int n) {

  int flag, i, j;
  flag=1;

  for(j=n-1; (j>=1) && (flag == 1); j--){
    flag=0;
    for(i=0; i<j; i++){
      if(vetor[i]>vetor[i+1])
        troca(&vetor[i], &vetor[i+1]);
        flag=1;
    }
  }
}

void selecao (int *vetor, int n){
  int i, j, min, x;
  for (i=0; i<n-1; i++){
    min = i;
    for (j=i+1; j<n; j++){
      if (vetor[j] < vetor[min])
        min = j;
    }
    troca(&vetor[min], &vetor[i]);
  }
}

void insercao (int *vetor, int tam){
  int i, j, x;
  for (i=1; i<tam; i++){
    x = vetor[i];
    for (j=i-1; j>=0 && x < vetor[j]; j--){
      vetor[j+1] = vetor[j];
    }
    vetor[j+1] = x;
  }
}

void merge(int *vetor,int ini,int meio,int fim) {
	int i, pt1, pt2, j, tam;
	
	pt1 = ini;//primeira metade do vetor
	pt2 = meio+1;//segunda metade
  i = ini;
  tam = fim - ini + 1;
	
	int *aux=(int*)malloc((tam)*sizeof(int));

	while((pt1 <= meio) && (pt2 <= fim))
	{
		if(vetor[pt1] <= vetor[pt2])
		{
			aux[i] = vetor[pt1];
			pt1++;
		}
		else
		{
			aux[i] = vetor[pt2];
			pt2++;
		}
		i++;
	}
	
	for(j = pt1; j <= meio; j++) //caso ainda exista elementos na primeira parte
	{
		aux[i] = vetor[j];
		i++;
	}	
	
	for(j=pt2; j<=fim; j++) //caso ainda exista elementos na segunda parte
	{
		aux[i] = vetor[j];
		i++;
	}	
	
	//Retornando os valores alocados para o vetor original
	for(j=ini; j<=fim; j++)
		vetor[j] = aux[j];
	free(aux);
}

void mergeSortRecursivo(int *vetor, int posicaoInicio, int posicaoFim) {

	int meio;

	if(posicaoInicio == posicaoFim)
		return;
	else
	{
		meio=(posicaoInicio+posicaoFim)/2;
		mergeSortRecursivo(vetor,posicaoInicio,meio);
		mergeSortRecursivo(vetor,meio+1,posicaoFim);
		merge(vetor,posicaoInicio,meio,posicaoFim);
	}	
}

void mergeSortIterativo(int *vetor, int posicaoInicio, int posicaoFim) {
  int i, j, k, metadeTamanho, *vetorTemp;
  if(posicaoInicio == posicaoFim) return;
  metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

  mergeSortIterativo(vetor, posicaoInicio, metadeTamanho);
  mergeSortIterativo(vetor, metadeTamanho + 1, posicaoFim);

  merge(vetor, posicaoInicio, metadeTamanho, posicaoFim);
}

void quick(int *vetor, int esq, int dir){
    int pivo = esq, i,ch,j;         
    for(i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vetor[j] < vetor[pivo]){     
            ch = vetor[j];               
            while(j > pivo){           
                vetor[j] = vetor[j-1];      
                j--;                    
            }
            vetor[j] = ch;               
            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quick(vetor,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quick(vetor,pivo+1,dir);      
    }
}

// void contagem(int *vetor, int N) {
//   int i, j, k;
//   int baldes [K];

//   for (i=0; i<K; i++)
//     baldes[i] = 0;
//   for(i = 0; i< N; i++)
//     baldes[vetor[i]]++;
  
//   for(i=0 && j=0; j<K; j++)
//     for(k=baldes[j]; k>0; k--)
//       vetor[i++] = j;
// }

int main(){
  int opcao, *vetor, tam, i;

  printf("\nDigite o tamanho do vetor que deve ser ordenado [1-100000]: ");
  scanf("%d", &tam);
  printf("\nDigite o tipo de conjunto de dados a ser ordenado: ");
  printf("\n1 - Aleatorio\n2 - Ordenado Crescentemente\n3 - Ordenado Decrescente\n4 - Quase Ordenado\nOpcao: ");
  // scanf("%d", &opcao);
  printf("\nInicializando  os vetores!\n\n");

  vetor = (int *) malloc(sizeof(int) * (tam));

  printf("\nOrdenacao por Bolha\n");
  for (i = tam-1; i>=0; i--)
    vetor[tam-1 - i] = i;
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
  
  bolha(vetor, tam);
  printf("\n");
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);

  printf("\nOrdenacao por Bolha Melhorado\n");
  for (i = tam-1; i>=0; i--)
    vetor[tam-1 - i] = i;
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
  
  bolhaMelhorado(vetor, tam);
  printf("\n");
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);

  printf("\n\nOrdenacao por Selecao\n");
  for (i = tam-1; i>=0; i--)
    vetor[tam-1 - i] = i;
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
  
  selecao(vetor, tam);
  printf("\n");
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);

  printf("\n\nOrdenacao por Insercao\n");
  for (i = tam-1; i>=0; i--)
    vetor[tam-1 - i] = i;
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
  
  insercao(vetor, tam);
  printf("\n");
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);

  printf("\n\nOrdenacao por Merge Recursivo\n");
  for (i = tam-1; i>=0; i--)
    vetor[tam-1 - i] = i;
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
  
  mergeSortRecursivo(vetor, 0, tam-1);
  printf("\n");
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);

  printf("\n\nOrdenacao por QuikSort\n");
  for (i = tam-1; i>=0; i--)
    vetor[tam-1 - i] = i;
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
  
  quick(vetor, 0, tam);
  printf("\n");
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);


  printf("\n");
}