#include <iostream>

using namespace std;

//
void sumOfDigitsRe(int number, int& result) {
    if (number == 0) return; // Điều kiện dừng của đệ quy
    sumOfDigitsRe(number / 10, result); // Gọi lại đệ quy với kết quả của phép chia 10 nhằm loại bỏ số ở hàng đơn vị đối lời gọi đệ quy hiện tại
    result += number % 10; // Cập nhật lại giá trị tổng các chữ số với giá trị ở hàng đơn vị
}

int main() {
    // Biến 'number' lưu giá trị đầu vào
    // Và 'result' lưu tổng các chữ số 
    int number, result = 0;
    cout << "Nhap vao mot so nguyen duong N: "; cin >> number;

    // Kiểm tra giá trị đầu vào
    // Giá trị đầu vào là số âm
    if (number < 0) {
        cout << "Chuong trinh khong ho tro tinh tong cac chu so cua so nguyen am\n";
        return 0;
    }

    // Gọi hàm đệ quy để tính tổng các chữ số
    sumOfDigitsRe(number, result);
    
    // Hiển thị kết quả
    cout << "Tong cac chu so cua " << number << " la " << result << "\n";
    return 0;
}