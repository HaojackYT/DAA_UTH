#include <iostream>

using namespace std;

// 
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}


//
int knapsackDP(int n, int w_balo, int w[], int v[]) {
    //
    int **dp = new int *[n + 1];
    
    //
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[w_balo + 1]();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < w_balo; j++) {
            //
            if (w_balo < w[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            }
            //
            else {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    //
    int largestTotalValInBalo = dp[n][w_balo];

    //
    for (int i = 0; i < n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    
    //
    return largestTotalValInBalo;
}

int main() {
    int n, w_balo;
    cout << " (> 0): "; cin >> n;

    //
    if (n <= 0) {
        cout << " (> 0)\n";
        return 0;
    }

    cout << " (> 0): "; cin >> w_balo;

    //
    if (w_balo <= 0) {
        cout << " (> 0)\n";
        return 0;
    }

    int *w = new int[n];
    int *v = new int[n];
    cout << " (cach nhau boi ' ') (> 0): ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        if (w[i] <= 0) {
            cout << " \n";
            return 0;
        }
    }
    cout << " (cach nhau boi ' ') (> 0): ";
    for (int i = 0; i < n; i++){
        cin >> v[i];
        if (v[i] <= 0) {
            cout << " \n";
            return 0;
        }
    }

    //
    int result = knapsackDP(n, w_balo, w, v);

    //
    cout << " " << result;
    return 0;
}