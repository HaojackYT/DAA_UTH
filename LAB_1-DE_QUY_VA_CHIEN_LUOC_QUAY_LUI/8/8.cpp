#include <iostream>

using namespace std;

// Hàm hiển thị kết quả của một xâu nhị phân
void printAnswer(int N, int X[]) {
    // Duyệt qua N phần tử của một xâu nhị phân
    for (int i = 0; i < N; i++) {
        cout << X[i];
    }
    cout << "\n";
}

// Hàm đệ quy để sinh ra các xâu nhị phân thõa mãn điều kiện
void binaryString(int i, int N, int X[]) {
    // Duyệt các khả năng phần tử X[i] có thể nhận được (0 và 1)
    for (int j = 0; j <= 1; j++) {
        X[i] = j;
        // Kiểm tra 'X[i]' có phải là phần tử đầu tiên trong xâu nhị phân không
        // Hoặc giá trị phần tử đứng trước và sau không là 2 số 0 liên tiếp 
        if (i == 0 || !(X[i] == 0 && X[i - 1] == 0)) {
            // Kiểm tra đã đủ N phần tử cho một xâu nhị phân không
            if (i == N - 1) {
                printAnswer(N, X);
            } else {
                // Gọi lại hàm đệ quy để xây dựng phần tử tiếp theo của xâu nhị phân
                binaryString(i + 1, N, X);
            }
        }
    }
}

int main() {
    int N; // Biến lưu độ dài của xâu nhị phân
    cout << "Nhap vao do dai cua xau nhi phan (> 0): "; cin >> N;

    // Kiểm tra giá trị đầu vào
    if (N <= 0) {
        cout << "Do dai cua xau nhi phan phai (> 0)\n";
        return 0;
    }

    // Mảng lưu giá trị của các phần tử của xâu nhị phân đang được xây dựng
    int X[N];

    // Gọi hàm đệ quy để sinh ra các xâu nhị phân
    binaryString(0, N, X);
    return 0;
}