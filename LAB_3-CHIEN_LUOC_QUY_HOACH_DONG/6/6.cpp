#include <iostream>
#include <string>

using namespace std;

/*
ABCDEF
AXBCYDGH
*/

/*
4
*/

// Hàm tìm giá trị lớn nhất giữa 2 số nguyên
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Hàm tính độ dài dãy con chung dài nhất của 2 chuỗi sử dụng chiến lược quy hoạch động
int longestCommonSubsequence2S(string str1, string str2) {
    // Biến 'str' + i + 'Len' lưu độ dài chuỗi i (i = 1,2)
    int str1Len = str1.size();
    int str2Len = str2.size();

    // Mảng 2 chiều lưu kết quả của quy hoạch động
    int F[str1Len + 1][str2Len + 1];

    // Duyệt các phần tử của chuỗi 1
    for (int i = 0; i <= str1Len; i++) {
        // Duyệt các phần tử của chuỗi 2
        for (int j = 0; j <= str2Len; j++) {
            // TH cơ sở: vị trí i và j == 0 không được dùng để lưu ký tự trong mảng 2 chiều
            if (i == 0 || j == 0) {
                F[i][j] = 0;
            }
            // Các TH còn lại:
            else {
                // TH1: 2 chuỗi có ký tự giống nhau tại vị trí tương ứng của mỗi chuỗi
                if (str1[i - 1] == str2[j - 1]) {
                    // Tăng độ dài dãy con chung của trạng thái hiện tại lên 1
                    F[i][j] = F[i - 1][j - 1] + 1;
                }
                // TH2: 2 chuỗi không có ký tự giống nhau tại các vị trí tương ứng của mỗi chuỗi
                else {
                    // Tìm độ dài lớn nhất từ các trạng thái trước đó để cập nhật cho trạng thái hiện tại
                    F[i][j] = max(F[i][j - 1], F[i - 1][j]);
                }
            }
        }
    }

    // Trả về độ dài dãy con chung dài nhất
    return F[str1Len][str2Len];
}

int main() {
    string str1, str2; // Biến 'str' + i lưu giá trị chuỗi i (i = 1,2)
    // Nhập vào giá trị các chuỗi
    cout << " "; getline(cin, str1);
    cout << " "; getline(cin, str2);

    // Gọi hàm tính độ dài dãy con chung dài nhất của 2 chuỗi
    int result = longestCommonSubsequence2S(str1, str2);

    // Hiển thị kết quả
    cout << "Do dai day con chung dai nhat cua 2 chuoi: " << result;
}