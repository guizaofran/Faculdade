#include <stdio.h>

int main(){
    int x, mult;
    
    printf("Digite o numero: ");
    scanf("%i",&x);
    
    for(mult=1;mult<=10;mult++){
        printf("%i.%i= %i \n",x,mult,x*mult);
    }
}
