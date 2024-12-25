#include <iostream>

using namespace std;

// Hàm tính giá trị trung bình của mảng số nguyên sử dụng chiến thuật chia để trị
float calAveValDnC(int a[], int left, int right) {
    // TH cơ sở: mảng chỉ có 1 phần tử
    if (left == right) {
        return a[left];
    }

    // Biến lưu chỉ số phần tử ở giữa để chia mảng thành 2 nửa
    // Nửa bên trái (left, middle) của mảng
    // Nửa bên phải (middle + 1, right) của mảng
    int middle = (left + right) / 2;

    // Biến 'aveLeft' lưu giá trị trung bình của nửa bên trái của mảng,
    // 'aveRight' lưu giá trị trung bình của nửa bên phải của mảng
    float aveLeft = calAveValDnC(a, left, middle);
    float aveRight = calAveValDnC(a, middle + 1, right);

    // Biến 'cntLeft' lưu số lượng phần tử của nửa bên trái của mảng,
    // 'cntRight' lưu số lượng phần tử của nửa bên phải của mảng
    int cntLeft = middle - left + 1;
    int cntRight = right - middle;

    // Trả về giá trị trung bình của giá trị trung bình nửa bên trái và bên phải của mảng
    return (aveLeft * cntLeft + aveRight * cntRight) / (cntLeft + cntRight);
}

int main() {
    int n; // Biến lưu số lượng phần tử của dãy số nguyên
    cout << "Nhap vao so luong phan tu cua day so nguyen (>0): "; cin >> n;

    // Kiểm tra giá trị đầu vào
    if (n <= 0) {
        cout << "So luong phan tu cua day so nguyen phai (>0)\n";
        return 0;
    }

    int a[n]; // Khai báo mảng có độ dài 'n'
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> a[i];
    }

    // Gọi hàm tính giá trị trung bình của mảng
    float result = calAveValDnC(a, 0, n - 1);

    // Hiển thị kết quả
    cout << "Gia tri trung binh cua day so: " << result << "\n";
}