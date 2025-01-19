#include <iostream>

using namespace std;

/*
6
4
2 1 4 3
3 3 4 2
*/

/*
8
8
7
*/

/*
- Tham lam (Greedy)
+ Ý tưởng chính: Chọn các vật phẩm theo tỷ lệ giá trị/trọng lượng giảm dần.
+ Tính tối ưu: Không đảm bảo tối ưu cho mọi trường hợp.
+ Tính đúng đắn: Không luôn đúng, có thể bị sai khi vật phẩm có tỷ lệ giá trị/trọng lượng
không phản ánh đúng giá trị tổng thể.
+ Thời gian thực thi: O(n * log(n)) (vì phải sắp xếp) + O(n) (duyệt qua các vật phẩm).
+ Không gian sử dụng: O(n), vì chỉ cần lưu thông tin về các vật phẩm và tỷ lệ giá trị/trọng
lượng.
+ Ưu điểm: Dễ triển khai, nhanh đối với các bài toán đơn giản.
+ Nhược điểm: Không luôn cho kết quả tối ưu, nhất là với các bài toán phức tạp.
+ Ví dụ phù hợp: Bài toán với tỷ lệ giá trị/trọng lượng rõ ràng.
+ Ứng dụng: Balo, lựa chọn tài sản, quyết định mua sắm khi có giới hạn.
+ Kết quả: Có thể không tối ưu nhưng nhanh.
*/

/*
- Quy hoạch động (DP)
+ Ý tưởng chính: Xây dựng bảng với các giá trị tối ưu cho mỗi trọng lượng balo và số lượng
đồ vật.
+ Tính tối ưu: Đảm bảo tối ưu, vì sử dụng quy hoạch động.
+ Tính đúng đắn: Đúng đắn, vì đảm bảo giải quyết tất cả các khả năng.
+ Thời gian thực thi: O(n * w_balo), với n là số đồ vật và w_balo là trọng lượng balo.
+ Không gian sử dụng: O(n * w_balo), vì phải lưu trữ một bảng 2 chiều để tính giá trị tối
ưu.
+ Ưu điểm: Đảm bảo giải pháp tối ưu, có thể xử lý các bài toán phức tạp.
+ Nhược điểm: Tốn bộ nhớ và thời gian đối với các bài toán có n và w_balo lớn.
+ Ví dụ phù hợp: Các bài toán cần tối ưu hóa về thời gian và bộ nhớ, có thể giải quyết với
quy hoạch động.
+ Ứng dụng: Các bài toán tối ưu như tối ưu hóa tài nguyên trong sản xuất.
+ Kết quả: Đảm bảo tối ưu nhưng tốn tài nguyên.
*/

/*
- Nhánh và cận (BnB)
+ Ý tưởng chính: Duyệt qua tất cả các lựa chọn có thể (chọn hoặc không chọn đồ vật) và loại
bỏ các nhánh không tối ưu.
+ Tính tối ưu: Đảm bảo tối ưu, vì loại bỏ các nhánh không tối ưu thông qua cận trên.
+ Tính đúng đắn: Đúng đắn, nếu áp dụng đúng cận và loại bỏ nhánh không cần thiết.
+ Thời gian thực thi: O(2^n) trong trường hợp tồi tệ, vì phải duyệt qua tất cả các lựa chọn
có thể.
+ Không gian sử dụng: O(n), vì chỉ cần lưu thông tin của các đồ vật đã chọn và cận trên.
+ Ưu điểm: Đảm bảo tối ưu, có thể sử dụng để cải thiện các bài toán khó.
+ Nhược điểm: Thời gian thực thi có thể rất lâu đối với bài toán có nhiều vật phẩm.
+ Ví dụ phù hợp: Các bài toán phức tạp, yêu cầu tính toán tối ưu với cận trên.
+ Ứng dụng: Lập lịch công việc, tối ưu hóa các bài toán kết hợp.
+ Kết quả: Đảm bảo tối ưu nhưng tốn thời gian tính toán trong trường hợp n lớn.
*/

