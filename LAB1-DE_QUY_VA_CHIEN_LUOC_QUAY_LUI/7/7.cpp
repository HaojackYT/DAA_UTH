#include <iostream>

using namespace std;

void printAnswer(int N, int X[]) {
    for (int i = 0; i < N; i++) {
        cout << X[i];
    }
    cout << "\n";
}

void permutation(int i, int N, int X[], bool used[], int tmp[]) {
    // Duyet cac kha nang phan tu X[i] co the nhan duoc
    for (int j = 0; j < N; j++) {
        // Kiem tra co the gan X[i] = j hay khong?
        // Kiem tra phan tu j da duoc su dung chua
        if (!used[j]) {
            // Danh dau phan tu j da duoc su dung
            used[j] = true;
            tmp[i] = X[j];
            if (i == N - 1) {
                printAnswer(N, tmp);
            } else {
                permutation(i + 1, N, X, used, tmp);
            }
            used[j] = false;
        }
    }
}

int main() {
    int N;
    cout << "Nhap vao so luong phan tu: "; cin >> N;
    int X[N], tmp[N]; bool used[N];
    for (int i = 0; i < N; i++) {
        int tmp;
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> tmp;
        X[i] = tmp;
    }
    permutation(0, N, X, used, tmp);
}