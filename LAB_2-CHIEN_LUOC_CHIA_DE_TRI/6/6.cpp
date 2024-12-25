#include <iostream>

using namespace std;

// Hàm tính giá trị biểu thức a^n sử dụng chiến thuật chia để trị kết hợp đệ quy
float powerDnC(int a, int n) {
    // TH cơ sở: a^0 = 1
    if (n == 0) return 1;

    // TH1: số mũ là số nguyên dương
    if (n > 0) {
        // Nếu số mũ là số chẵn
        if (n % 2 == 0) {
            int half = powerDnC(a, n / 2);
            return half * half; // (a^(n/2) * a^(n/2) = a^n)
        }
        // Nếu số mũ là số lẻ
        else {
            return a * powerDnC(a, n - 1); // a * a^(n-1) = a^n
        }
    }
    // TH2: số mũ là số nguyên âm
    else {
        return 1 / powerDnC(a, -n);
    }
}

int main() {
    int a, n; // Biến 'a' lưu giá trị của cơ số, 'n' lưu giá trị của số mũ
    cout << "Nhap vao co so a: "; cin >> a;
    cout << "Nhap vao so mu n: "; cin >> n;

    // Gọi hàm tính giá trị biểu thức a^n
    float result = powerDnC(a, n);

    // Hiển thị kết quả
    cout << "Gia tri cua bieu thuc (" << a << ")^" << n << " = " << result;
}