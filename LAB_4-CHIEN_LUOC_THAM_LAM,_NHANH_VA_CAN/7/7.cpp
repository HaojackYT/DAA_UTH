#include <iostream>

using namespace std;

#define INT_MAX 10000

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

//
float tspGreedy(float **a, int n, bool visited[], int tmp[]) {
    int currentCityIndex = 0;
    float totalDistance = 0;
    for (int i = 1; i < n; i++) {
        int currentCity = tmp[currentCityIndex];
        int nextCity = -1;
        float smallestDistanceBetweenCities = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && a[currentCity][j] < smallestDistanceBetweenCities) {
                smallestDistanceBetweenCities = a[currentCity][j];
                nextCity = j;
            }
        }
        currentCityIndex++;
        tmp[currentCityIndex] = nextCity;
        visited[nextCity] = true;
        currentCityIndex = i;
    }
    for (int i = 0; i < n - 1; i++) {
        totalDistance += a[tmp[i]][tmp[i + 1]];
    }
    totalDistance += a[tmp[n - 1]][tmp[0]];

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
    // Duyệt qua các phần tử (thành phố) của mảng
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
            
            // Kiểm tra đã đủ n phần tử (thành phố) trong lộ trình đang xây dựng không ?
            // Nếu đã đủ n phần tử (thành phố) trong lộ trình đang xây dựng
            if (i == n - 1) {
                // Cập nhật giá trị tổng khoảng cách nhỏ nhất của lộ trình từng được duyệt
                // dựa trên giá trị bé hơn với tổng khoảng cách của lộ trình hiện tại
                smallestTotalDistance = min(smallestTotalDistance, currentDistance + a[tmp[n - 1]][0]);
            } else if (currentDistance + (n - i) * smallestDistanceBetweenCities < smallestTotalDistance) {
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
    // Biến 'n' lưu số lượng phần tử (thành phố) của mảng,
    // 's' lưu STT thành phố xuất phất
    int n, s;
    cout << "Nhap vao so luong phan tu (thanh pho) cua mang (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào của 'n'    
    if (n <= 0) {
        cout << "So luong phan tu (thanh pho) cua mang phai (> 0)\n";
        return 0;
    }

    // Biến lưu khoảng cách nhỏ nhất giữa 2 thành phố
    float smallestDistanceBetweenCities = INT_MAX;

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
            // Nếu khoảng cách giữa 2 thành phố hiện tại < khoảng cách nhỏ nhất giữa 2
            // thành phố
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

    // Khai báo mảng động có 'n' phần tử: chứa lộ trình tham quan thành phố đang xây dựng
    int *tmp = new int[n];
    // Lưu thành phố xuất phát là thành phố đầu tiên trong lộ trình
    tmp[0] = s - 1;
    // Biến 'currentDistance' lưu tổng khoảng cách của lộ trình hiện tại,
    // 'smallestTotalDistance' lưu tổng khoảng cách nhỏ nhất của lộ trình từng được duyệt
    float currentDistance = 0, smallestTotalDistance = INT_MAX;

    // Gọi hàm giải bài toán người du lịch (TSP)
    tspBnB(1, a, n, smallestDistanceBetweenCities, visited, tmp, currentDistance, smallestTotalDistance);

    // Hiển thị kết quả
    cout << "Tong khoang cach nho nhat cua lo trinh (BnB): " << smallestTotalDistance;

    float result = tspGreedy(a, n, visited, tmp);

    //
    cout << "\nTong khoang cach nho nhat cua lo trinh (Greedy): " << result;

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 2 chiều 'a'
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    // Giải phóng bộ nhớ đã cấp phát cho mảng động 'visited' và 'tmp'
    delete[] visited;
    delete[] tmp;

    return 0;
}