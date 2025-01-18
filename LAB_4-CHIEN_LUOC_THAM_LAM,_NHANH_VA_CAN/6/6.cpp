#include <iostream>

using namespace std;

/*
6
4
2 1 4 3
3 3 4 2
*/

// Hàm tìm giá trị lớn nhất giữa 2 số thực
float max(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}

//
struct Item {
    float w;
    float v;
    float wpv;
};

//
float knapsackGreedy(int n, int w_balo, float w[], float v[]) {
    Item *storage = new Item[n];
    for (int i = 0; i < n; i++) {
        Item tmp = {w[i], v[i], w[i] / v[i]};
        storage[i] = tmp;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (storage[i].wpv <= storage[j].wpv) {
                Item tmp = storage[i];
                storage[i] = storage[j];
                storage[j] = tmp;
            }
        }
    }

    float maxValue = 0;
    int currentTotalWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentTotalWeight + storage[i].w <= w_balo) {
            maxValue += storage[i].v;
            currentTotalWeight += storage[i].w;
        }
    }

    delete[] storage;

    return maxValue;
}

// Hàm tính tổng giá trị đồ vật lớn nhất balo có thể chứa dựa trên trọng lượng
// sử dụng chiến lược quy hoạch động
float knapsackDP(int n, int w_balo, float w[], float v[]) {
    // Mảng động 2 chiều lưu tổng giá trị các đồ vật
    // Hàng tiêu đề: STT đồ vật (0, n)
    // Cột tiêu đề: Trọng lượng balo (0, w_balo) 
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[w_balo + 1]();
    }

    // Duyệt qua các phần tử mảng động 2 chiều
    // Duyệt qua các STT đồ vật (1, n)
    for (int i = 0; i <= n; i++) {
        // Duyệt qua các trọng lượng balo (0, w_balo)
        for (int j = 0; j <= w_balo; j++) {
            // TH cơ sở:
            // -'i == 0': Không chọn đồ vật nào (mặc cho trọng lượng balo)
            // -'j == 0':Trọng lượng balo = 0 => Không thể chọn được đồ vật nào
            // => Tổng giá trị đồ vật = 0
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            // Kiểm tra trọng lượng balo với trọng lượng đồ vật tương ứng
            // Nếu trọng lượng balo < trọng lượng đồ vật
            else if (j < w[i - 1]) {
                // Cập nhật tổng giá trị đồ vật hiện tại dựa trên
                // tổng giá trị đồ vật trước đó 
                dp[i][j] = dp[i - 1][j];
            }
            // Ngược lại, trọng lượng balo >= trọng lượng đồ vật
            else {
                // Cập nhật tổng giá trị đồ vật hiện tại dựa trên giá trị lớn hơn với
                // tổng giá trị đồ vật trước đó (trước khi thêm đồ vật hiện tại) + giá trị đồ vật hiện tại
                dp[i][j] = max(dp[i][j], dp[i - 1][int(j - w[i - 1])] + v[i - 1]);
            }
        }
    }

    // Biến lưu tổng giá trị đồ vật lớn nhất
    int largestTotalValInBalo = dp[n][w_balo];

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 2 chiều
    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    
    // Trả về tổng giá trị đồ vật lớn nhất
    return largestTotalValInBalo;
}

//
struct Node {
    int level;
    float w;
    float v;
    float wpv;
    float upperBound;
};

float calculateUpperBound(Node u, int n, int w_balo, float w[], float v[]) {
    if (u.w >= w_balo) return 0;

    float upperBound = u.v;
    float totalWeight = u.w;

    for (int i = u.level + 1; i < n && totalWeight + w[i] <= w_balo; i++) {
        totalWeight += w[i];
        upperBound += v[i];
    }

    if (u.level + 1 < n) {
        upperBound += (w_balo - totalWeight) * v[u.level + 1] / w[u.level + 1];
    }

    return upperBound;
}

