#include <iostream>

using namespace std;

void printAnswer(int i, int tmp[]) {
    for (int j = 0; j <= i; j++) {
        cout << tmp[j] << " ";
    }
    cout << "\n";
}

void findCombination(int i, int N, int X[], int tmp[], int B, int sum) {
    for (int j = 0; j < N; j++) {
        tmp[i] = X[j];
        sum += X[j];
        if (i <= N - 1) {
            if (sum == B) {
                printAnswer(i, tmp);
            } else {
                findCombination(i + 1, N, X, tmp, B, sum);
            }
        }
        sum -= X[j];
    }
    
}

int main() {
    int N, B;
    cin >> N >> B;
    int X[N], tmp[N], sum = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> tmp;
        X[i] = tmp;
    }
    findCombination(0, N, X, tmp, B, sum);
    return 0;
}