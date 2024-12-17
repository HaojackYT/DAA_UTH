#include <iostream>

using namespace std;

void printAnswer(int N, int X[], int numberOfOperators, char tmp[], int result) {
    for (int i = 0; i < N - 1; i++) {
        cout << X[i] << " " << tmp[i] << " ";
    }
    cout << X[N - 1] << " = " << result << endl;
}

float calculate(int N, int X[], int numberOfOperators, char tmp[]) {
    float temp[N];
    char tempOps[numberOfOperators];
    int tempIndex = 0;

    // Sao chép toán hạng vào mảng tạm
    for (int i = 0; i < N; i++) {
        temp[i] = X[i];
    }

    // Xử lý * và / trước
    for (int i = 0, j = 0; j < numberOfOperators; j++) {
        switch (tmp[j]) {
            case '*':
                temp[i] *= temp[i + 1];
                for (int k = i + 1; k < N - 1; k++) {
                    temp[k] = temp[k + 1];
                }
                N--;
                break;
            case '/':
                if (temp[i + 1] == 0) return 1e9; // Tránh chia cho 0
                temp[i] /= temp[i + 1];
                for (int k = i + 1; k < N - 1; k++) {
                    temp[k] = temp[k + 1];
                }
                N--;
                break;
            default:
                tempOps[tempIndex++] = tmp[j];
                i++;
                break;
        }
    }

    // Xử lý + và -
    float result = temp[0];
    for (int i = 1, j = 0; j < tempIndex; i++, j++) {
        switch (tempOps[j]) {
            case '+':
                result += temp[i];
                break;
            case '-':
                result -= temp[i];
                break;
        }
    }

    return result;
}

void completeExpression(int i, int N, int X[], char operators[3], int numberOfOperators, char tmp[], float result) {
    for (int j = 0; j < 4; j++) {
        tmp[i] = operators[j];
        if (i == numberOfOperators - 1) {
            if (calculate(N, X, numberOfOperators, tmp) == result) {
                printAnswer(N, X, numberOfOperators, tmp, result);
            }
        } else {
            completeExpression(i + 1, N, X, operators, numberOfOperators, tmp, result);
        }
    }
}

int main() {
    int N, numberOfOperators, result;
    cout << "Nhap vao so luong toan hang cua bieu thuc: "; cin >> N;
    cout << "Nhap vao so luong toan tu cua bieu thuc: "; cin >> numberOfOperators;
    cout << "Nhap vao ket qua cua bieu thuc: "; cin >> result;
    int X[N];
    char tmp[numberOfOperators];
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    char operators[] = {'+', '-', '*', '/'};
    completeExpression(0, N, X, operators, numberOfOperators, tmp, result);
}