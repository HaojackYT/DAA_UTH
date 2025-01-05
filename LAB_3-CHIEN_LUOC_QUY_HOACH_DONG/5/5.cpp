#include <iostream>

using namespace std;

/*
6
3 -4 5 10 7 8
*/

/*
30
*/

// Hàm tìm giá trị lớn nhất giữa hai số thực
float max(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Hàm tìm tổng lớn nhất của dãy con liên tiếp sử dụng chiến lược quy hoạch động
float maxSubSum(float A[], int N) {
    float currentMax = 0; // Biến lưu tổng lớn nhất tạm thời
    float largestMax = 0; // Biến lưu tổng lớn nhất của hàm

    // Duyệt qua từng phần tử trong mảng
    for (int i = 0; i < N; i++) {
        // Cập nhật tổng lớn nhất tạm thời với giá trị phần tử hiện tại
        // Nếu tổng lớn nhất tạm thời sau khi cập nhật <= 0 thì = 0
        currentMax = max(0, currentMax + A[i]);

        // Cập nhật tổng lớn nhất của hàm nếu:
        // Tổng lớn nhất của hàm < Tổng lớn nhất hiện tại
        largestMax = max(currentMax, largestMax);
    }

    // Trả về tổng lớn nhất của hàm
    return largestMax;
}

int main() {
    int N; // Biến lưu số lượng phần tử của mảng
    cout << "Nhap vao so luong phan tu cua mang (> 0): "; cin >> N;

    // Kiểm tra giá trị đầu vào
    if (N <= 0) {
        cout << "So luong phan tu cua mang phai (> 0)\n";
        return 0;
    }

    float A[N]; // Khai báo mảng có độ dài 'N'
    // Nhập vào giá trị các phần tử của mảng
    cout << "Nhap vao gia tri cac phan tu cua mang (cach nhau boi ' '): ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Gọi hàm tìm tổng lớn nhất của dãy con liên tiếp 
    float result = maxSubSum(A, N);

    // Hiển thị kết quả
    cout << "Tong gia tri lon nhat cua day con lien tiep trong mang: " << result;
    return 0;
}