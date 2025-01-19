#include <iostream>

using namespace std;

#define FLOAT_MAX 1e9

/*
4
0 85 26 81
85 0 77 97
26 77 0 26
81 97 26 0
1
*/

/*
234
234
*/

/*
- Tham lam (Greedy)
+ Ý tưởng chính: Chọn thành phố gần nhất ở mỗi bước mà không quan tâm đến toàn bộ lộ trình.
+ Tính tối ưu: Không đảm bảo tối ưu; chỉ đúng trong một số trường hợp đặc biệt.
+ Tính đúng đắn: Không luôn đúng, có thể bỏ qua các lộ trình tối ưu do chỉ xét cục bộ.
+ Thời gian thực thi: O(n^2) do phải duyệt qua các thành phố để tìm thành phố gần nhất.
+ Không gian sử dụng: O(n^2) để lưu bảng chi phí.
+ Ưu điểm: Thời gian thực thi nhanh hơn trong thực tế với số lượng thành phố lớn.
+ Nhược điểm: Không đảm bảo kết quả chính xác.
+ Ví dụ phù hợp: Khi cần tìm một lộ trình chấp nhận được trong thời gian ngắn.
+ Ứng dụng: Các bài toán thực tế cần giải nhanh như robot di chuyển, trò chơi AI.
+ Kết quả: Lộ trình gần đúng, có thể không tối ưu.
*/

/*
- Nhánh và cận (BnB)
+ Ý tưởng chính: Sử dụng nhánh và cận để duyệt toàn bộ các lộ trình có thể, cắt tỉa những
nhánh không tiềm năng.
+ Tính tối ưu: Đảm bảo tìm ra lộ trình tối ưu với tổng khoảng cách nhỏ nhất.
+ Tính đúng đắn: Luôn đúng với mọi trường hợp.
+ Thời gian thực thi: O(n!) trong trường hợp tệ nhất (tất cả các nhánh phải được duyệt).
+ Không gian sử dụng: O(n^2) để lưu bảng chi phí và trạng thái.
+ Ưu điểm: Tìm ra lộ trình tối ưu, áp dụng được cho mọi trường hợp.
+ Nhược điểm: Tốn thời gian hơn, đặc biệt với số lượng thành phố lớn.
+ Ví dụ phù hợp: Khi cần tìm lộ trình chính xác và không quan tâm đến hiệu năng.
+ Ứng dụng: Các hệ thống yêu cầu độ chính xác cao như hoạch định lộ trình giao hàng.
+ Kết quả: Lộ trình tối ưu nhất với tổng khoảng cách nhỏ nhất.
*/

