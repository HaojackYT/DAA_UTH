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

int longestCommonSubsequence3S(string s1, string s2, string s3) {
    int s1Len = s1.size();
    int s2Len = s2.size();
    int s3Len = s3.size();
    int F[s1Len + 1][s2Len + 1][s3Len + 1];
    for (int i = 0; i <= s1Len; i++) {
        for (int j = 0; j <= s2Len; j++) {
            for (int k = 0; k <= s3Len; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    F[i][j][k] = 0;
                }
                else {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                        F[i][j][k] = F[i - 1][j - 1][k - 1] + 1;
                    }
                    else {
                        F[i][j][k] = max(F[i - 1][j][k], F[i][j - 1][k], F[i][j][k - 1]);
                    }
                }
            }
        }
    }
    return F[s1Len][s2Len][s3Len];
}

int main() {
    string s1, s2, s3;
    cout << " "; getline(cin, s1);
    cout << " "; getline(cin, s2);
    cout << " "; getline(cin, s3);

    int result = longestCommonSubsequence3S(s1, s2, s3);

    cout << " " << result;
    return 0;
}