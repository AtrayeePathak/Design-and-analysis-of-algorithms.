
#include <stdio.h>
#include <string.h>

int isSubstring(const char *str, const char *sub) {
    int strLen = strlen(str);
    int subLen = strlen(sub);

    for (int i = 0; i <= strLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == subLen) {
            return 1; // Substring found
        }
    }

    return 0; // Substring not found
}

int main() {
    char string[100];
    char substring[50];

    printf("Enter the main string: ");
    scanf("%s", string);

    printf("Enter the substring: ");
    scanf("%s", substring);

    if (isSubstring(string, substring)) {
        printf("'%s' is a substring of '%s'\n", substring, string);
    } else {
        printf("'%s' is not a substring of '%s'\n", substring, string);
    }

    return 0;
}

