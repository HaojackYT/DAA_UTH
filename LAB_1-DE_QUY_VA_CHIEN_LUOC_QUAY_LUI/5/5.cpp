#include <iostream>

using namespace std;

// Hàm hiển thị kết quả chuyển một đĩa từ cột này sang cột khác
void swap(int disk, char a, char b) {
    cout << "Chuyen dia thu " << disk << " tu " << a << " sang " << b << "\n";
}

// Hàm đệ quy giải bài toán tháp Hà Nội
void towerOfHanoi(int numberOfDisks, char source, char intermediate, char destination) {
    // TH1: Chuyển 1 đĩa từ nguồn tới đích
    if (numberOfDisks == 1) {
        swap(1, source, destination);
    }
    // TH2: Chuyển >1 đĩa từ nguồn tới đích
    else {
        // B1: Chuyển n - 1 đĩa từ nguồn sang trung gian, sử dụng cột đích làm cột trung gian
        towerOfHanoi(numberOfDisks - 1, source, destination, intermediate);
        // B2: Chuyển đĩa có số thứ tự lớn nhất từ nguồn sang đích
        swap(numberOfDisks, source, destination);
        // B3: Chuyển n - 1 đĩa từ trung gian sang đích, sử dụng cột nguồn làm cột trung gian
        towerOfHanoi(numberOfDisks - 1, intermediate, source, destination);
    }
}

int main() {
    int numberOfDisks; // Biến lưu số lượng đĩa
    cout << "Nhap vao so luong dia cua thap Ha Noi (> 0): "; cin >> numberOfDisks;

    // Kiểm tra giá trị đầu vào
    if (numberOfDisks <= 0) {
        cout << "So luong dia cua thap Ha Noi phai (> 0)\n";
        return 0;
    }

    // Các cột trong bài toán tháp Hà Nội
    char source = 'A', intermediate = 'B', destination = 'C';
    
    // Gọi hàm đệ quy giải bài toán tháp Hà Nội
    towerOfHanoi(numberOfDisks, source, intermediate, destination);
    return 0;
}