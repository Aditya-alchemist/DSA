#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

float calculateArea(Point A, Point B, Point C) {
    return abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}

int main() {
    int rollNumber;

    printf("Enter the last six digits of your roll number: ");
    scanf("%d", &rollNumber);

    Point A = {rollNumber % 10, (rollNumber / 10) % 10};       
    Point B = {(rollNumber / 100) % 10, (rollNumber / 1000) % 10};
    Point C = {(rollNumber / 10000) % 10, (rollNumber / 100000) % 10}; 

    
    float area = calculateArea(A, B, C);
    printf("The area of the triangle with coordinates A(%d, %d), B(%d, %d), C(%d, %d) is: %.2f\n",
           A.x, A.y, B.x, B.y, C.x, C.y, area);

    return 0;
}
