#include <iostream>

using namespace std;

// Hàm hiển thị kết quả của 2 tập con được chia từ tập hợp
void printAnswer(int N, int X[], int used[]) {
    cout << "Tap con 1: ";
    // Duyệt qua N phần tử của tập hợp
    for (int i = 0; i < N; i++) {
        // Kiểm tra giá trị của phần tử trong mảng 'used' (false: tập con 1) 
        if (!used[i]) {
            cout << X[i] << " ";
        }
    }
    cout << "\nTap con 2: ";
    // Duyệt qua N phần tử của tập hợp
    for (int i = 0; i < N; i++) {
        // Kiểm tra giá trị của phần tử trong mảng 'used' (true: tập con 2) 
        if (used[i]) {
            cout << X[i] << " ";
        }
    }
    cout << "\n";
}

// Hàm đệ quy để chia tập hợp thành 2 tập con sao cho tổng giá trị của các phần tử trong 2 tập hợp bằng nhau
void devideSubset(int i, int N, int X[], int used[], int sum1, int sum2) {
    // Duyệt các khả năng phần tử used[i] có thể nhận được (0: false và 1: true)
    for (int j = 0; j <= 1; j++) {
        used[i] = j;

        // Cập nhật tổng của tập con (0: tập con 1 và 1: tập con 2)
        if (j == 0) {
            sum1 += X[i];
        } else {
            sum2 += X[i];
        }

        // Kiểm tra đã đủ N phần tử cho một hoán vị không
        if (i == N - 1) {
            // Kiểm tra tổng của 2 tập con có bằng nhau không
            if (sum1 == sum2) {
                printAnswer(N, X, used);
                return;
            }
        } else {
            // Gọi lại hàm đệ quy để xây dựng phần tử tiếp theo
            devideSubset(i + 1, N, X, used, sum1, sum2);
        }

        // Quay lui phần tử X[i] để thử các khả năng khác
        if (j == 0) {
            sum1 -= X[i];
        } else {
            sum2 -= X[i];
        }
    }
}

int main() {
    int N; // Biến lưu số lượng các phần tử của tập hợp
    cout << "Nhap vao so luong cac phan tu cua tap hop (>0): "; cin >> N;
    
    // Kiểm tra giá trị đầu vào
    if (N <= 0) {
        cout << "So luong cac phan tu cua tap hop phai (>0)\n";
        return 0;
    }
    
    // Mảng 'X' lưu giá trị các phần tử của tập hợp,
    // 'used' đánh dấu các phần tử của mảng 'X' thuộc tập con 1 hay 2
    // Biến 'sum' + 'i' lưu giá trị tổng các phần tử của tập con 'i' (i = 1,2)
    int X[N], used[N] = {false}, sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++) {
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> X[i];
    }

    // Gọi hàm đệ quy để chia tập hợp thành 2 tập con
    devideSubset(0, N, X, used, sum1, sum2);
    return 0;
}