// Hàm tìm giá trị lớn nhất giữa 2 số thực
float max(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Khai báo kiểu dữ liệu 'Item' (Vật phẩm)
struct Item {
    float w; // Biến lưu trọng lượng của đồ vật
    float v; // Biến lưu giá trị của đồ vật
    float wpv; // Biến lưu giá trị trên trọng lượng của đồ vật
};

// Hàm tính tổng giá trị đồ vật lớn nhất balo có thể chứa dựa trên trọng lượng sử dụng
// chiến lược tham lam
float knapsackGreedy(int n, int w_balo, float w[], float v[]) {
    // Khai báo mảng động có 'n' phần tử: chứa vật phẩm của các đồ vật
    Item *storage = new Item[n];
    // Duyệt qua các phần tử (trọng lượng, giá trị đồ vật) của mảng 'w' và 'v'
    for (int i = 0; i < n; i++) {
        // Biến lưu vật phẩm tạm thời của đồ vật
        Item tmp = {w[i], v[i], w[i] / v[i]};
        // Cập nhật vật phẩm tạm thời của đồ vật vào mảng
        storage[i] = tmp;
    }

    // Sắp xếp mảng mảng vật phẩm của các đồ vật theo thứ tự giá trị giảm dần sử dụng
    // bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Kiểm tra giá trị 'wpv' phần tử trước với giá trị 'wpv' phần tử sau của mảng
            // Nếu giá trị 'wpv' phần tử trước < giá trị 'wpv' phần tử sau
            if (storage[i].wpv < storage[j].wpv) {
                Item tmp = storage[i];
                storage[i] = storage[j];
                storage[j] = tmp;
            }
        }
    }

    // Biến 'maxValue' lưu tổng giá trị lớn nhất của các đồ vật
    // 'currentTotalWeight' lưu tổng trọng lượng hiện tại của các đồ vật
    float maxTotalValue = 0;
    int currentTotalWeight = 0;

    // Duyệt qua các phần tử của mảng 'storage'
    for (int i = 0; i < n; i++) {
        // Kiểm tra tổng trọng lượng hiện tại với trọng lượng của đồ vật hiện tại và
        if (currentTotalWeight + storage[i].w <= w_balo) {
            // Cập nhật tổng giá trị lớn nhất của các đồ vật với giá trị của đồ vật hiện
            // tại
            maxTotalValue += storage[i].v;
            // Cập nhật tổng trọng lượng hiện tại của các đồ vật với trọng lượng của đồ vật
            // hiện tại
            currentTotalWeight += storage[i].w;
        }
    }

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 'storage'
    delete[] storage;

    // Trả về tổng giá trị lớn nhất của các đồ vật
    return maxTotalValue;
}

// Hàm tính tổng giá trị đồ vật lớn nhất balo có thể chứa dựa trên trọng lượng sử dụng
// chiến lược quy hoạch động
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
                // tổng giá trị đồ vật trước đó (trước khi thêm đồ vật hiện tại) + giá trị
                // đồ vật hiện tại
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

// Hàm tính toán giá trị cận trên (bound) cho bài toán nhánh và cận
float bound(int i, int n, int w_balo, float w[], float v[], int tmp[]) {
    if (i >= n) return 0; // Đã duyệt hết vật phẩm

    float remainingWeight = w_balo; // Trọng lượng còn lại trong balo
    float totalValue = 0; // Giá trị tổng hiện tại

    // Tính toán giá trị đã chọn trước đó
    for (int j = 0; j < i; j++) {
        if (tmp[j] == 1) {
            remainingWeight -= w[j]; // Trừ trọng lượng đã chọn
            totalValue += v[j]; // Thêm giá trị đồ vật đã chọn
        }
    }
    // Nếu trọng lượng còn lại < 0, không thể chứa đồ vật, trả về 0
    if (remainingWeight < 0) return 0;

    // Thử thêm các vật phẩm còn lại vào balo (chọn theo tỉ lệ giá trị/trọng lượng)
    while (i < n && remainingWeight >= w[i]) {
        remainingWeight -= w[i];
        totalValue += v[i];
        i++;
    }
    // Nếu còn trọng lượng mà không đủ chứa vật phẩm tiếp theo, thêm giá trị một phần của vật phẩm
    if (remainingWeight > 0 && i < n) {
        totalValue += v[i] * (float)remainingWeight / w[i];
    }
    // Trả về giá trị cận trên
    return totalValue;
}

