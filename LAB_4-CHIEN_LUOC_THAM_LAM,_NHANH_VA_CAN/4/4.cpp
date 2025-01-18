#include <iostream>

using namespace std;

/*
AAABBC
*/

/*
Co the sap lai chuoi S theo yeu cau
*/

// Hàm kiểm tra có thể sắp xếp các ký tự trong chuỗi S để 2 ký tự liền kề nhau không giống
// nhau hay không ?
bool canRearrange(string S, int n) {
    // Mảng lưu số lần xuất hiện của mỗi ký tự in hoa ('A' đến 'Z')
    int cnt[26] = {0};

    // Duyệt qua các ký tự của chuỗi ký tự 'S'
    for (int i = 0; i < n; i++) {
        // Tăng giá trị mảng 'cnt' tại vị trí tương ứng với ký tự 'S[i]'
        cnt[S[i] - 'A']++;
    }

    int maxCnt = 0; // Biến lưu số lần xuất hiện lớn nhất của một ký tự
    // Duyệt qua các ký tự từ 'A' đến 'Z' trong mảng 'cnt'
    for (int i = 0; i < 26; i++) {
        // Kiểm tra số lần xuất hiện của ký tự tương ứng so với số lần xuất hiện lớn nhất
        // của một ký tự
        if (cnt[i] > maxCnt) {
            maxCnt = cnt[i];
        }
    }
    
    // Nếu số lần xuất hiện lớn nhất của một ký tự > (n + 1) / 2 thì không thể sắp xếp lại
    // các ký tự trong chuỗi ký tự được
    if (maxCnt > (n + 1) / 2) {
        return false;
    }
    return true;
}

int main() {
    string S; // Biến lưu chuỗi ký tự
    cout << "Nhap vao chuoi ky tu S (gom cac ky tu in hoa): "; getline(cin, S);

    // Biến lưu độ dài chuỗi ký tự
    int n = S.length();

    // Kiểm tra giá trị đầu vào của 'S'
    for (int i = 0; i < n; i++) {
        if (S[i] >= 'a' && S[i] <= 'z') {
            cout << "Chuoi ky tu S phai (gom cac ky tu in hoa)\n";
            return 0;
        }
    }

    // Kiểm tra và hiển thị kết quả
    if (canRearrange(S, n)) {
        cout << "Co the sap lai chuoi S theo yeu cau\n";
    } else {
        cout << "Khong the sap lai chuoi S theo yeu cau\n";
    }
    return 0;
}