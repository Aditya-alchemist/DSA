#include <stdio.h>

struct Distance{
    int km;
    int meter;
};

struct Distance addDistance(struct Distance d1, struct Distance d2){
    struct Distance sum;
    sum.km = d1.km + d2.km;
    sum.meter = d1.meter + d2.meter;
    if(sum.meter >= 1000){
        sum.km += sum.meter / 1000;
        sum.meter = sum.meter % 1000;
    }
    return sum;
};

int main(){
    struct Distance d1, d2, sum;
    printf("Enter the first distance in km and meter: ");
    scanf("%d %d", &d1.km, &d1.meter);
    printf("Enter the second distance in km and meter: ");
    scanf("%d %d", &d2.km, &d2.meter);
    sum = addDistance(d1, d2);
    printf("The sum of the distances is %d km and %d meters", sum.km, sum.meter);
    return 0;
}


