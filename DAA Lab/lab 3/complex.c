/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//find the value of (1+i)^n where i = underoot(-1) in O(log2n) time and theta(log2n) space. Input: n and output: (1+i)^n
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double real;
  double imag;
} Complex;

Complex *power(int n) {
  Complex *result = malloc(sizeof(Complex));
  result->real = 1;
  result->imag = 0;

  if (n == 0) {
    return result;
  }

  Complex *temp = power(n / 2);
  result->real = temp->real * temp->real - temp->imag * temp->imag;
  result->imag = temp->real * temp->imag + temp->imag * temp->real;

  if (n % 2 == 1) {
    result->real += temp->imag;
    result->imag -= temp->real;
  }

  return result;
}

int main() {
  int n;
  scanf("%d", &n);

  Complex *result = power(n);
  printf("(1+i)^n = %.2lf + %.2lfi\n", result->real, result->imag);

  free(result);
  return 0;
}