// Hàm tính tổng khoảng cách nhỏ nhất của lộ trình trong bài toán người du lịch (TSP) sử
// dụng chiến lược tham lam
float tspGreedy(float **a, int n, bool visited1[], int tmp1[]) {
    // Biến 'currentCityIndex' lưu chỉ số thành phố hiện tại trong mảng 'tmp1',
    // 'totalDistance' lưu tổng khoảng cách của lộ trình
    int currentCityIndex = 0;
    float totalDistance = 0;
    // Duyệt qua tất cả các thành phố (trừ thành phố xuất phát)
    for (int i = 1; i < n; i++) {
        // Biến 'currentCity' lưu thành phố tiếp theo của lộ trình,
        // 'nextCity' lưu thành phố tiếp theo của lộ trình (-1: Chưa xác định),
        // 'smallestDistanceBetweenCities' lưu khoảng cách nhỏ nhất giữa 2 thành phố
        int currentCity = tmp1[currentCityIndex];
        int nextCity = -1;
        float smallestDistanceBetweenCities = FLOAT_MAX;
        // Duyệt qua tất cả các thành phố
        for (int j = 0; j < n; j++) {
            // Kiểm tra đã đến thành phố 'j' và khoảng cách hiện tại giữa 2 thành phố với
            // khoảng cách nhỏ nhất giữa 2 thành phố
            // Nếu chưa đến thành phố 'j' và khoảnh cách hiện tại giữa 2 thành phố < khoảng
            // cách nhỏ nhất giữa 2 thành phố
            if (!visited1[j] && a[currentCity][j] < smallestDistanceBetweenCities) {
                // Cập nhật khoảng cách nhỏ nhất giữa 2 thành phố với khoảng cách giữa 2
                // thành phố hiện tại
                smallestDistanceBetweenCities = a[currentCity][j];
                nextCity = j; // Cập nhật thành phố tiếp theo của lộ trình
            }
        }
        // Tăng chỉ số thành phố tiếp theo của lộ trình
        currentCityIndex++;
        // Lưu thành phố tiếp theo vào lộ trình
        tmp1[currentCityIndex] = nextCity;
        // Đánh dấu đã đến thành phố tiếp theo của lộ trình
        visited1[nextCity] = true;
    }
    // Duyệt qua các thành phố của lộ trình
    for (int i = 0; i < n - 1; i++) {
        // Cập nhật tổng khoảng cách của lộ trình với khoảng cách giữa 2 thành phố ('i' và
        // 'i + 1') của lộ trình
        totalDistance += a[tmp1[i]][tmp1[i + 1]];
    }
    // Cập nhật tổng khoảng cách của lộ trình với khoảng cách giữa 2 thành phố (Cuối cùng
    // và đầu tiên) của lộ trình
    totalDistance += a[tmp1[n - 1]][tmp1[0]];

    // Trả về tổng khoảng cách của lộ trình
    return totalDistance;
}

// Hàm tìm giá trị lớn nhất giữa 2 số thực
float min(float a, float b) {
    if (a < b) {
        return a;
    }
    return b;
}

// Hàm tính tổng khoảng cách nhỏ nhất của lộ trình trong bài toán người du lịch (TSP) sử
// dụng chiến lược quay lui nhánh và cận
void tspBnB(int i, float **a, int n, float smallestDistanceBetweenCities, bool visited[], int tmp[], float currentDistance, float &smallestTotalDistance) {
    // Duyệt qua tất cả các thành phố
    for (int j = 0; j < n; j++) {
        // Kiểm tra đã đến thành phố hiện tại 'j' trong lộ trình đang xây dựng không ?
        // Nếu chưa đến thành phố hiện tại 'j' trong lộ trình đang xây dựng
        if (!visited[j]) {
            // Đánh dấu đã đến thành phố hiện tại 'j' trong lộ trình đang xây dựng
            visited[j] = true;
            // Lưu thành phố hiện tại 'j' là thành phố thứ 'i' trong lộ trình đang xây dựng
            tmp[i] = j;
            // Cập nhật tổng khoảng cách của lộ trình đang xây dựng với khoảng cách của
            // thành phố thứ 'i - 1' đến thành phố hiện tại 'j'
            currentDistance += a[tmp[i - 1]][tmp[i]];
            
            // Kiểm tra đã đủ n thành phố trong lộ trình đang xây dựng không ?
            // Nếu đã đủ n thành phố trong lộ trình đang xây dựng
            if (i == n - 1) {
                // Cập nhật giá trị tổng khoảng cách nhỏ nhất của lộ trình từng được duyệt
                // dựa trên giá trị bé hơn với tổng khoảng cách của lộ trình hiện tại
                smallestTotalDistance = min(smallestTotalDistance, currentDistance + a[tmp[n - 1]][0]);
            }
            //
            else if (currentDistance + (n - i) * smallestDistanceBetweenCities < smallestTotalDistance) {
                tspBnB(i + 1, a, n, smallestDistanceBetweenCities, visited, tmp, currentDistance, smallestTotalDistance);
            }
            // Quay lui, thành phố hiện tại 'j' để thử các khả năng (lộ trình) khác
            // Đánh dấu chưa đến thành phố hiện tại 'j' trong lộ trình đang xây dựng
            visited[j] = false;
            // Cập nhật tổng khoảng cách của lộ trình đang xây dựng với khoảng cách của
            // thành phố thứ 'i - 1' đến thành phố hiện tại 'j'
            currentDistance -= a[tmp[i - 1]][tmp[i]];
        }
    }
}

