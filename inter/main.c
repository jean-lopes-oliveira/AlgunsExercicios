#include <stdio.h>
#include <stdlib.h>
/*Author: Jean Lopes Oliveira*/

int main()
{
    int vet1[] = {1,2,2,4,5,8};
    int vet2[] = {1,2,3,4,5,6,7,1,8,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int vet3[9];
    int l;
    int k = 0;
    int f = 0;
    int h = 0;
    for(int i = 0 ; i<6;i++){

        for(int j = 0; j<30;j++){

            if(vet1[i] == vet2[j]){

                        while(k<6 && l != 1){
                            if(vet3[k] == vet1[i]){
                                    l = 1;
                            }else{
                                    l = 0;
                            }

                            k++;
                        }
                        k = 0;
                        if(l == 0){

                            vet3[f++] = vet1[i];

                        }
                        l = 0;

            }

        }

    }
    for(int i =0; i<=f-1;i++){


        printf("%d",vet3[i]);

    }
    return 0;
}
