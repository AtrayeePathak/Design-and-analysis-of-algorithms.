/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
 #include <stdio.h>

int findRepeated(int arr[], int n) {
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    fast = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int permutation[n + 1];
    printf("Enter the permutation of {1, 2, ..., n} with one element repeated: ");
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &permutation[i]);
    }

    int repeated_element = findRepeated(permutation, n);

    printf("Repeated element: %d\n", repeated_element);

    return 0;
}

