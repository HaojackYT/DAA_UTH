#include <iostream>

using namespace std;

// Hàm hoán đổi giá trị của 2 biến nguyên
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Hàm phân hoạch mảng theo thuật toán Lomuto
int lomutoPartition(int a[], int left, int right) {
    int pivot = a[right]; // Chọn phần tử cuối cùng làm pivot
    int i = left - 1; // Biến lưu chỉ số của phần tử sẽ hoán đổi
    // Duyệt các phần tử của mảng từ trái sang phải - 1 (phần tử đứng trước phần tử cuối)
    for (int j = left; j < right; j++) {
        // Kiểm tra giá trị phần tử hiện tại so với pivot
        // Nếu giá trị phần tử hiện tại <= pivot
        if (a[j] <= pivot) {
            i++;
            // Hoán đổi phần tử hiện tại với phần tử đầu tiên lớn hơn pivot của mảng
            swap(a[i], a[j]);
        }
    }
    // Hoán đổi pivot với phần tử sau phần tử cuối cùng <= pivot
    swap(a[i + 1], a[right]);
    // Trả về chỉ số của pivot sau khi phân hoạch
    return i + 1;
}

// Hàm sắp xếp nhanh các phần tử của mảng của mảng bằng thuật toán Quick sort với phân hoạch Lomuto
void quickSort(int a[], int left, int right) {
    // TH cơ sở: mảng con có 1 phần tử hoặc rỗng
    if (left >= right) return;
    // Biến lưu chỉ số của pivot sau khi phân hoạch
    int pivotIndex = lomutoPartition(a, left, right);
    // Gọi lại hàm sắp xếp bên trái pivot của mảng
    quickSort(a, left, pivotIndex - 1);
    // Gọi lại hàm sắp xếp bên phải pivot của mảng
    quickSort(a, pivotIndex + 1, right);
}

int main() {
    int n; // Biến lưu số lượng phần tử của mảng
    cout << "Nhap vao so luong phan tu cua mang (> 0): "; cin >> n;
    
    // Kiểm tra giá trị đầu vào
    if (n <= 0) {
        cout << "So luong phan tu cua mang phai (> 0)\n";
        return 0;
    }

    int a[n]; // Khai báo mảng có độ dài 'n'
    // Nhập giá trị các phần tử của mảng
    for (int i = 0 ; i < n; i++) {
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> a[i];
    }

    // Gọi hàm đệ quy để sắp xếp mảng
    quickSort(a, 0, n - 1);

    // Hiển thị kết quả
    cout << "Mang sau khi duoc sap xep tu be den lon: ";
    for (int i = 0 ; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}