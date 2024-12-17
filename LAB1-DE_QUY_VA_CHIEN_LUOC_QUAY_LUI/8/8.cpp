#include <iostream>

using namespace std;

void printAnswer(int N, int X[]) {
    for (int i = 0; i < N; i++) {
        cout << X[i];
    }
    cout << "\n";
}

void binaryString(int i, int N, int X[]) {
    for (int j = 0; j <= 1; j++) {
        X[i] = j;
        if (i == 0 || !(X[i] == 0 && X[i - 1] == 0)) {
            if (i == N) {
                printAnswer(N, X);
            } else {
                binaryString(i + 1, N, X);
            }
        }
    }
}

int main() {
    int N;
    cout << "Nhap vao do dai cua xau nhi phan: "; cin >> N;
    int X[N];
    binaryString(0, N, X);
    return 0;
}