int main() {
    // Biến 'n' lưu số lượng thành phố,
    // 's' lưu STT thành phố xuất phất
    int n, s;
    cout << "Nhap vao so luong thanh pho (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào của 'n'    
    if (n <= 0) {
        cout << "So luong phan tu (thanh pho) cua mang phai (> 0)\n";
        return 0;
    }

    // Biến lưu khoảng cách nhỏ nhất giữa 2 thành phố
    float smallestDistanceBetweenCities = FLOAT_MAX;

    // Khai báo mảng động 2 chiều có 'n^2' phần tử: chứa khoảng cách giữa các thành phố
    // với nhau
    float **a = new float *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new float[n];
    }
    cout << "Nhap vao khoang cach giua 2 thanh pho voi moi vi tri tuong ung trong mang (cach nhau boi ' ') (>= 0): ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] < 0) {
                cout << "Khoang cach giua 2 thanh pho voi moi vi tri tuong ung trong mang phai (> 0)\n";
                return 0;
            }
            // Kiểm tra khoảng cách giữa 2 thành phố hiện tại và khoảng cách nhỏ nhất giữa
            // 2 thành phố
            // Nếu khoảng cách giữa 2 thành phố hiện tại != 0 và khoảng cách giữa 2 thành
            // phố hiện tại < khoảng cách nhỏ nhất giữa 2 thành phố
            if (a[i][j] != 0 && a[i][j] < smallestDistanceBetweenCities) {
                // Lưu khoảng cách nhỏ nhất giữa 2 thành phố là khoảng cách giữa 2 thành
                // hiện tại phố
                smallestDistanceBetweenCities = a[i][j];
            }
        }
    }

    cout << "Nhap vao STT thanh pho xuat phat (1 <= s <= " << n << "): "; cin >> s;
    
    // Kiểm tra giá trị đầu vào của 's'
    if (s < 1 || s > n) {
        cout << "STT thanh pho xuat phat phai (1 <= s <= " << n << ")\n";
        delete[] a;
        return 0;
    }

    // Khai báo mảng động có 'n' phần tử: đánh dấu các thành phố trong lộ trình
    // (false: chưa đến, true: đã đến)
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    // Đánh dấu đã đến thành phố xuất phát trong lộ trình
    visited[s - 1] = true;

    // Khai báo mảng động có 'n' phần tử: (giống mảng 'visited')
    bool *visited1 = new bool[n];
    for (int i = 0; i < n; i++) {
        visited1[i] = visited[i]; 
    }

    // Khai báo mảng động có 'n' phần tử: chứa lộ trình tham quan thành phố đang xây dựng
    int *tmp = new int[n];
    // Lưu thành phố xuất phát là thành phố đầu tiên trong lộ trình
    tmp[0] = s - 1;
    
    // Khai báo mảng động có 'n' phần tử: (giống mảng 'tmp')
    int *tmp1 = new int[n];
    tmp1[0] = s - 1;

    // Biến 'currentDistance' lưu tổng khoảng cách của lộ trình hiện tại,
    // 'smallestTotalDistance' lưu tổng khoảng cách nhỏ nhất của lộ trình từng được duyệt
    float currentDistance = 0, smallestTotalDistance = FLOAT_MAX;

    // Gọi hàm giải bài toán người du lịch (TSP)
    tspBnB(1, a, n, smallestDistanceBetweenCities, visited, tmp, currentDistance, smallestTotalDistance);
    float resultGreedy = tspGreedy(a, n, visited, tmp);

    // Hiển thị kết quả
    cout << "Tong khoang cach nho nhat cua lo trinh (BnB): " << smallestTotalDistance;
    cout << "\nTong khoang cach nho nhat cua lo trinh (Greedy): " << resultGreedy;

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 2 chiều 'a'
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 'visited', 'visited1', 'tmp' và 'tmp1'
    delete[] visited;
    delete[] visited1;
    delete[] tmp;
    delete[] tmp1;

    return 0;
}