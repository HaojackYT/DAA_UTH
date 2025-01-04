#include <iostream>

using namespace std;

/*
6
1 3 2 8 4 5
*/

/*
4
*/

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int longestIncreasingSubSequence(float a[], int n) {
    int L[n];

    for (int i = 0; i < n; i++) {
        L[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }

    int lisLen = 0;
    for (int i = 0; i < n; i++) {
        if (L[i] > lisLen) {
            lisLen = L[i];
        }
    }

    return lisLen;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang (> 0): "; cin >> n;

    float a[n];
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int result = longestIncreasingSubSequence(a, n);

    cout << "Do dai cua day con tang dai nhat: "<< result;
    return 0;
}