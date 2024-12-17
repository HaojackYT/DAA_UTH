#include <iostream>

using namespace std;

// Hàm hiển thị kết quả của một tổ hợp
void printAnswer(int K, int tmp[]) {
    cout << "{"; // Bắt đầu tổ hợp với dấu ngoặc mở
    // Duyệt qua K phần tử của tổ hợp
    for (int i = 1; i <= K; i++) {
        cout << tmp[i];
        // Nếu không phải phần tử cuối, in thêm dấu phẩy sau mỗi phần tử
        if (i <= K - 1) {
            cout << ",";
        }
    }
    cout << "}\n"; // Kết thúc tổ hợp với dấu ngoặc đóng
}

// Hàm quay lui để tìm tổ hợp N chập K
void NCK(int i, int N, int K, int X[], int tmp[]) {
    // Duyệt các khả năng phần tử X[i] có thể nhận được
    for (int j = X[i - 1] + 1; j <= N - K + i; j++) {
        // Giá trị nhỏ nhất: X[i - 1] + 1 => phần tử đứng trước của X[i] + 1
        // Giá trị lớn nhất: N - K + i
        tmp[i] = j;
        // Kiểm tra đã đủ K phần tử cho một tổ hợp chưa
        // Và phần tử đứng trước có bé hơn phần tử đứng sau không
        if (i == K && tmp[i - 1] < tmp[i]) {
            printAnswer(K, tmp);
        } else {
            NCK(i + 1, N, K, X, tmp); // Gọi lại đệ quy để chọn phần tử tiếp theo
        }
    }
}

int main() {
    // Biến 'N' lưu số lượng phần tử của tập hợp
    // Và 'K' lưu số lượng phần tử của mỗi tập con từ tập hợp
    int N, K;
    cout << "Nhap vao so luong phan tu khac nhau cua tap hop (N): "; cin >> N;
    cout << "Nhap vao so luong phan tu cua tap con (K): "; cin >> K;
    
    // Kiểm tra giá trị đầu vào
    if (K > N || K <= 0 || N <= 0) {
        cout << "Gia tri cua N >= K > 0\n";
        return 0;
    }

    // Mảng 'X' lưu giá trị của các phần tử của tập hợp
    // Và 'tmp' lưu giá trị của các phần tử của tổ hợp đang được xây dựng
    int X[N + 1], tmp[N + 1];
    X[0] = 0; // Đảm bảo giá trị nhỏ nhất của vòng lặp: X[i - 1] + 1  (X[1] => X[0] + 1)
    for (int i = 1; i <= N; i++) {
        int tmp;
        cout << "Nhap vao gia tri cua phan tu " << i << ": "; cin >> tmp;
        X[i] = tmp;
    }

    // Gọi hàm quay lui để sinh các tổ hợp
    NCK(1, N, K, X, tmp);
    return 0;
}