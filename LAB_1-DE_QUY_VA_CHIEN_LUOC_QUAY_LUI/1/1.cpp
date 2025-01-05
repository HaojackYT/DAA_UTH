#include <iostream>
#include <string>

using namespace std;

// Hàm chuyển đổi số thập phân (10) sang nhị phân (2) sử dụng đệ quy
void De2BiRe(int number, string& result) {
    if (number == 0) return; // Điều kiện dừng của đệ quy
    // Gọi lại đệ quy với kết quả của phép chia 2 nhằm cập nhật lại giá trị đầu vào
    De2BiRe(number / 2, result);
    // Tính số dư của phép chia 2 nhằm tạo thành các giá trị 0 và 1
    int remainder = number % 2;
    // Thực hiện nối chuỗi với kiểu dữ liệu string để lưu kết quả đệ quy
    result += to_string(remainder);
}

int main() {
    int number; // Biến lưu giá trị đầu vào
    cout << "Nhap vao mot so tu he thap phan (10) sang he nhi phan (2): "; cin >> number;
    string result = ""; // Chuỗi lưu kết quả chuyển đổi sang hệ nhị phân (2)
    
    // Kiểm tra giá trị đầu vào
    // TH1: Giá trị đầu vào là số âm
    if (number < 0) {
        cout << "Chuong trinh khong ho tro chuyen so am sang he nhi phan (2)\n";
        return 0;
    }
    // TH2: Giá trị đầu vào là 0
    if (number == 0) {
        cout << "So 0 tu he thap phan (10) sang 0 he nhi phan (2)\n";
        return 0;
    }
    
    // Gọi hàm đệ quy để thực hiện chuyển đổi
    De2BiRe(number, result);

    // Hiển thị kết quả
    cout << "So " << number << " tu he thap phan (10) sang " << result << " he nhi phan (2)\n";
    return 0;
}