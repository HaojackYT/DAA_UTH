#include <iostream>

using namespace std;

// Hàm hiển thị kết quả của một hoán vị
void printAnswer(int N, int X[]) {
    for (int i = 0; i < N; i++) {
        cout << X[i];
    }
    cout << "\n";
}

// Hàm quay lui để sinh ra tất cả các hoán vị
void permutation(int i, int N, int X[], bool used[], int tmp[]) {
    // Duyệt các khả năng phần tử X[i] có thể nhận được
    for (int j = 0; j < N; j++) {
        // Kiểm tra có thể gán X[i] = j hay không ?
        // Kiểm tra phần tử thứ j đã được sử dụng chưa
        if (!used[j]) {
            // Đánh dấu phần tử thứ j đã được sử dụng
            used[j] = true;
            tmp[i] = X[j];
            // Kiểm tra đã đủ N phần tử cho một hoán vị hay chưa?
            if (i == N - 1) {
                printAnswer(N, tmp);
            }
            // Nếu chưa đủ, gọi lại hàm quay lui để xây dựng phần tử tiếp theo
            else {
                permutation(i + 1, N, X, used, tmp);
            }
            // Quay lui, đánh dấu phần tử thứ j chưa được sử dụng
            used[j] = false;
        }
    }
}

int main() {
    int N; // Biến 'N' lưu số lượng phần tử của mảng
    cout << "Nhap vao so luong phan tu: "; cin >> N;
    
    
    
    // Mảng 'X' lưu giá trị của các phần tử, 'tmp'
    int X[N], tmp[N]; bool used[N];
    for (int i = 0; i < N; i++) {
        int tmp;
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> tmp;
        X[i] = tmp;
    }
    permutation(0, N, X, used, tmp);
}