#include <iostream>

using namespace std;

void printAnswer(int N, int X[], int used[]) {
    cout << "Tap hop 1: ";
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            cout << X[i] << " ";
        }
    }
    cout << "\nTap hop 2: ";
    for (int i = 0; i < N; i++) {
        if (used[i]) {
            cout << X[i] << " ";
        }
    }
    cout << "\n";
}

void devideSubset(int i, int N, int X[], int used[], int sum1, int sum2) {
    for (int j = 0; j <= 1; j++) {
        used[i] = j;
        if (j == 0) {
            sum1 += X[i];
        } else {
            sum2 += X[i];
        }

        if (i == N - 1) {
            if (sum1 == sum2) {
                printAnswer(N, X, used);
                return;
            }
        } else {
            devideSubset(i + 1, N, X, used, sum1, sum2);
        }

        if (j == 0) {
            sum1 -= X[i];
        } else {
            sum2 -= X[i];
        }
    }
}

int main() {
    int N;
    cout << "Nhap vao so luong cac phan tu cua tap hop: "; cin >> N;
    int X[N], used[N], sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> tmp;
        X[i] = tmp;
        used[i] = false;
    }
    devideSubset(0, N, X, used, sum1, sum2);
    return 0;
}