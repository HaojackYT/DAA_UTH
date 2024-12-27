#include <iostream>

using namespace std;

// Hàm đệ quy kiểm tra tính đối xứng của mảng
bool checkSymmetricRe(int a[], int left, int right) {
    if (left >= right) return true; // Điều kiện dừng của đệ quy
    // So sánh cặp giá trị phần tử bên trái với bên phải của hai đầu mảng
    if (a[left] != a[right]) return false;
    // Gọi lại đệ quy với cặp giá trị index tiếp theo của phần tử bên trái với bên phải
    return checkSymmetricRe(a, left + 1, right - 1);
}

// Hàm bao bọc (wrapper function) của hàm đệ quy
bool checkSymmetricRe(int a[], int n) {
    return checkSymmetricRe(a, 0, n - 1);
}

int main() {
    int n; // Biến lưu độ dài của mảng một chiều
    cout << "Nhap vao so luong phan tu cua mang mot chieu (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào
    if (n <= 0) {
        cout << "So luong phan tu cua mang mot chieu phai (> 0)\n";
        return 0;
    }

    int a[n]; // Khai báo mảng có độ dài 'n'
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao gia tri cua a[" << i << "]: "; cin >> a[i];
    }

    // Gọi hàm bao bọc để kiểm tra đối xứng
    bool result = checkSymmetricRe(a, n);

    // Kiểm tra kết quả trả về và hiển thị
    if (result) {
        cout << "Mang mot chieu doi xung\n";
    } else {
        cout << "Mang mot chieu khong doi xung\n";
    }
    return 0;
}