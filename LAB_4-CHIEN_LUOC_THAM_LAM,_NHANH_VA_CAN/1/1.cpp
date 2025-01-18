#include <iostream>

using namespace std;

/*
5
3 1 4 5 1
*/

/*
39
*/

// Hàm tính tổng lớn nhất của A[i] * i trong mảng sử dụng chiến lược tham lam
float maxCombinationSumInArrGreedy(float A[], int n) {
    // Sắp xếp mảng theo thứ tự giá trị tăng dần sử dụng bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Kiểm tra giá trị phần tử trước với giá trị phần tử sau của mảng
            // Nếu giá trị phần tử trước > giá trị phần tử sau
            if (A[i] > A[j]) {
                // Hoán đổi giá trị 2 phần tử
                float tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }

    // Biến lưu tổng lớn nhất của A[i] * i trong mảng
    float maxSum = 0;
    for (int i = 0; i < n; i++) {
        maxSum += A[i] * i;
    }

    // Trả về tổng lớn nhất của A[i] * i trong mảng
    return maxSum;
}

int main() {
    int n; // Biến lưu số lượng phần tử của mảng
    cout << "Nhap vao so luong phan tu cua mang (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào của 'n'
    if (n <= 0) {
        cout << "So luong phan tu cua mang phai (> 0)\n";
        return 0;
    }

    // Khai báo mảng động có kích thước 'n': chứa giá trị của các phần tử
    float *A = new float[n];
    cout << "Nhap vao gia tri phan tu voi moi vi tri tuong ung (cach nhau boi ' '): ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Gọi hàm tính tổng lớn nhất của A[i] * i trong mảng
    float result = maxCombinationSumInArrGreedy(A, n);

    // Hiển thị kết quả
    cout << "Tong lon nhat cua A[i] * i trong mang: " << result;

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 'A'
    delete[] A;

    return 0;
}