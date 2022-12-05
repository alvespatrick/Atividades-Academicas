#include <stdio.h>
#include <stdlib.h>

#define K 100
#define tam_bucket 100
#define num_bucket 10
#define max 10
#define TAM 100000

 typedef struct {
         int topo;
         int balde[tam_bucket];
 }bucket;
 
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
  for (i=0; i<=n-1; i++){
    min = i;
    for (j=i+1; j<=n; j++){
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

/*void mergeSortRecursivo(int *vetor, int posicaoInicio, int posicaoFim) {
  int i, j, k, metadeTamanho, *vetorTemp;
  if(posicaoInicio == posicaoFim) return;
  metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

  mergeSortRecursivo(vetor, posicaoInicio, metadeTamanho);
  mergeSortRecursivo(vetor, metadeTamanho + 1, posicaoFim);

  merge(vetor, posicaoInicio, posicaoFim);
}*/

// void mergeSortIterativo(int *vetor, int posicaoInicio, int posicaoFim) {
//   int i, j, k, metadeTamanho, *vetorTemp;
//   if(posicaoInicio == posicaoFim) return;
//   metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

//   mergeSortIterativo(vetor, posicaoInicio, metadeTamanho);
//   mergeSortIterativo(vetor, metadeTamanho + 1, posicaoFim);

//   merge(vetor, posicaoInicio, posicaoFim);
// }

void merge(int *vetor, int posicaoInicio, int posicaoFim) {

  int i, j, k, metadeTamanho, *vetorTemp;

  i = posicaoInicio;
  j = metadeTamanho + 1;
  k = 0;
  vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

  while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
      if (i == metadeTamanho + 1 ) { 
          vetorTemp[k] = vetor[j];
          j++;
          k++;
      }
      else {
          if (j == posicaoFim + 1) {
              vetorTemp[k] = vetor[i];
              i++;
              k++;
          }
          else {
              if (vetor[i] < vetor[j]) {
                  vetorTemp[k] = vetor[i];
                  i++;
                  k++;
              }
              else {
                  vetorTemp[k] = vetor[j];
                  j++;
                  k++;
              }
          }
      }

  }
  for(i = posicaoInicio; i <= posicaoFim; i++) {
      vetor[i] = vetorTemp[i - posicaoInicio];
  }
  free(vetorTemp);
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

void bucket_sort(int *v, int N){

         bucket b[num_bucket];                                      
         int i,j,k;                                                 
 /* 1 */ for(i=0;i<num_bucket;i++)                    //inicializa todos os "topo"
                 b[i].topo=0;
         
 /* 2 */ for(i=0;i<N;i++){                          //verifica em que balde o elemento deve ficar
                j=(num_bucket)-1;
                 while(1){
                         if(j<0)
                                 break;
                         if(v[i]>=j*10){
                                 b[j].balde[b[j].topo]=v[i];
                                 (b[j].topo)++;
                                 break;
                         }
                         j--;
                 }
         }
         
 /* 3 */ for(i=0;i<num_bucket;i++)                     //ordena os baldes
                 if(b[i].topo)
                         bolha(b[i].balde,b[i].topo);
         
         i=0;
 /* 4 */ for(j=0;j<num_bucket;j++){                    //põe os elementos dos baldes de volta no vetor
                 for(k=0;k<b[j].topo;k++){
                         v[i]=b[j].balde[k];
                         i++;
                 }
         }
	


}

int maior(int *vetor, int tam) {
	int i, pos, maior;
	
	i=0;
	pos = i;
	maior = vetor[i];
	
	for(i=1;i<tam;i++)
	{
		if(vetor[i] > maior)
		{
			maior = vetor[i];
			pos = i;
		}
	}
	
	return pos;
}


void contagem(int *vetor, int N) {   
	int i, pos, k;
	int *vetor_aux, *vetor_saida;
	
	pos = maior(vetor, N);
	k = vetor[pos];
	
	//printf("\n Maior: %d \n", k);
	
	vetor_aux = (int *) malloc(sizeof(int) * (k));
	vetor_saida = (int *) malloc(sizeof(int) * (N));

	// inicializando o vetor_aux com tudo zero
	
	for(i=0;i<k;i++)
		vetor_aux[i] = 0;
		
	for (int i = 0; i < N; i++) {
    vetor_aux[vetor[i]]++;
  }
  
	for (int i = 1; i <= k; i++) {
    vetor_aux[i] += vetor_aux[i - 1];
  }
  
  // Encontre o índice de cada elemento do vetor original no vetor auxiliar e
  // coloca os elementos no vetor de saída

  for (int i = N - 1; i >= 0; i--) {
    vetor_saida[vetor_aux[vetor[i]] - 1] = vetor[i];
    vetor_aux[vetor[i]]--;
  }

  // Copie os elementos classificados na matriz original
  for (int i = 0; i < N; i++) {
    vetor[i] = vetor_saida[i];
  }
}

int main(){
  int op, *vetor, tam, i;

  printf("\nDigite o tamanho do vetor que deve ser ordenado [1-100000]: ");
  scanf("%d", &tam);
  printf("\nDigite o tipo de conjunto de dados a ser ordenado: ");
  printf("\n1 - Aleatorio\n2 - Ordenado Crescentemente\n3 - Ordenado Decrescente\n4 - Quase Ordenado\nOpcao: ");
  scanf("%d", &op);
  printf("\nInicializando  os vetores!\n\n");

  vetor = (int *) malloc(sizeof(int) * (tam));

  switch (op) {
    case 1:
      for (i = 0; i< tam; i++)
        vetor[i] = rand() % TAM;
      break;

    case 2:
      for (i = 0; i < tam; i++)
        vetor[i] = i;
      break;

    case 3:
      for (i = tam-1; i>=0; i--)
        vetor[tam-1 - i] = i;
      break;

    case 4:
      for (i = 0; i < tam; i++)
        if ((i%10 == 0) && i>0)
          vetor[i] = rand() % TAM;
        else
          vetor[i] = i;
      break;
    default:
      printf("\nOpcao invalida\n");
  }

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

  printf("\nOrdenacao por Selecao\n");
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

  /*printf("\n\nOrdenacao por Merge Recursivo\n");
  for (i = tam-1; i>=0; i--)
    vetor[tam-1 - i] = i;
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
  
  mergeSortRecursivo(vetor, 0, tam);
  
  printf("\n");
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);*/

  printf("\n\nOrdenacao por QuikSort\n");
  for (i = tam-1; i>=0; i--)
    vetor[tam-1 - i] = i;
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
  
  quick(vetor, 0, tam);
  printf("\n");
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
    
 printf("\n\nOrdenacao por Bucket Sort\n");
  for (i = tam-1; i>=0; i--)
    vetor[tam-1 - i] = i;
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
  
  bucket_sort(vetor, tam);
  printf("\n");
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
    
  printf("\n\nOrdenacao por Contagem\n");
  for (i = tam-1; i>=0; i--)
    vetor[tam-1 - i] = i;
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);
  
 contagem(vetor,tam);
  printf("\n");
  for (i = 0; i < tam; i++)
    printf("%d ", vetor[i]);

  printf("\n");
}
