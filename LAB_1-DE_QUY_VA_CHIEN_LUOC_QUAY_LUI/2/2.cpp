#include <iostream>
#include <string>

using namespace std;

// Hàm đệ quy để in ngược dòng ký tự
void reverseString(string &s, int i, string &result) {
    // Điều kiện dừng của đệ quy
    if (i < 0) return;
    // Lưu ký tự tại vị trí hiện tại vào 'result'
    result += s[i];
    // Gọi lại đệ quy với vị trí trước vị trí hiện tại
    reverseString(s, i - 1, result);
}

int main() {
    // Biến 's' lưu dòng ký tự,
    // 'result' lưu dòng ký tự in ngược
    string s, result;
    cout << "Nhap vao mot dong ky tu: "; getline(cin, s);

    // Hàm đệ quy để in ngược dòng ký tự
    reverseString(s, s.length() - 1, result);

    // Hiển thị kết quả
    cout << "Dong ky tu in nguoc: " << result << "\n";
    return 0;
}