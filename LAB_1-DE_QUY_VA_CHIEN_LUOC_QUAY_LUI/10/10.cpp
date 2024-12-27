#include <iostream>

using namespace std;

// Hàm hiển thị kết quả của một tổ hợp
void printAnswer(int i, int tmp[]) {
    cout << "{";
    // Duyệt qua i phần tử của tổ hợp
    for (int j = 0; j <= i; j++) {
        cout << tmp[j];
        // Nếu không phải phần tử cuối, in thêm dấu phẩy sau mỗi phần tử
        if (j < i ) {
            cout << ",";
        }
    }
    cout << "}\n";
}

// Hàm đệ quy để tìm các tổ hợp các phần tử của mảng có tổng bằng B
void findCombination(int i, int N, int X[], int tmp[], int B, int sum) {
    // Duyệt các khả năng phần tử tmp[i] có thể nhận được
    for (int j = 0; j < N; j++) {
        tmp[i] = X[j];
        // Cập nhật tổng của tổ hợp hiện tại
        sum += X[j];
        // Kiểm tra phần tử đang xây dựng có phải phần tử thứ 1 không 
        // Và phần tử đứng sau có lớn hơn phần tử đứng trước không
        if (i == 0 ||tmp[i - 1] <= tmp[i]) {
        // Kiểm tra tổ hợp có tổng các giá trị phần tử bằng B không
            if (sum == B) {
                printAnswer(i, tmp);
            } else if (sum < B) {
                // Gọi lại hàm đệ quy để xây dựng phần tử tiếp theo
                findCombination(i + 1, N, X, tmp, B, sum);
            }
        }
        // Quay lui phần tử X[i] để thử các khả năng khác
        sum -= X[j];
    }
    
}

int main() {
    // Biến 'N' lưu số lượng phần tử của mảng
    // Và 'B' lưu giá trị tổng cần tìm của các tổ hợp
    int N, B;
    cout << "Nhap vao so luong phan tu cua mang (> 0): "; cin >> N;
    cout << "Nhap vao gia tri tong can tim cua cac to hop (> 0): "; cin >> B;

    // Kiểm tra giá trị đầu vào
    if (N <= 0) {
        cout << "So luong phan tu cua mang phai (> 0)\n";
        return 0;
    }
    if (B <= 0) {
        cout << "Gia tri tong can tim cua cac to hop (> 0)\n";
        return 0;
    }

    // Mảng 'X' lưu giá trị các phần tử của mảng,
    // 'tmp' lưu giá trị của các phần tử của tổ hợp đang được xây dựng
    // Biến 'sum' lưu giá trị tổng các phần tử của tổ hợp đang được xây dựng
    int X[N], tmp[N], sum = 0;
    for (int i = 0; i < N; i++) {
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> X[i];
    }

    // Gọi hàm đệ quy để tìm các tổ hợp
    findCombination(0, N, X, tmp, B, sum);
    return 0;
}