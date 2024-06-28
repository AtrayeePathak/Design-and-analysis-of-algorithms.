/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
 #include <stdio.h>

int main() {
    int a[10][10], b[10][10], product[10][10];
    int arows, acolumn, brows, bcolumn, n;

    printf("Enter the value of rows and columns for matrix A: ");
    scanf("%d %d", &arows, &acolumn);  // Removed the comma here

    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < arows; i++) {
        for (int j = 0; j < acolumn; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the value of rows and columns for matrix B: ");
    scanf("%d %d", &brows, &bcolumn);  // Removed the comma here

    if (acolumn != brows) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < brows; i++) {
        for (int j = 0; j < bcolumn; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < arows; i++) {
        for (int j = 0; j < bcolumn; j++) {
            int sum = 0;
            for (int k = 0; k < acolumn; k++) {
                sum += a[i][k] * b[k][j];
            }
            product[i][j] = sum;
        }
    }

    // Display the product matrix
    printf("Product of the matrices:\n");
    for (int i = 0; i < arows; i++) {
        for (int j = 0; j < bcolumn; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}

