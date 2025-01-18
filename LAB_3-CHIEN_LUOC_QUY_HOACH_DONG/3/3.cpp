#include <iostream>

using namespace std;

/*
6
5
*/

/*
720
*/

// Hàm tính chỉnh hợp chập K của N sử dụng chiến lược quy hoạch động
int nAkDP(int N, int K) {
    // Mảng động 2 chiều lưu kết quả của các chỉnh hợp
    int **dp = new int *[N + 1];
    for (int i = 0; i <= N; i++) {
        dp[i] = new int[K + 1]();
    }

    // TH cơ sở: Chỉnh hợp chập 0 của i = 1
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }

    // Duyệt qua các phần tử của mảng động 2 chiều
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            // Kiểm tra số phần tử chọn và số phần tử
            // Nếu số phần tử chọn (j) > số phần tử (i)
            if (j > i) {
                // Kết quả giá trị chỉnh hợp = 0
                dp[i][j] = 0;
            }
            // Nếu số phần tử chọn (j) <= số phần tử (i)
            else {
                // Công thức truy hồi của chỉnh hợp:
                // A(N, K) = A(N-1, K) + K * A(N-1, K-1)
                dp[i][j] = dp[i - 1][j] + j * dp[i - 1][j - 1];
            }
        }
    }

    // Biến lưu kết quả chỉnh hợp chập K của N
    int nAk = dp[N][K];

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 2 chiều
    for (int i = 0; i <= N; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    // Trả về kết quả chỉnh hợp chập K của N
    return nAk;
}

int main() {
    int N, K;
    cout << "Nhap vao tong so phan tu (N): "; cin >> N;
    cout << "Nhap vao so phan tu duoc chon (K): "; cin >> K;

    // Gọi hàm tính chỉnh hợp chập K của N
    int result = nAkDP(N, K);

    // Hiển thị kết quả
    cout << "Chinh hop chap " << K << " cua " << " N: " << result;
    return 0;
}