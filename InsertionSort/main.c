#include <stdio.h>

void insertionSortD(int array[], int tamanho) {
      int i, j, tmp;
      for (i = 1; i < tamanho; i++) { // PERCORRE TODO O NOSSO VETOR PARA DEPOIS PODER FAZER A VERIFCACAO
            j = i;
            while (j > 0 && array[j - 1] < array[j]) { // VERIFICA SSE QUAIS NUMEROS NA POSICAO i-1 SAO MENORES QUE O NUMERO VERIFICADO, CASO FOR ENTRA NAS LINHA ABAIXO PARA PODER REALIZAR AS TROCAS
                  tmp = array[j];
                  array[j] = array[j - 1];
                  array[j - 1] = tmp;
                  j--;
            }
      }
}
void insertionSortC(int array[], int tamanho) {
      int i, j, tmp;
      for (i = 1; i < tamanho; i++) {// PERCORRE TODO O NOSSO VETOR PARA DEPOIS PODER FAZER A VERIFCACAO
            j = i;
            while (j > 0 && array[j - 1] > array[j]) { // VERIFICA SSE QUAIS NUMEROS NA POSICAO i-1 SAO MAIORES QUE O NUMERO VERIFICADO, CASO FOR ENTRA NAS LINHA ABAIXO PARA PODER REALIZAR AS TROCAS
                  tmp = array[j];
                  array[j] = array[j - 1];
                  array[j - 1] = tmp;
                  j--;
            }
      }
}

int main(int argc, char** argv)
{
   int array[100], tamanho, ordem;
   printf("DIGITE QUANTOS NUMEROS O USUARIO VAI DIGIAR NO VETOR:");
   scanf("%d", &tamanho);
   printf("\n");
   for(int i = 0; i < tamanho;i++){
      printf("DIGITE O VALOR PARA VET[%d]: ",i);
      scanf("%d",&array[i]);
   }
   printf("\n");
   printf("\t\tMENU:\n");
   printf("1-ORDERNAR EM ORDEM CRESCENTE.\n");
   printf("2-ORDERNAR EM ORDEM DECRESCENTE.\n");
   printf("0-SAIR.\n");
   scanf("%d",&ordem);
   if (ordem == 1){
      insertionSortC(array,tamanho);
      printf("\nArray em ordem crescente: ");
      for(int i=0; i<tamanho; i++){
      printf("\n\t\t\t%d", array[i]);
   }

      }else if (ordem ==2) {
   insertionSortD(array,tamanho);
   printf("\nArray em ordem decrescente: ");
   for(int i=0; i<tamanho; i++){
      printf("\n\t\t\t%d", array[i]);
   }
}
   return 0;
}
