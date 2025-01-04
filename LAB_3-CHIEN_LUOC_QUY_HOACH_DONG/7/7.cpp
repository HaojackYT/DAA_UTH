#include <iostream>

using namespace std;

/*
5
2 5 4 3 15
*/

int calMinCandyDifference(int a[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i];
    }

    int half = total / 2;

    bool *dp = new bool[half + 1]{false};
    dp[0] = true;

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