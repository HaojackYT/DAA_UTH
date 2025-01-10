#include <iostream>

using namespace std;

#define INT_MAX 10000

int exchangeCash(int n, int k, int denomination[]) {
    //
    int *dp = new int[n + 1];
    //
    for (int i = 0; i <= k; i++) {
        dp[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (i >= denomination[k]) {
                dp[i] = min(dp[i], dp[i - denomination[j] + 1]);
            }
        }
    }

    if (dp[n] != INT_MAX) {
        return dp[n];
    } 
    else {
        return -1;
    }
}

int main() {

    return 0;
}