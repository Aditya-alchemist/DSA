#include <stdio.h>

int main(){
    int i,n,fact=1;

    printf("enter the number to find factorial:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        fact=fact*i;
    }

    printf("factorial is %d\n",fact);

    
}