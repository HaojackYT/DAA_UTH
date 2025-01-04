#include <iostream>

using namespace std;

/*
6
3 -4 5 10 7 8
*/

/*
30
*/

float max(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}

float maxSubSum(float A[], int N) {
    float currentMax = 0;
    float largestMax = 0;

    for (int i = 0; i < N; i++) {
        currentMax = max(0, currentMax + A[i]);
        largestMax = max(currentMax, largestMax);
    }

    return largestMax;
}

int main() {
    int N;
    cout << "Nhap vao so luong phan tu cua mang (> 0): "; cin >> N;

    if (N <= 0) {
        cout << "So luong phan tu cua mang phai (> 0)\n";
        return 0;
    }

    float A[N];
    cout << "Nhap vao gia tri cac phan tu cua mang (cach nhau boi ' '): ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    float result = maxSubSum(A, N);

    cout << "Tong gia tri lon nhat cua day con lien tiep trong mang: " << result;

    return 0;
}