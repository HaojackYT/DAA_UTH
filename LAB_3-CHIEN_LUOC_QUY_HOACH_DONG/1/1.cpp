#include <iostream>

using namespace std;

/*
6
1 3 2 8 4 5
*/

/*
4
*/

// Hàm tìm giá trị lớn nhất giữa 2 số nguyên
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Hàm tìm độ dài của dãy con tăng dài nhất (có thể liên tiếp hoặc 0)
// sử dụng chiến lược quy hoạch động
int longestIncreasingSubSequenceDP(float a[], int n) {
    // Mảng lưu độ dài dãy con có thể tạo được tại mỗi vị trí
    int L[n];

    // TH cơ sở: Dãy con chỉ chứa 1 phần tử (chính nó)
    for (int i = 0; i < n; i++) {
        L[i] = 1;
    }

    // Duyệt các phần tử của mảng từ phần tử thứ 2 sang phần tử cuối cùng
    for (int i = 1; i < n; i++) {
        // Duyệt các phần tử đứng trước phần tử hiện tại
        for (int j = 0; j < i; j++) {
            // Kiểm tra giá trị phần tử hiện tại và phần tử đứng trước phần tử hiện tại
            // Nếu giá trị phần tử hiện tại > phần tử đứng trước phần tử hiện tại
            if (a[i] > a[j]) {
                // Cập nhật độ dài dãy con có thể tạo được ở vị trị hiện tại
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }

    int lisLen = 0; // Biến lưu độ dài lớn nhất của mảng 'L'
    for (int i = 0; i < n; i++) {
        if (L[i] > lisLen) {
            lisLen = L[i];
        }
    }

    // Trả về độ dài lớn nhất của mảng 'L'
    return lisLen;
}

int main() {
    int n; // Biến lưu số lượng phần tử của mảng
    cout << "Nhap so luong phan tu cua mang (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào
    if (n <= 0) {
        cout << "So luong phan tu cua mang phai (> 0)\n";
        return 0;
    }

    float a[n]; // Khai báo mảng có độ dài 'n'
    // Nhập vào giá trị các phần tử của mảng
    cout << "Nhap vao gia tri cac phan tu cua mang (cach nhau boi ' '): ";
    for (int i = 0; i < n; i++) cin >> a[i];

    // Gọi hàm tính độ dài của dãy con tăng dài nhất (có thể liên tiếp hoặc 0)
    int result = longestIncreasingSubSequenceDP(a, n);

    // Hiển thị kết quả
    cout << "Do dai cua day con tang dai nhat: "<< result;
    return 0;
}