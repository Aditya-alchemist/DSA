#include <stdio.h>
#include <string.h>

int main(){
    int i,length;
    char roll_number[20];

    printf("Please enter your roll numer:");
    scanf("%s",roll_number);

    length= strlen(roll_number);

printf("Digits at even position are");
for(i=0;i<length;i++){
    if((i+1)%2==0){
        printf("Roll number at even position is:%c\n",roll_number[i]);
    }
}

printf("Digits at odd position are");
for(i=0;i<length;i++){
    if((i+1)%2!=0){
        printf("Roll number at odd position is:%c\n",roll_number[i]);
    }
}

return 0;
}