#include <iostream>

using namespace std;

#define INT_MAX 10000

/*
11
3
1 5 7
*/

/*
5
3
*/

/*
- Tham lam (Greedy)
+ Ý tưởng chính: Chọn mệnh giá lớn nhất có thể tại mỗi bước, giảm dần số tiền cần đổi.
+ Tính tối ưu: Không luôn luôn đảm bảo tối ưu. Chỉ đúng với hệ thống mệnh giá có tính chất
tham lam.
+ Tính đúng đắn: Phụ thuộc vào hệ thống mệnh giá đồng tiền. Ví dụ, với các mệnh giá không
chuẩn như {1, 3, 4}, Greedy không đảm bảo tối ưu.
+ Thời gian thực thi: O(k * log(k) + k) (sắp xếp và duyệt qua mệnh giá).
+ Không gian sử dụng: O(k) (mảng chứa mệnh giá).
+ Độ phức tạp cài đặt: Đơn giản.
+ Ví dụ phù hợp: Hệ thống mệnh giá có tính chất tham lam, ví dụ: {1, 5, 10, 20}.
+ Ưu điểm: Nhanh hơn khi mệnh giá có tính chất tham lam, code ngắn gọn, dễ hiểu.
+ Nhược điểm: Không áp dụng được cho các hệ thống mệnh giá không có tính chất tham lam.
*/

/*
- Quy hoạch động (DP)
+ Ý tưởng chính: Xây dựng giải pháp tối ưu bằng cách chia nhỏ bài toán thành các bài toán
con.
+ Tính tối ưu: Đảm bảo luôn luôn tìm được số lượng đồng tiền nhỏ nhất.
+ Tính đúng đắn: Đúng với mọi hệ thống mệnh giá đồng tiền.
+ Thời gian thực thi: O(n * k), với n là số tiền cần đổi.
+ Không gian sử dụng: O(n) (mảng DP để lưu trữ trạng thái).
+ Độ phức tạp cài đặt: Phức tạp hơn do phải sử dụng mảng trạng thái và các phép cập nhật.
+ Ví dụ phù hợp: Bất kỳ hệ thống mệnh giá nào, kể cả mệnh giá không chuẩn.
+ Ưu điểm: Kết quả tối ưu trong mọi trường hợp.
+ Nhược điểm: Tốn tài nguyên hơn khi xử lý số tiền lớn hoặc hệ thống nhiều mệnh giá.
*/

// Hàm tìm giá trị lớn nhất giữa 2 số nguyên
int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

// Hàm tính số lượng đồng tiền nhỏ nhất dựa trên số lượng tiền cần chuyển đổi và
// mệnh giá đồng tiền sử dụng chiến lược tham lam
int exchangeSmallestNumOfCoinsGreedy(int n, int k, int denomination[]) {
    // Sắp xếp mảng mệnh giá đồng tiền theo thứ tự giá trị giảm dần sử dụng bubble sort
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            // Kiểm tra giá trị phần tử trước với giá trị phần tử sau của mảng
            // Nếu giá trị phần tử trước < giá trị phần tử sau
            if (denomination[i] < denomination[j]) {
                int tmp = denomination[i];
                denomination[i] = denomination[j];
                denomination[j] = tmp;
            }
        }
    }

    int cnt = 0; // Biến đếm số lượng đồng tiền
    for (int i = 0; i < k; i++) {
        // Cập nhật số lượng đồng tiền sau khi chuyển đổi mệnh giá đồng tiền hiện tại
        cnt += n / denomination[i];
        // Cập nhật số lượng tiền còn lại sau khi chuyển đổi sang mệnh giá đồng tiền hiện
        // tại
        n %= denomination[i];
    }

    // Trả về số lượng đồng tiền
    return cnt;
}

// Hàm tính số lượng đồng tiền nhỏ nhất dựa trên số lượng tiền cần chuyển đổi và
// mệnh giá đồng tiền sử dụng chiến lược quy hoạch động
int exchangeSmallestNumOfCoinsDP(int n, int k, int denomination1[]) {
    // Mảng động lưu số lượng đồng tiền
    // Cột tiêu đề: Số tiền cần chuyển đổi (0, n) 
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }

    // TH cơ sở: Không cần đồng nào để chuyển đổi số tiền là 0
    dp[0] = 0;

    // Duyệt qua các phần tử của mảng động
    // Duyệt qua các số tiền cần được chuyển đổi (1, n)
    for (int i = 1; i <= n; i++) {
        // Duyệt qua các mệnh giá đồng tiền của mảng 'denomination1'
        for (int j = 0; j < k; j++) {
            // Kiểm tra số tiền cần được chuyển đổi với mệnh giá đồng tiền
            // Nếu số tiền cần được chuyển đổi >= mệnh giá đồng tiền
            if (i >= denomination1[j]) {
                // Cập nhật số lượng đồng tiền dựa trên giá trị nhỏ hơn với
                // số lượng đồng tiền trước đó (trước khi thêm mệnh giá đồng tiền hiện tại) + 1
                dp[i] = min(dp[i], dp[i - denomination1[j]] + 1);
            }
        }
    }
    
    // Biến lưu số lượng đồng tiền nhỏ nhất
    int smallestNumOfCoins = dp[n];

    // Giải phóng bộ nhớ đã cấp phát cho mảng
    delete[] dp;

    // Trả về số lượng đồng tiền nhỏ nhất
    if (smallestNumOfCoins != INT_MAX) {
        return dp[n];
    } 
    else {
        return -1;
    }
}

int main() {
    // Biến 'n' lưu số lượng tiền cần chuyển đổi,
    // 'k' lưu số lượng mệnh giá đồng tiền
    int n, k;
    cout << "Nhap vao so luong tien can chuyen doi (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào của 'n'
    if (n <= 0) {
        cout << "So luong tien can chuyen doi phai (> 0)\n";
        return 0;
    }

    cout << "Nhap vao so luong menh gia dong tien (> 0): "; cin >> k;

    // Kiểm tra giá trị đầu vào của 'k'
    if (k <= 0) {
        cout << "So luong menh gia dong tien phai (> 0)\n";
        return 0;
    }

    // Khai báo mảng động có kích thước 'n': chứa các mệnh giá đồng tiền 
    int *denomination = new int[k];
    cout << "Nhap vao menh gia dong tien voi moi vi tri tuong ung trong mang (cach nhau boi ' ') (> 0)(cach nhau boi ' ') (> 0): ";
    for (int i = 0; i < k; i++) {
        cin >> denomination[i];
        if (denomination[i] <= 0) {
            cout << "Menh gia dong tien voi moi vi tri tuong ung trong mang phai (> 0)\n";
            return 0;
        }
    }

    // Khai báo mảng động có kích thước 'n': (giống mảng 'denomination')
    int *denomination1 = new int[k];
    for (int i = 0; i < k; i++) {
        denomination1[i] = denomination[i];
    }

    // Gọi hàm tính số lượng đồng tiền nhỏ nhất dựa trên số lượng tiền cần chuyển đổi và
    // mệnh giá đồng tiền
    int resultGreedy = exchangeSmallestNumOfCoinsGreedy(n, k, denomination);
    int resultDP = exchangeSmallestNumOfCoinsDP(n, k, denomination1);

    // Hiển thị kết quả
    cout << "So luong dong tien nho nhat (Greedy): " << resultGreedy;
    cout << "\nSo luong dong tien nho nhat (DP): " << resultDP;

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 'denomination' và 'denomination1'
    delete[] denomination;
    delete[] denomination1;

    return 0;
}