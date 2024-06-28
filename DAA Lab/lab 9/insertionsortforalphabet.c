#include <stdio.h>
#include <string.h>  // Include this header file for string functions

int main() {
    int n;
    printf("Enter the number of names:");
    scanf("%d", &n);

    char names[n][50];  // Assuming each name has a maximum length of 49 characters

    printf("Enter names: ");

    // Taking names as input and storing them in an array
    for (int i = 0; i < n; ++i) {
        scanf("%s", names[i]);
    }

    // Insertion Sort Algorithm for descending alphabetical order
    for (int i = 1; i < n; i++) {
        char current[50];
        strcpy(current, names[i]);
        int j = i - 1;

        // Compare and move names greater than 'current' to one position ahead
        while (j >= 0 && strcmp(names[j], current) < 0) {
            strcpy(names[j + 1], names[j]);
            j--;
        }

        // Place 'current' in its correct position in the sorted part of the array
        strcpy(names[j + 1], current);
    }

    // Printing the sorted names in descending alphabetical order
    printf("The sorted names in descending alphabetical order are:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
