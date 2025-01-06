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
    // Mảng động 2 chiều lưu để lưu kết quả của các chỉnh hợp
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
            
            if (j > i) {
                dp[i][j] = 0;
            }
            
            else {
                dp[i][j] = dp[i - 1][j] + j * dp[i - 1][j - 1];
            }
        }
    }


    int result = dp[N][K];

    for (int i = 0; i <= N; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return result;
}

int main() {
    int N, K;
    cout << " "; cin >> N;
    cout << " "; cin >> K;

    int result = nAkDP(N, K);

    cout << " " << result;
    return 0;
}