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

// Hàm đệ quy để tìm tổ hợp chập K của N
void NCK(int i, int N, int K, int X[], int tmp[]) {
    // Duyệt các khả năng phần tử tmp[i] có thể nhận được
    for (int j = X[i - 1] + 1; j <= N - K + i; j++) {
        // Giá trị nhỏ nhất: X[i - 1] + 1 (phần tử đứng trước của X[i] + 1)
        // Giá trị lớn nhất: N - K + i
        tmp[i] = X[j];
        // Kiểm tra đã đủ K phần tử cho một tổ hợp không (1)
        // Và phần tử đứng trước có bé hơn phần tử đứng sau không (2)
        // TH1: (1) và (2) đều thỏa mãn
        if (i == K && tmp[i - 1] < tmp[i]) {
            printAnswer(K, tmp);
        }
        // TH2: (1) hoặc (2) không thỏa mãn
        else {
            // Gọi lại hàm đệ quy để xây dựng phần tử tiếp theo của tổ hợp
            NCK(i + 1, N, K, X, tmp);
        }
    }
}

int main() {
    // Biến 'N' lưu số lượng phần tử của tập hợp
    // Và 'K' lưu số lượng phần tử của mỗi tập con từ tập hợp
    int N, K;
    cout << "Nhap vao so luong phan tu khac nhau cua tap hop (N): "; cin >> N;
    cout << "Nhap vao so luong phan tu cua tap con (K): "; cin >> K;
    
    // Kiểm tra giá trị đầu vàos
    if (K > N || K <= 0 || N <= 0) {
        cout << "Gia tri cua N >= K > 0\n";
        return 0;
    }

    // Mảng 'X' lưu giá trị của các phần tử của tập hợp,
    // 'tmp' lưu giá trị của các phần tử của tổ hợp đang được xây dựng
    int X[N + 1], tmp[N + 1];
    // Đảm bảo giá trị nhỏ nhất của vòng lặp: X[i - 1] + 1  (X[1] => X[0] + 1)
    X[0] = 0;
    for (int i = 1; i <= N; i++) {
        X[i] = i;
    }

    // Gọi hàm đệ quy để sinh các tổ hợp
    NCK(1, N, K, X, tmp);
    return 0;
}