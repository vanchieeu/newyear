#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash_func(char *a) {
    int x = 0;

    for (int i = 0; a[i] != '\0'; i++)
        x += (int)a[i];

    return x;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    int arr[2701];
    for (int i = 0; i < 2701; i++)
        arr[i] = 0;
    for (int i = 1; i <= n; i++) {
        char a[31];
        fgets(a, sizeof(a), stdin);
        a[strlen(a)] = '\0';

        arr[hash_func(a)%900]++;
    }

    int d = 0;
    for (int i = 0; i < 2701; i++)
        if (arr[i] == 1)
            d++;

    printf("%d", d);
    return 0;
}