/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

void findDuplicates(int arr[], int n) {
    // Calculate the sum and product of all elements
    int sum = 0;
    int product = 1;

    for (int i = 0; i < n + 2; i++) {
        sum += arr[i];
        product *= arr[i];
    }

    // Calculate the sum and product of numbers from 1 to n
    int sumOfNumbers = (n * (n + 1)) / 2;
    int productOfNumbers = 1;

    for (int i = 1; i <= n; i++) {
        productOfNumbers *= i;
    }

    // Calculate the difference and quotient
    int diff = sum - sumOfNumbers;
    int quotient = product / productOfNumbers;

    // Find the duplicates using the quadratic equation
    int sqrtTerm = sqrt(diff * diff - 4 * quotient);
    int duplicate1 = (diff + sqrtTerm) / 2;
    int duplicate2 = (diff - sqrtTerm) / 2;

    printf("Duplicates: %d and %d\n", duplicate1, duplicate2);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n + 2];
    printf("Enter the elements of the array with two duplicates: ");
    for (int i = 0; i < n + 2; i++) {
        scanf("%d", &arr[i]);
    }

    findDuplicates(arr, n);

    return 0;
}

