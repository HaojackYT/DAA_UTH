#include <iostream>

using namespace std;

/*
10
7
5
*/

/*
4
*/

// Hàm tìm giá trị lớn nhất giữa 2 số thực
float min(float a, float b) {
    if (a < b) {
        return a;
    }
    return b;
}

// Hàm tính số lượng ngày ít nhất cần phải mua gạo để đáp ứng đủ cho nhu cầu gia đình sử
// dụng chiến lược tham lam
int minDaysToBuyRiceGreedy(float A, int B, float C) {
    // Biến 'totalRiceNeeded' lưu tổng số lượng gạo cần phải mua,
    // 'totalRiceBought' lưu tổng số lượng gạo đã mua,
    // 'numOfDaysNeeded' lưu số lượng ngày cần phải mua gạo,
    // 'currentDayInWeek' lưu ngày hiện tại trong tuần (0: Thứ 2, ..., 6: Chủ nhật)
    float totalRiceNeeded = float(B) * C, totalRiceBought = 0;
    int numOfDaysNeeded = 0, currentDayInWeek = 0;

    // Thực hiện vòng lặp cho đến khi mua đủ số lượng gạo cần phải mua
    while (totalRiceBought < totalRiceNeeded) {
        // Kiểm tra ngày hiện tại trong tuần
        // Nếu ngày hiện tại trong tuần <= 5 (!= 6: Chủ nhật)
        if (currentDayInWeek <= 5) {
            // Cập nhật tổng số lượng gạo đã mua dựa trên giá trị bé hơn giữa số lượng gạo
            // tối đa có thể mua trong 1 ngày và số lượng gạo còn lại cần phải mua
            totalRiceBought += min(A, totalRiceNeeded - totalRiceBought);
            numOfDaysNeeded++; // Tăng số lượng ngày cần phải mua gạo
        }
        currentDayInWeek++; // Chuyển sang ngày tiếp theo trong tuần
        // Kiểm tra ngày hiện tại trong tuần
        // Nếu ngày hiện tại trong tuần > 6 (Qua Chủ nhật)
        if (currentDayInWeek > 6) {
            // Cập nhật lại ngày hiện tại trong tuần
            currentDayInWeek = 0;
        }
    }

    // Trả về số lượng ngày cần phải mua gạo
    return numOfDaysNeeded;
}

int main() {
    // Biến 'A' lưu số lượng gạo tối đa có thể mua trong 1 ngày,
    // 'B' lưu số lượng ngày gia đình cần dùng gạo,
    // 'C' lưu số lượng gạo mỗi ngày gia đình cần
    float A, C; int B;
    cout << "Nhap vao so luong gao toi da co the mua trong 1 ngay (> 0): "; cin >> A;

    // Kiểm tra giá trị đầu vào của 'A'
    if (A <= 0) {
        cout << "So luong gao toi da co the mua trong 1 ngay phai (> 0)\n";
        return 0;
    }

    cout << "Nhap vao so luong ngay gia dinh can gao de dung (> 0): "; cin >> B;

    // Kiểm tra giá trị đầu vào của 'B'
    if (B <= 0) {
        cout << "So luong ngay gia dinh can gao de dung phai (> 0)\n";
        return 0;
    }

    cout << "Nhap vao so luong gao moi ngay gia dinh can (> 0): "; cin >> C;

    // Kiểm tra giá trị đầu vào của 'C'
    if (C <= 0) {
        cout << "So luong gao moi ngay gia dinh can phai (> 0)\n";
        return 0;
    }

    // Gọi hàm tính số lượng ngày ít nhất cần phải mua gạo để đáp ứng đủ cho nhu cầu gia
    // đình
    int result = minDaysToBuyRiceGreedy(A, B, C);

    // Hiển thị kết quả
    cout << "So luong ngay it nhat can phai mua gao de dap ung du cho nhu cau gia dinh: " << result;
    return 0;
}