#include <stdio.h>
#include <string.h>

typedef struct newyear {
    char string[31];
} newyear;

void insertNewYear(newyear *a, int n) {
    for (int i = 0; i < n; i++) {
        fgets(a[i].string, sizeof(a[i].string), stdin);
        a[i].string[strlen(a[i].string) - 1] = '\0';
    }
}

int demString(newyear *a, int n, char string[]) {
    int d = 0;

    for (int i = 0; i < n; i++)
        if (strcmp(a[i].string, string) == 0)
            d++;

    return d;
}

int remakeString(newyear *a, int n, char string[]) {
    for (int i = 0; i < n; i++)
        if (strcmp(a[i].string, string) == 0)
            strcpy(a[i].string, "DELETE");

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    newyear a[n];

    insertNewYear(a, n);
    
    int d = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(a[i].string, "DELETE") != 0) {
            if (demString(a, n, a[i].string) > 1) {
                d++;
                remakeString(a, n, a[i].string);
            }
        }
    
    int c = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(a[i].string, "DELETE") != 0)
            c++;

    printf("%d", c+d);
    return 0;
}