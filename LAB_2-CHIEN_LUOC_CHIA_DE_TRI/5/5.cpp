#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N_MAX 100

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    // Số nhỏ hơn hoặc bằng 1 không phải là số nguyên tố
    if (n <= 1) return false;
    // Kiểm tra số có chia hết từ 2 đến căn bậc 2 của n không
    for (int i = 2; i * i < n; i++) {
        // Nếu chia hết cho một số nào, thì không là số nguyên tố
        if (n % i == 0) return false;
    }
    // Nếu không chia hết cho bất kỳ số nào, thì là số nguyên tố
    return true;
}

// Hàm tìm vị trí, giá trị của số dương đầu tiên và số nguyên tố cuối cùng của mảng
void findFirstPositiveAndLastPrimeDnC(int a[], int left, int right, int &posFirst, int &valFirst, int &posLast, int &valLast) {
    // TH cơ sở: mảng chỉ có 1 phần tử
    if (left == right) {
        // Kiểm tra phần tử để tìm số dương đầu tiên
        if (a[left] > 0 && posFirst == -1) {
            valFirst = a[left]; // Lưu giá trị số dương đầu tiên
            posFirst = left; // Lưu vị trí số dương đầu tiên
        }

        // Kiểm tra phần tử để tìm số nguyên tố cuối cùng
        if (isPrime(a[left])) {
            valLast = a[left]; // Lưu giá trị số nguyên tố cuối cùng
            posLast = left; // Lưu vị trí số nguyên tố cuối cùng
        }
        return;
    }
    
    // Biến lưu chỉ số phần tử ở giữa để chia mảng thành 2 nửa
    // Nửa bên trái (left, middle) của mảng
    // Nửa bên phải (middle + 1, right) của mảng
    int middle = (left + right) / 2;

    // Đệ quy kiểm tra nửa bên trái
    findFirstPositiveAndLastPrimeDnC(a, left, middle, posFirst, valFirst, posLast, valLast);
    // Đệ quy kiểm tra nửa bên phải
    findFirstPositiveAndLastPrimeDnC(a, middle + 1, right, posFirst, valFirst, posLast, valLast);
}

int main() {
    // Biến 'N' lưu số lượng phần tử của mảng,
    // 'posFirst' lưu vị trí của số dương đầu tiên,
    // 'valFirst lưu giá trị của số dương đầu tiên,
    // 'posLast' lưu vị trí của số nguyên tố cuối cùng,
    // 'valLast' lưu giá trị của số nguyên tố cuối cùng
    int N, posFirst = -1, valFirst = 101, posLast = -1, valLast = 101;
    cout << "Nhap vao so luong phan tu cua day so (0 < N < 100): "; cin >> N;

    // Kiểm tra giá trị đầu vào
    if (N <= 0 || N >= 100) {
        cout << "So luong phan tu cua day so phai (0 < N < 100)";
        return 0;
    }

    int a[N_MAX]; // Mảng lưu giá trị các phần tử
    srand(time(NULL)); // Khởi tạo hạt giống (seed) cho hàm sinh số ngẫu nhiên
    // Gán giá trị các phần tử của mảng trong khoảng [-100, 100] ngẫu nhiên
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 201 - 100;
    }

    // Hiển thị dãy số nguyên được sinh ra ngẫu nhiên
    cout << "Day so nguyen duoc sinh ra ngau nhien: ";
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";


    // Gọi hàm tìm vị trí, giá trị của số dương đầu tiên và số nguyên tố cuối cùng
    findFirstPositiveAndLastPrimeDnC(a, 0, N - 1, posFirst, valFirst, posLast, valLast);

    // Kiểm tra kết quả trả về và hiển thị thông tin về số dương đầu tiên
    if (posFirst == -1) {
        cout << "Khong co so duong trong day tren\n";
    } else {
        cout << "Vi tri cua so duong dau tien: " << posFirst << "\n";
        cout << "Gia tri cua so duong dau tien: " << valFirst << "\n";
    }

    // Kiểm tra kết quả trả về và hiển thị thông tin về số nguyên tố cuối cùng
    if (posLast == -1) {
        cout << "Khong co so nguyen to trong day tren\n";
    } else {
        cout << "Vi tri cua so nguyen to cuoi cung: " << posLast << "\n";
        cout << "Gia tri cua so nguyen to cuoi cung: " << valLast << "\n";
    }
    return 0;
}