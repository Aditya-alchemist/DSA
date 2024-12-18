#include <stdio.h>

int main() {
  float num1, num2, result;
  char operator;

  printf("Enter the first number: ");
  scanf("%f", &num1);

  printf("Enter the second number: ");
  scanf("%f", &num2);

  printf("Enter the operator (+, -, *, /): ");
  scanf(" %c", &operator);

  switch(operator) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero\n");
        return 1; 
      }
      result = num1 / num2;
      break;
    default:
      printf("Invalid operator\n");
      return 1; 
  }

  printf("Result: %.2f\n", result);

  return 0;
}