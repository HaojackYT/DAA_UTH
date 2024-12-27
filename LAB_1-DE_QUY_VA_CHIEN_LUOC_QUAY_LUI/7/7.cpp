#include <iostream>

using namespace std;

// Hàm hiển thị kết quả của một hoán vị
void printAnswer(int N, int X[]) {
    // Duyệt qua N phần tử của một hoán vị
    for (int i = 0; i < N; i++) {
        cout << X[i];
    }
    cout << "\n";
}

// Hàm đệ quy để sinh ra tất cả các hoán vị của tập hợp
void permutation(int i, int N, int X[], bool used[], int tmp[]) {
    // Duyệt các khả năng phần tử X[i] có thể nhận được
    for (int j = 0; j < N; j++) {
        // Kiểm tra có thể gán X[i] = j không
        // Kiểm tra phần tử X[j] đã được sử dụng chưa
        if (!used[j]) {
            // Đánh dấu phần tử X[j] đã được sử dụng
            used[j] = true;
            tmp[i] = X[j];
            // Kiểm tra đã đủ N phần tử cho một hoán vị không
            if (i == N - 1) {
                printAnswer(N, tmp);
            } else {
                // Gọi lại hàm đệ quy để xây dựng phần tử tiếp theo của hoán vị
                permutation(i + 1, N, X, used, tmp);
            }
            // Quay lui đánh dấu phần tử X[j] chưa được sử dụng để thử các khả năng khác
            used[j] = false;
        }
    }
}

int main() {
    int N; // Biến lưu số lượng phần tử của tập hợp
    cout << "Nhap vao so luong phan tu cua tap hop (> 0): "; cin >> N;

    // Kiểm tra giá trị đầu vào
    if (N <= 0) {
        cout << "So luong phan tu cua tap hop phai (> 0)\n";
        return 0;
    }

    // Mảng 'X' lưu giá trị của các phần tử của tập hợp,
    // 'tmp' lưu giá trị của các phần tử của hoán vị đang được xây dựng,
    // 'used' đánh dấu phần tử đã được sử dụng hay chưa
    int X[N], tmp[N]; bool used[N] = {false};
    for (int i = 0; i < N; i++) {
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> X[i];
    }

    // Gọi hàm đệ quy để sinh ra các hoán vị
    permutation(0, N, X, used, tmp);
    return 0;
}