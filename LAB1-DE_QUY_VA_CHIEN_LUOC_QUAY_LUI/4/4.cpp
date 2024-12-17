#include <iostream>

using namespace std;

// Hàm đệ quy kiểm tra tính đối xứng của mảng
bool checkSymmetricRe(int arr[], int left, int right) {
    if (left >= right) return true; // Điều kiện dừng của đệ quy
    if (arr[left] != arr[right]) return false; // Kiểm tra lần lượt cặp phần tử bên trái với bên phải của hai đầu mảng
    return checkSymmetricRe(arr, left + 1, right - 1); // Gọi lại đệ quy với cặp giá trị index tiếp theo của phần tử bên trái với bên phải
}

// Hàm bao bọc (wrapper function) của hàm đệ quy
bool checkSymmetricRe(int arr[], int arrlen) {
    return checkSymmetricRe(arr, 0, arrlen - 1);
}

int main() {
    int arrlen; // Biến lưu độ dài của mảng một chiều
    cout << "Nhap vao so luong phan tu cua mang mot chieu (>0): "; cin >> arrlen;
    
    // Kiểm tra giá trị đầu vào
    // Giá trị đầu vào là số nguyên âm
    if (arrlen <= 0) {
        cout << "So luong phan tu cua mang mot chieu phai (>0)\n";
        return 0;
    }
    
    int arr[arrlen]; // Khai báo mảng có độ dài 'arrlen'
    for (int i = 0; i < arrlen; i++) {
        int tmp;
        cout << "Nhap vao gia tri cua a[" << i << "]: "; cin >> tmp;
        arr[i] = tmp;
    }

    //Gọi hàm bao bọc kiểm tra đối xứng
    bool result = checkSymmetricRe(arr, arrlen);

    // Kiểm tra kết quả trả về và hiển thị
    if (result) {
        cout << "Mang mot chieu doi xung\n";
    } else {
        cout << "Mang mot chieu khong doi xung\n";
    }
    return 0;
}