// Hàm tính tổng giá trị đồ vật lớn nhất balo có thể chứa dựa trên trọng lượng sử dụng
// chiến lược quay lui nhánh cận
void knapsackBnB(int i, int n, int w_balo, float w[], float v[], int tmp[], int best_tmp[], float &resultBnB, float currentTotalValue) {
    // Điều kiện cắt nhánh: Nếu đã duyệt hết vật phẩm hoặc không còn khả năng cải thiện
    if (i >= n || w_balo < 0 || bound(i, n, w_balo, w, v, tmp) <= resultBnB) {
        return;
    }

    // Duyệt qua các khả năng phần tử 'tmp[i]' có thể nhận được (0 và 1)
    for (int j = 0; j <= 1; j++) {
        tmp[i] = j;
        // TH1: Chọn đồ vật hiện tại
        if (j == 1 && w[i] <= w_balo) {
            // Cập nhật tổng giá trị hiện tại của các đồ vật với giá trị của đồ vật hiện
            // tại
            currentTotalValue += v[i];
            // Kiểm tra tổng giá trị hiện tại của các đồ vật với kết quả của bài toán sử
            // dụng chiến lược quay lui nhánh cận
            if (currentTotalValue > resultBnB) {
                // Cập nhật kết quả của bài toán sử dụng chiến lược quay lui nhánh cận
                resultBnB = currentTotalValue;
                for (int j = 0; j < n; j++) {
                    best_tmp[j] = tmp[j];
                }
            }
            // Gọi lại hàm với đồ vật tiếp theo
            knapsackBnB(i + 1, n, w_balo - w[i], w, v, tmp, best_tmp, resultBnB, currentTotalValue);
            // Quay lui, bỏ vật phẩm vừa chọn
            currentTotalValue -= v[i];
        } 
        // TH2: Không chọn đồ vật hiện tại
        else if (j == 0) {
            // Gọi lại hàm với đồ vật tiếp theo
            knapsackBnB(i + 1, n, w_balo, w, v, tmp, best_tmp, resultBnB, currentTotalValue);
        }
    }
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

    // Khai báo mảng động có 'n' phần tử:
    int *tmp = new int[n];
    for (int i = 0; i < n; i++) {
        tmp[i] = 0;
    }

    // Khai báo mảng động có 'n' phần tử:
    int *best_tmp = new int[n];
    for (int i = 0; i < n; i++) {
        best_tmp[i] = 0;
    }

    // Biến 'resultBnB' lưu kết quả của bài toán chiến lược quay lui nhánh cận,
    // 'currentTotalValue' lưu tổng giá trị hiện tại của các đồ vật
    float resultBnB = 0;
    float currentTotalValue = 0;

    // Gọi hàm tính tổng giá trị đồ vật lớn nhất balo có thể chứa dựa trên trọng lượng
    float resultDP = knapsackDP(n, w_balo, w, v);
    float resultGreedy = knapsackGreedy(n, w_balo, w, v);
    knapsackBnB(0, n, w_balo, w, v, tmp, best_tmp, resultBnB, currentTotalValue);

    // Hiển thị kết quả
    cout << "Tong gia tri do vat lon nhat balo co the chua (Greedy): " << resultGreedy;
    cout << "\nTong gia tri do vat lon nhat balo co the chua (DP): " << resultDP;
    cout << "\nTong gia tri do vat lon nhat balo co the chua (BnB): " << resultBnB;

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 'w' và 'v'
    delete[] w;
    delete[] v;
    
    return 0;
}