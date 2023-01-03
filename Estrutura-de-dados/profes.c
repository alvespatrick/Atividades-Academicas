#include <stdio.h>
#include <stdlib.h>
#include<time.h>

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
	int i, j, menor;
	
	for(j=0; j<n-1; j++){
		menor = j;
		for(i=j+1; i<n; i++){
			if(vetor[i] < vetor[menor])
				menor = i;
		}
		troca(&vetor[j], &vetor[menor]);
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

void intercala(int *v,int ini,int meio,int fim) {
	int i=0,pt1,pt2,aux,tam;
	int *vet;
	
	tam=(fim-ini)+1;
	pt1=ini;//primeira metado do vetor
	pt2=meio+1;//segunda metade
	
	vet=(int*)malloc(tam*sizeof(int));
	
	if(!vet)
	{	printf("\n impossivel alocar memória\n");
		return;
	}
	
	for(int p=0;p<=fim;p++)
		vet[p] = v[p];

	while((pt1<=meio) && (pt2<=fim))
	{
		if(v[pt1]>v[pt2])
		{
			vet[i]=v[pt2];
			pt2++;
		}
		else
		{
			vet[i]=v[pt1];
			pt1++;
		}
		i++;
	}
	
	while(pt1<=meio)//caso ainda exista elementos na primeira parte
	{
		vet[i]=v[pt1];
		pt1++;
		i++;
	}
	while(pt2<=fim)// caso ainda exista elementos na segunda parte
	{
		vet[i]=v[pt2];
		i++;
		pt2++;
	}
	for(aux=ini;aux<=fim;aux++)//transfere dados do vetor auxiliar para o vetor principal
	{
		v[aux]=vet[aux-ini];
	}
	free(vet);
}

void mergesortRecursivo(int v[], int ini, int fim) {
	int meio,i;
	if(ini==fim)
		return;
	else
	{
		meio=(ini+fim)/2;
		mergesortRecursivo(v,ini,meio);
		mergesortRecursivo(v,meio+1,fim);
		intercala(v,ini,meio,fim);
	}	
}

// Função de utilidade para encontrar o mínimo de dois inteiros
int min(int x, int y) { return (x<y)? x :y; }

void mergesortIterativo(int *vetor, int N) {
	int curr_size; // Para o tamanho atual dos subarrays a serem mesclados
					// curr_size varia de 1 to n/2

	int left_start; // Para escolher o índice inicial do subarray esquerdo
					// para ser mesclado

	// Mescle subarrays de baixo para cima. Primeiro, mescle subarrays de
	// tamanho 1 para criar submatrizes classificadas de tamanho 2 e, em seguida, mesclar submatrizes
	// de tamanho 2 para criar subarrays classificados de tamanho 4 e assim por diante.
	for (curr_size=1; curr_size<=N-1; curr_size = 2*curr_size)
	{
		// Escolha o ponto inicial de diferentes subarrays de tamanho atual
		for (left_start=0; left_start<N-1; left_start += 2*curr_size)
		{
			// Encontre o ponto final do subarray esquerdo. mid+1 está começando
			// ponto de direita
			int meio = min(left_start + curr_size - 1, N-1);

			int right_end = min(left_start + 2*curr_size - 1, N-1);

			// Mesclar Subarrays arr[left_start...mid] & arr[mid+1...right_end]
			intercala(vetor, left_start, meio, right_end);
		}
	}
}

void quick_sort(int *vetor, int esq, int dir){
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
    quick_sort(vetor,esq,pivo-1);      
  }
  if(pivo+1 <= dir){              
    quick_sort(vetor,pivo+1,dir);      
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
  int op, *vetor, *aux, tam, i;
  clock_t t;

  srand(time(NULL));

  printf("\nDigite o tamanho do vetor que deve ser ordenado [1-100000]: ");
  scanf("%d", &tam);
  printf("\nDigite o tipo de conjunto de dados a ser ordenado: ");
  printf("\n1 - Aleatorio\n2 - Ordenado Crescentemente\n3 - Ordenado Decrescente\n4 - Quase Ordenado\nOpcao: ");
  scanf("%d", &op);
  printf("\nInicializando os vetores!\n\n");

  vetor = (int *) malloc(sizeof(int) * (tam));
  aux = (int *) malloc(sizeof(int) * (tam));

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
  
  for (i = 0; i < tam; i++)
    aux[i] = vetor[i];
  t = clock();
  bolha(aux, tam);
  t = clock() - t;
  printf("\nMetodo Bolha %lfs\n", ((double)t)/((CLOCKS_PER_SEC)));

  for (i = 0; i < tam; i++)
    aux[i] = vetor[i];
  t = clock();
  bolhaMelhorado(aux, tam);
  t = clock() - t;
  printf("\nMetodo Bolha Melhorado %lfs\n", ((double)t)/((CLOCKS_PER_SEC)));

  for (i = 0; i < tam; i++)
    aux[i] = vetor[i];
  t = clock();
  insercao(aux, tam);
  t = clock() - t;
  printf("\nMetodo Insertion %lfs\n", ((double)t)/((CLOCKS_PER_SEC)));

  for (i = 0; i < tam; i++)
    aux[i] = vetor[i];
  t = clock();
  selecao(aux, tam);
  t = clock() - t;
  printf("\nMetodo Selection %lfs\n", ((double)t)/((CLOCKS_PER_SEC)));

  for (i = 0; i < tam; i++)
    aux[i] = vetor[i];
  t = clock();
  mergesortRecursivo(aux, 0, tam);
  t = clock() - t;
  printf("\nMetodo Merge Sort %lfs\n", ((double)t)/((CLOCKS_PER_SEC)));

  for (i = 0; i < tam; i++)
    aux[i] = vetor[i];
  t = clock();
  mergesortIterativo(aux, tam);
  t = clock() - t;
  printf("\nMetodo Merge Sort Iterativo %lfs\n", ((double)t)/((CLOCKS_PER_SEC)));

  for (i = 0; i < tam; i++)
    aux[i] = vetor[i];
  t = clock();
  quick_sort(aux, 0, tam-1);
  t = clock() - t;
  printf("\nMetodo Quick Sort %lfs\n", ((double)t)/((CLOCKS_PER_SEC)));

  for (i = 0; i < tam; i++)
    aux[i] = vetor[i];
  t = clock();
  bucket_sort(aux, tam);
  t = clock() - t;
  printf("\nMetodo Bucket Sort %lfs\n", ((double)t)/((CLOCKS_PER_SEC)));

  for (i = 0; i < tam; i++)
    aux[i] = vetor[i];
  t = clock();
  contagem(aux, tam);
  t = clock() - t;
  printf("\nMetodo Contagem %lfs\n", ((double)t)/((CLOCKS_PER_SEC)));
  free(aux);
}
