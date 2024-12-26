#include <iostream>

using namespace std;

// Hàm đếm số lượng số có giá trị bằng k sử dụng chiến thuật chia để trị
int cntKDnC(int a[], int left, int right, int k) {
    // TH cơ sở: mảng chỉ có 1 phần tử
    if (left == right) {
        if (a[left] == k) {
            return 1;
        } else {
            return 0;
        }
    }

    // Biến lưu chỉ số phần tử ở giữa để chia mảng thành 2 nửa
    // Nửa bên trái (left, middle) của mảng
    // Nửa bên phải (middle + 1, right) của mảng
    int middle = (left + right) / 2;
    
    // Biến 'cntLeft' lưu số lượng số có giá trị bằng k nửa bên trái của mảng,
    // 'cntRight' lưu số lượng số có giá trị bằng k nửa bên phải của mảng
    int cntLeft = cntKDnC(a, left, middle, k);
    int cntRight = cntKDnC(a, middle + 1, right, k);

    // Trả về tổng số lượng số có giá trị bằng k nửa bên trái và bên phải của mảng
    return cntLeft + cntRight;
}

// Hàm đếm số lượng số có giá trị lớn hơn x và nhỏ hơn y sử dụng chiến thuật chia để trị
int cntBetweenDnC(int a[], int left, int right, int x, int y) {
    // TH cơ sở: mảng chỉ có 1 phần tử
    if (left == right) {
        if (a[left] > x && a[left] < y) {
            return 1;
        } else {
            return 0;
        }
    }

    // Biến lưu chỉ số phần tử ở giữa để chia mảng thành 2 nửa
    // Nửa bên trái (left, middle) của mảng
    // Nửa bên phải (middle + 1, right) của mảng
    int middle = (left + right) / 2;

    // Biến 'cntLeft' lưu số lượng số có giá trị lớn hơn x và nhỏ hơn y nửa bên trái của mảng,
    // 'cntRight' lưu số lượng số có giá trị lớn hơn x và nhỏ hơn y nửa bên phải của mảng
    int cntLeft = cntBetweenDnC(a, left, middle, x, y);
    int cntRight = cntBetweenDnC(a, middle + 1, right, x, y);

    // Trả về tổng số lượng số có giá trị lớn hơn x và nhỏ hơn y nửa bên trái và bên phải của mảng
    return cntLeft + cntRight;
}

int main() {
    // Biến 'n' lưu số lượng phần tử của mảng số nguyên
    // 'k', 'x', 'y' lưu giá trị các số nguyên để so sánh với các giá trị phần tử của mảng
    int n, k, x, y;
    cout << "Nhap vao so luong phan tu cua mang so nguyen (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào
    if (n <= 0) {
        cout << "So luong phan tu cua mang so nguyen phai (> 0)\n";
        return 0;
    }

    cout << "Nhap vao so nguyen k: "; cin >> k;

    int a[n]; // Khai báo mảng có độ dài 'n'
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao gia tri phan tu " << i + 1 << ": "; cin >> a[i];
    }

    // Gọi hàm đếm số lượng số có giá trị bằng k
    int result1 = cntKDnC(a, 0, n - 1, k);

    cout << "So luong so co gia tri bang k ("<< k << "): " << result1 << "\n";

    cout << "Nhap vao so nguyen x (< y): "; cin >> x;
    cout << "Nhap vao so nguyen y (> x): "; cin >> y;

    // Kiểm tra giá trị đầu vào
    if (x >= y) {
        cout << "Gia tri so nguyen x phai (< y)\n";
        return 0;
    }

    // Hàm đếm số lượng số có giá trị lớn hơn x và nhỏ hơn y
    int result2 = cntBetweenDnC(a, 0, n - 1, x, y);

    cout << "So luong so co gia tri > x ("<< x << ") va < y ("<< y <<"): " << result2 << "\n";
    return 0;
}