#include <stdio.h>
#include <stdlib.h>
void prueba(int[]);
int  main1(){
    int ej[5]={1,2,3,4,5};
    prueba(ej);
    printf("\n El original es(5) %i",ej[4]);


return 0;
}
void prueba(int Pej[]){
 Pej[4]++;
 printf("\n El modificado es %i",Pej[4]);


}

