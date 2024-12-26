#include <iostream>

using namespace std;

// Hàm tìm giá trị nhỏ nhất của một mảng số nguyên sử dụng chiến thuật chia để trị
int findMinValDnC(int A[], int left, int right) {
    // TH cơ sở: mảng chỉ có 1 phần tử
    if (left == right) {
        return A[left];
    }

    // Biến lưu chỉ số phần tử ở giữa để chia mảng thành 2 nửa
    // Nửa bên trái (left, middle) của mảng
    // Nửa bên phải (middle + 1, right) của mảng
    int middle = (left + right) / 2;
    
    // Biến 'minLeft' lưu giá trị phần tử nhỏ nhất ở nửa bên trái của mảng,
    // 'minRight' lưu giá trị phần tử nhỏ nhất ở nửa bên phải của mảng
    int minLeft = findMinValDnC(A, left, middle);
    int minRight = findMinValDnC(A, middle + 1, right);

    // Trả về giá trị nhỏ nhất giữa nửa bên trái và bên phải của mảng
    if (minLeft < minRight) {
        return minLeft;
    } else {
        return minRight;
    }
} 

int main() {
    int n; // Biến lưu số lượng phần tử của mảng số nguyên A
    cout << "Nhap vao so luong phan tu cua mang so nguyen A (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào
    if (n <= 0) {
        cout << "So luong phan tu cua mang so nguyen A phai (> 0)\n";
    }

    int A[n]; // Khai báo mảng có độ dài 'n'
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> A[i];
    }

    // Gọi hàm tìm giá trị nhỏ nhất của mảng
    int result = findMinValDnC(A, 0, n - 1);

    // Hiển thị kết quả
    cout << "Gia tri nho nhat cua mang: " << result << "\n";
}