#include <stdio.h>

int main(){
    int n,i,smallest,largest;

    printf("the size of 1d array is :");
    scanf("%d",&n);

    int arr[n];

    printf("Enter %d elements in array :",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

smallest=largest=arr[0];

for(i=1;i<n;i++){
    if(arr[i]<smallest){
        smallest=arr[i];
    }
}

for(i=1;i<n;i++){
    if(arr[i]>largest){
        largest=arr[i];
    }
}

printf("largest number in array is %d\n",largest);
printf("smallest number in array is %d\n",smallest);

return 0;

}