#include <iostream>

using namespace std;

// Hàm tìm giá trị lớn nhất giữa hai số thực
float max(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Hàm tính tổng lớn nhất của dãy con trong mảng,
// dãy con không được có 2 phần tử liền kề nhau
// sử dụng chiến lược quy hoạch động
float maxSubSumNonAdjectDP(float A[], int N) {
    // Nếu mảng chỉ có 1 phần tử
    if (N == 1) return A[0];

    // Mảng động lưu giá trị tổng lớn nhất tại mỗi vị trí
    float *dp = new float[N];
    
    // TH cơ sở 1: Tổng lớn nhất tại vị trí đầu tiên
    // là giá trị đầu tiên
    dp[0] = A[0];
    // TH cơ sở 2: Tổng lớn nhất tại vị trí thứ 2
    // là giá trị lớn hơn giữa A[0] và A[1]
    dp[1] = max(A[0], A[1]);

    // Duyệt qua các phần tử của mảng động từ 2 đến N - 1
    for (int i = 2; i < N; i++) {
        // Tổng lớn nhất tại vị trí i:
        // dp[i - 1]: Không chọn phần tử hiện tại
        // dp[i - 2] + A[i]: Chọn phần tử hiện tại
        // (Cập nhật tổng lớn nhất trước đó với giá trị phần tử hiện tại)
        dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);
    }

    // Biến lưu tổng lớn nhất cuối cùng của mảng động
    int maxSum = dp[N - 1];

    // Giải phóng bộ nhớ đã cấp phát động cho mảng
    delete[] dp;

    // Trả về tổng lớn nhất cuối cùng của mảng động
    return maxSum;
}

int main() {
    int N; // Biến lưu số lượng phần tử của mảng
    cout << "Nhap vao so luong phan tu cua mang (> 0): "; cin >> N;

    // Kiểm tra giá trị đầu vào
    if (N <= 0) {
        cout << "So luong phan tu cua mang phai (> 0)\n";
        return 0;
    }

    // Khai báo mảng động có độ dài 'N'
    float *A = new float[N];
    cout << "Nhap vao gia tri cac phan tu cua mang (cach nhau boi ' '): ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Gọi hàm tính tổng lớn nhất của dãy con trong mảng,
    // dãy con không được có 2 phần tử liền kề nhau
    int result = maxSubSumNonAdjectDP(A, N);

    // Hiển thị kết quả
    cout << "Tong lon nhat cua day con trong mang: " << result;
    return 0;
}