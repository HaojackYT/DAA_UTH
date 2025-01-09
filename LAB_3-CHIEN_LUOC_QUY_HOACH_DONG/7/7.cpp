#include <iostream>

using namespace std;

/*
5
2 5 4 3 15
*/

/*
1
*/

// Hàm tính số lượng kẹo chênh lệch ít nhất khi chia kẹo thành 2 phần sử dụng chiến lược quy hoạch động
int calMinCandyDifference(int a[], int n) {
    int total = 0; // Biến lưu tổng số lượng kẹo của mảng
    for (int i = 0; i < n; i++) {
        total += a[i];
    }

    int half = total / 2; // Biến lưu một nửa số lượng kẹo của mảng

    // Mảng lưu trạng thái các tổng có thể đạt được (0, half)
    // 'dp[j] = true' nếu tổng số lượng viên kẹo 'j' được tạo từ một số gói kẹo
    bool *dp = new bool[half + 1]{false};
    
    // TH cơ sở: Trạng thái tổng số lượng kẹo của 0 = true (không chọn gói kẹo nào)
    dp[0] = true;

    // Duyệt qua các phần tử của mảng
    for (int i = 0; i < n; i++) {
        // Duyệt qua các phần tử của mảng động từ 'half' về 'a[i]'
        for (int j = half; j >= a[i]; j--) {
            // Kiểm tra tổng số lượng viên kẹo trước đó 'j - a[i]' có thể tạo được hay không ? 
            if (dp[j - a[i]] == true) {
                // Tổng số lượng viên kẹo mới có thể tạo được 'j',
                // khi thêm gói kẹo có số lượng viên kẹo 'a[i]'
                dp[j] = true;
            }
            // Ngược lại, tổng số lượng viên kẹo 'j' có thể đạt được trước đó,
            // thì giữ nguyên giá trị của nó
        }
    }

    // Tìm tổng số lượng kẹo lớn nhất của mảng động
    int totalHalf = 0;
    for (int i = half; i >= 0; i--) {
        if (dp[i]) {
            totalHalf = i;
            break;
        }
    }

    // Biến lưu số lượng viên kẹo phần còn lại
    int remainder = total - totalHalf;

    // Giải phóng bộ nhớ đã cấp phát cho mảng động
    delete[] dp;

    // Trả về số lượng kẹo chênh lệch giữa 2 phần   
    return abs(totalHalf - remainder);
}

int main() {
    int n; // Biến lưu số lượng phần tử của mảng
    cout << "Nhap vao so luong goi keo (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào
    if (n <= 0) {
        cout << "So luong goi keo phai (> 0)\n";
        return 0;
    }

    // Khai báo mảng động có độ dài 'n'
    int *a = new int[n];
    cout << "Nhap vao so luong vien keo trong moi goi tuong ung (cach nhau boi ' '): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Gọi hàm tính số lượng kẹo chênh lệch ít nhất khi chia kẹo thành 2 phần
    int result = calMinCandyDifference(a, n);
    
    // Hiển thị kết quả
    cout << "So luong vien keo chenh lech it nhat khi chia keo thanh 2 phan: " << result;
    
    // Giải phóng bộ nhớ đã cấp phát cho mảng động
    delete[] a;
    
    return 0;
}