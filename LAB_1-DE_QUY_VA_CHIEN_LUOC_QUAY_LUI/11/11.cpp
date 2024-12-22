#include <iostream>

using namespace std;

// Hàm hiển thị kết quả của biểu thức
void printAnswer(int N, float X[], int numberOfOperators, char tmp[], int result) {
    
    for (int i = 0; i < N - 1; i++) {
        cout << X[i] << " " << tmp[i] << " ";
    }
    cout << X[N - 1] << " = " << result << "\n";
}

// Hàm tính toán giá trị của biểu thức dựa trên các toán hạng và toán tử
float calculate(int N, float X[], int numberOfOperators, char tmp[]) {
    // Mảng 'tmpX' lưu giá trị các phần tử (toán hạng) của 'X'
    // Và 'secondOperators' lưu giá trị các phần tử (toán tử) còn lại sau khi xử lý các phép toán nhân (*) và chia (/)
    float tmpX[N]; char secondOperators[numberOfOperators]; 
    // Chỉ số của 
    int secondOperatorsIndex = 0;

    // Sao chép các toán hạng từ mảng 'X' sang 'tmpX'
    for (int i = 0; i < N; i++) {
        tmpX[i] = X[i];
    }

    // B1: Xử lý các phép toán nhân (*) và chia (/) trước
    // Duyệt các khả năng phần tử (toán tử) tmp[j] có thể nhận được
    for (int i = 0, j = 0; j < numberOfOperators; j++) {
        switch (tmp[j]) {
            // Toán tử là phép nhân (*)
            case '*':
                // Nhân toán hạng thứ 'i' và toán hạng thứ 'i + 1'
                // Và gán kết quả cho toán hạng thứ 'i'
                tmpX[i] *= tmpX[i + 1];
                // Di chuyển tất cả giá trị các toán hạng trong 'tmpX' từ phải qua trái 1 vị trí
                // Nhằm xóa bỏ toán hạng thứ i + 1
                for (int k = i + 1; k < N - 1; k++) {
                    tmpX[k] = tmpX[k + 1];
                }
                N--; // Giảm số lượng toán hạng
                break;
            // Toán tử là phép chia (/)
            case '/':
                // Kiểm tra giá trị toán hạng thứ 'i + 1' (số bị chia) khác 0
                if (tmpX[i + 1] == 0) {
                    return 1e9;
                }
                // Chia toán hạng thứ 'i' cho toán hạng thứ 'i + 1'
                // Và gán kết quả cho toán hạng thứ 'i'
                tmpX[i] /= tmpX[i + 1];
                // Di chuyển tất cả giá trị các toán hạng trong 'tmpX' từ phải qua trái 1 vị trí
                // Nhằm xóa bỏ toán hạng thứ i + 1
                for (int k = i + 1; k < N - 1; k++) {
                    tmpX[k] = tmpX[k + 1];
                }
                N--; // Giảm số lượng toán hạng
                break;
            // Toán tử là phép cộng (+) hoặc trừ (-)
            default:
                // Lưu lại các toán tử vào 'secondOperators'
                secondOperators[i] = tmp[j];
                secondOperatorsIndex++; // Tăng chỉ số toán tử của 'secondOperators'
                i++; // Tăng chỉ số toán hạng của 'tmpX' 
                break;
        }
    }

    // B2: Xử lý các phép toán cộng (+) và trừ (-) sau đó
    // Lấy kết quả của B1 thông qua phần tử đầu tiên của 'tmpX'
    float result = tmpX[0];
    // Duyệt các khả năng phần tử (toán tử) secondOperators[j] có thể nhận được 
    for (int i = 1, j = 0; j < secondOperatorsIndex; i++, j++) {
        switch (secondOperators[j]) {
            // Toán tử là phép cộng (+)
            case '+':
                result += tmpX[i];
                break;
            // Toán tử là phép trừ (-)
            case '-':
                result -= tmpX[i];
                break;
        }
    }

    // Trả về kết quả của biểu thức
    return result;
}

void completeExpression(int i, int N, float X[], char operators[4], int numberOfOperators, char tmp[], float result) {
    // Duyệt các khả năng phần tử (toán tử) tmp[j] có thể nhận được ('+','-','*','/')
    for (int j = 0; j < 4; j++) {
        tmp[i] = operators[j];
        // Kiểm tra đã đủ numberOfOperators toán tử cho một biểu thức không   
        if (i == numberOfOperators - 1) {
            // Kiểm tra kết quả của biểu thức có phải kết quả yêu cầu không
            if (calculate(N, X, numberOfOperators, tmp) == result) {
                printAnswer(N, X, numberOfOperators, tmp, result);
            }
        } else {
            // Gọi lại hàm đệ quy để xây dựng toán tử tiếp theo
            completeExpression(i + 1, N, X, operators, numberOfOperators, tmp, result);
        }
    }
}

int main() {
    // Biến 'N' lưu số lượng toán hạng của biểu thức,
    // 'numberOfOperators' lưu số lượng toán tử của biểu thức,
    // 'result' lưu kết quả yêu cầu của biểu thức
    int N, numberOfOperators, result;
    cout << "Nhap vao so luong toan hang cua bieu thuc (>0): "; cin >> N;
    
    // Kiểm tra giá trị đầu vào
    if (N <= 0) {
        cout << "So luong toan hang cua bieu thuc phai (>0)\n";
        return 0;
    }

    cout << "Nhap vao so luong toan tu cua bieu thuc: "; cin >> numberOfOperators;
    
    // Kiểm tra giá trị đầu vào
    if (numberOfOperators <= 0) {
        cout << "So luong toan tu cua bieu thuc phai (>0)\n";
        return 0;
    }

    cout << "Nhap vao ket qua yeu cau cua bieu thuc: "; cin >> result;

    float X[N]; // Mảng lưu giá trị các toán hạng của biểu thức
    for (int i = 0; i < N; i++) {
        cout << "Nhap vao gia tri toan hang thu " << i + 1 << ": "; cin >> X[i];
    }
    
    // Mảng 'tmp' lưu các toán tử của biểu thức đang được xây dựng
    // 'operators' lưu các toán tử sẽ có trong bất kỳ biểu thức
    char tmp[numberOfOperators], operators[] = {'+', '-', '*', '/'};
    completeExpression(0, N, X, operators, numberOfOperators, tmp, result);
    return 0;
}