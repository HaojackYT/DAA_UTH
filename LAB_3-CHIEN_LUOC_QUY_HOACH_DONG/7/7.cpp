#include <iostream>

using namespace std;

/*
5
2 5 4 3 15
*/

/*
1
*/

// Hàm tính sự chênh lệch ít nhất khi chia kẹo thành 2 phần sử dụng chiến lược quy hoạch động
int calMinCandyDifference(int a[], int n) {
    int total = 0; // Biến lưu tổng số lượng kẹo của mảng
    for (int i = 0; i < n; i++) {
        total += a[i];
    }

    int half = total / 2; // Biến lưu một nửa số lượng kẹo của mảng

    // Mảng lưu trạng thái các tổng có thể đạt được (0, half)
    bool *dp = new bool[half + 1]{false};
    
    // TH cơ sở:
    dp[0] = true;

    //
    for (int i = 0; i < n; i++) {
        for (int j = half; j >= a[i]; j--) {
            dp[j] = dp[j] || dp[j - a[i]];
        }
    }

    int totalHalf = 0;
    for (int i = half; i >= 0; i--) {
        if (a[i]) {
            totalHalf = i;
            break;
        }
    }

    int remainder = total - totalHalf;

    delete[] dp; // Giải phóng bộ nhớ cấp phát động

    return abs(totalHalf - remainder);
}

int main() {
    int n;
    cout << " "; cin >> n;

    int *a = new int[n];
    cout << " ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = calMinCandyDifference(a, n);
    
    cout << " " << result;
    return 0;
}