#include <iostream>

using namespace std;

/*
ABCDEF
AXBCYDGH
ABYCDF
*/

/*
4
*/

// Hàm tìm giá trị lớn nhất giữa 3 số nguyên
int max(int a, int b, int c) {
    if (a > b) {
        if (a > c) {
            return a;
        }
        else {
            return c;
        }
    }
    else {
        if (b > c) {
            return b;
        }
        else {
            return c;
        }
    }
}

// Hàm tính độ dài dãy con chung dài nhất của 3 chuỗi sử dụng chiến lược quy hoạch động
int longestCommonSubsequence3S(string s1, string s2, string s3) {
    // Biến 's' + i + 'Len' lưu độ dài chuỗi i (i = 1,2,3)
    int s1Len = s1.size();
    int s2Len = s2.size();
    int s3Len = s3.size();

    // Mảng 3 chiều lưu kết quả của quy hoạch động
    int F[s1Len + 1][s2Len + 1][s3Len + 1];

    // Duyệt các phần tử của chuỗi 1
    for (int i = 0; i <= s1Len; i++) {
        // Duyệt các phần tử của chuỗi 2
        for (int j = 0; j <= s2Len; j++) {
            // Duyệt các phần tử của chuỗi 3
            for (int k = 0; k <= s3Len; k++) {
                // TH cơ sở: Vị trí i, j hoặc k == 0 không được dùng để lưu ký tự trong mảng 3 chiều
                if (i == 0 || j == 0 || k == 0) {
                    F[i][j][k] = 0;
                }
                // Các TH còn lại:
                else {
                    // TH1: 3 chuỗi có ký tự giống nhau tại vị trí tương ứng của mỗi chuỗi
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                        // Tăng độ dài dãy con chung của trạng thái hiện tại lên 1
                        F[i][j][k] = F[i - 1][j - 1][k - 1] + 1;
                    }
                    // TH2: 3 chuỗi không có ký tự giống nhau tại các vị trí tương ứng của mỗi chuỗi
                    else {
                        // Tìm độ dài lớn nhất từ các trạng thái trước đó để cập nhật cho trạng thái hiện tại
                        F[i][j][k] = max(F[i - 1][j][k], F[i][j - 1][k], F[i][j][k - 1]);
                    }
                }
            }
        }
    }

    // Trả về độ dài dãy con chung dài nhất
    return F[s1Len][s2Len][s3Len];
}

int main() {
    string s1, s2, s3; // Biến 's' + i lưu giá trị chuỗi i (i = 1,2,3)
    // Nhập vào giá trị các chuỗi
    cout << "Nhap vao chuoi 1: "; getline(cin, s1);
    cout << "Nhap vao chuoi 2: "; getline(cin, s2);
    cout << "Nhap vao chuoi 3: "; getline(cin, s3);

    // Gọi hàm tính độ dài dãy con chung dài nhất của 3 chuỗi
    int result = longestCommonSubsequence3S(s1, s2, s3);

    // Hiển thị kết quả
    cout << "Do dai day con chung dai nhat cua 3 chuoi: " << result;
    return 0;
}