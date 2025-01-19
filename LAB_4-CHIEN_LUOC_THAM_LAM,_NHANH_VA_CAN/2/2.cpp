#include <iostream>

using namespace std;

/*
5
2 1 4 3 5
*/

/*
135
24
159
*/

// Hàm tìm tổng nhỏ nhất của 2 số nhỏ nhất được tạo từ các số trong mảng sử dụng chiến lược
// tham lam
void findMinSumGreedy(int A[], int n) {
    // Sắp xếp mảng theo thứ tự giá trị tăng dần sử dụng bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Kiểm tra giá trị phần tử trước với giá trị phần tử sau của mảng
            // Nếu giá trị phần tử trước > giá trị phần tử sau
            if (A[i] > A[j]) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }

    // Biến 'num' + 'i' lưu số thứ 'i' nho nhat được tạo từ mảng (i = 1,2)
    int num1 = 0, num2 = 0;

    // Duyệt qua các phần tử của mảng
    for (int i = 0; i < n; i++) {
        // Kiểm tra vị trí các phần tử của mảng
        // Nếu vị trí của phần tử chẵn
        if (i % 2 == 0) {
            // Cập nhật số thứ 1 với giá trị của phần tử ở vị trí chẵn
            num1 = num1 * 10 + A[i];
        }
        // Ngược lại, vị trí của phần tử lẻ
        else {
            // Cập nhật số thứ 2 với giá trị của phần tử ở vị trí lẻ
            num2 = num2 * 10 + A[i];
        }
    }

    // Hiển thị kết quả
    cout << "So nho nhat thu nhat: " << num1;
    cout << "\nSo nho nhat thu hai: " << num2;
    cout << "\nTong nho nhat cua 2 so nho nhat: " << num1 + num2;
}

int main() {
    int n; // Biến lưu số lượng phần tử của mảng
    cout << "Nhap vao so luong phan tu cua mang (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào của 'n'
    if (n <= 0) {
        cout << "So luong phan tu cua mang phai (> 0)\n";
        return 0;
    }

    // Khai báo mảng động có kích thước 'n': chứa giá trị các phần tử
    int *A = new int[n];
    cout << "Nhap vao gia tri cac phan tu voi moi vi tri tuong ung trong mang (cach nhau boi ' ') (> 0): ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] < 0) {
            cout << "Gia tri cac phan tu voi moi vi tri tuong ung trong mang phai (> 0)\n";
            return 0;
        }
    }

    // Gọi hàm tìm tổng nhỏ nhất của 2 số nhỏ nhất được tạo từ các số trong mảng
    findMinSumGreedy(A, n);

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 'A'
    delete[] A;

    return 0;
}