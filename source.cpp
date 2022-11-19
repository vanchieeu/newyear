#include <iostream>
#include <string>
using namespace std;

#define N 10001
string a[N];

void cinString(int n) {
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]);
    }
}

int coutString(int n, string s) {
    int d = 0;

    for (int i = 0; i < n; i++)
        if (a[i] == s)
            d++;

    return d;
}

void remakeString(int n, string s) {
    for (int i = 0; i < n; i++)
        if (a[i] == s)
            a[i] = "DELETE";
}

int main() {
    int n;
    cin >> n;

    cin.ignore();
    cinString(n);

    int d = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != "DELETE") 
            if (coutString(n, a[i]) > 1) {
                d++;
                remakeString(n, a[i]);
            }
    }

    int c = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != "DELETE")
            c++;
    
    cout << c+d;
    return 0;
}