#include <iostream>
#include <string>

using namespace std;

/*
ABCDEF
AXBCYDGH
*/

/*
4
*/

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int longestCommonSubsequence2S(string str1, string str2) {
    int str1Len = str1.size();
    int str2Len = str2.size();
    int F[str1Len + 1][str2Len + 1];
    for (int i = 0; i <= str1Len; i++) {
        for (int j = 0; j <= str2Len; j++) {
            if (i == 0 || j == 0) {
                F[i][j] = 0;
            }
            else {
                if (str1[i - 1] == str2[j - 1]) {
                    F[i][j] = F[i - 1][j - 1] + 1;
                }
                else {
                    F[i][j] = max(F[i][j - 1], F[i - 1][j]);
                }
            }
        }
    }
    return F[str1Len][str2Len];
}

int main() {
    string str1, str2;
    cout << " "; getline(cin, str1);
    cout << " "; getline(cin, str2);

    int result = longestCommonSubsequence2S(str1, str2);

    cout << " " << result;
}