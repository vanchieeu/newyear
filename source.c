#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 31
#define HASH_SIZE 31

typedef struct NEWYEAR {
    char a[MAX_LENGTH];

    struct NEWYEAR *next;
} NEWYEAR;

NEWYEAR *head[HASH_SIZE];

int hash_func(char *a) {
    int index = 0;

    for (int i = 0; *(a+i) != '\0'; i++)
        index += (int)*(a+i);

    return index % HASH_SIZE;
}

void InsertHash(char *a) {
    int index = hash_func(a);
    if (head[index] != NULL)
        return;

    NEWYEAR *ptr = (NEWYEAR *)malloc(sizeof(NEWYEAR));
    strcpy(ptr->a, a);

    head[index] = ptr;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char string[MAX_LENGTH];
        fgets(string, sizeof(string), stdin);

        string[strlen(string)-1] = '\0';

        InsertHash(string);
    }

    int d = 0;
    for (int i = 0; i < HASH_SIZE; i++)
        if (head[i] != NULL)
            d++;
    
    printf("%d", d);
    return 0;
}