//
float knapsackBnB(int n, int w_balo, float w[], float v[]) {
    // Sắp xếp đồ vật theo tỉ lệ giá trị/trọng lượng giảm dần
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            float r1 = v[j] / w[j];
            float r2 = v[j + 1] / w[j + 1];
            if (r1 < r2) {
                // Hoán đổi giá trị và trọng lượng
                int tempValue = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tempValue;

                int tempWeight = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tempWeight;
            }
        }
    }

    // Hàng đợi đơn giản để lưu trạng thái
    Node queue[1000];
    int front = 0, rear = 0;

    // Nút gốc
    Node u, v;
    u.level = -1;
    u.v = 0;
    u.w = 0;
    u.upperBound = calculateUpperBound(u, n, w_balo, w, v);
    queue[rear++] = u;

    int maxValue = 0;

    // Duyệt cây trạng thái
    while (front < rear) {
        u = queue[front++];

        if (u.upperBound > maxValue) {
            // Nhánh chọn đồ vật
            v.level = u.level + 1;
            v.w = u.w + w[v.level];
            v.v = u.v + v[v.level];

            if (v.weight <= w_balo && v.value > maxValue) {
                maxValue = v.value;
            }

            v.bound = calculateUpperBound(v, n, w_balo, w, v);
            if (v.bound > maxValue && v.weight <= W) {
                queue[rear++] = v;
            }

            // Nhánh không chọn đồ vật
            v.weight = u.w;
            v.value = u.v;
            v.bound = calculateBound(v, n, W, w, v);
            if (v.upperBound > maxValue) {
                queue[rear++] = v;
            }
        }
    }

    return maxValue;
}

int main() {
    // Biến 'w_balo' lưu trọng lượng tối đa có thể chứa của balo,
    // 'n' lưu số lượng phần tử (đồ vật) của mảng
    int w_balo, n;

    cout << "Nhap vao trong luong toi da co the chua cua balo (> 0): "; cin >> w_balo;
    // Kiểm tra giá trị đầu vào của 'w_balo'
    if (w_balo <= 0) {
        cout << " (> 0)\n";
        return 0;
    }

    cout << "Nhap vao so luong phan tu (do vat) cua mang (> 0): "; cin >> n;
    // Kiểm tra giá trị đầu vào của 'n'
    if (n <= 0) {
        cout << " (> 0)\n";
        return 0;
    }

    // Khai báo mảng động có 'n' phần tử: chứa trọng lượng của các đồ vật
    float *w = new float[n];
    cout << "Nhap vao trong luong do vat voi moi vi tri tuong ung trong mang (cach nhau boi ' ') (> 0): ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        if (w[i] <= 0) {
            cout << "Trong luong do vat voi moi vi tri tuong ung trong mang phai (> 0)\n";
            delete[] w;
            return 0;
        }
    }

    // Khai báo mảng động v có 'n' phần tử: chứa giá trị của các đồ vật
    float *v = new float[n];
    cout << "Nhap vao gia tri do vat voi moi vi tri tuong ung trong mang (cach nhau boi ' ') (> 0): ";
    for (int i = 0; i < n; i++){
        cin >> v[i];
        if (v[i] <= 0) {
            cout << "Gia tri do vat voi moi vi tri tuong ung trong mang phai (> 0)\n";
            delete[] w;
            delete[] v;
            return 0;
        }
    }

    // Gọi hàm tính tổng giá trị đồ vật lớn nhất balo có thể chứa dựa trên trọng lượng
    // sử dụng chiến lược quy hoạch động
    float resultDP = knapsackDP(n, w_balo, w, v);
    //
    //
    float resultGreedy = knapsackGreedy(n, w_balo, w, v);

    // Hiển thị kết quả
    cout << "Tong gia tri do vat lon nhat balo co the chua (Tham lam): " << resultGreedy << "\n";
    cout << "Tong gia tri do vat lon nhat balo co the chua (Quy hoach dong): " << resultDP << "\n";

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 'w' và 'v'
    delete[] w;
    delete[] v;
    
    return 0;
}