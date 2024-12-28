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

// Hàm tìm phần tử lớn thứ k trong một mảng ko sắp xếp sử dụng chiến thuật chia để trị
int findKthLargestDnC(int a[], int left, int right, int k) {
    // TH cơ sở: nếu không hợp lệ
    if (left > right) return -1;

    // Biến lưu chỉ số của pivot sau khi phân hoạch
    int pivotIndex = lomutoPartition(a, left, right);

    // Số lượng phần tử ở phía bên phải (bao gồm cả pivot)
    int cntRight = right - pivotIndex + 1;

    // TH1: số lượng phần tử bên phải bằng k
    if (cntRight == k) {
        return a[pivotIndex];
    }
    // TH2: số lượng phần tử bên phải lớn hơn k
    else if (cntRight > k) {
        // Gọi lại hàm tìm tiếp ở bên phải của mảng (pivotIndex + 1, right)
        return findKthLargestDnC(a, pivotIndex + 1, right, k);
    }
    // TH3: số lượng phần tử bên phải nhỏ hơn k
    else {
        // Gọi lại hàm tìm tiếp ở bên trái của mảng (left, pivotIndex - 1)
        return findKthLargestDnC(a, left, pivotIndex - 1, k - cntRight);
    }
}

int main() {
    // Biến 'n' lưu số lượng phần tử của mảng,
    // 'k' lưu chỉ số phần tử lớn thứ k
    int n, k;
    cout << "Nhap vao so luong phan tu cua mang (> 0): "; cin >> n;

    // Kiểm tra giá trị đầu vào
    if (n <= 0) {
        cout << "So luong phan tu cua mang phai (> 0)\n";
        return 0;
    }

    cout << "Nhap vao chi so phan tu lon thu k (1 <= k <= " << n << "): "; cin >> k;

    // Kiểm tra giá trị đầu vào
    if (k <= 0) {
        cout << "Chi so phan tu lon thu k phai (1 <= k <= " << n << ")\n";
        return 0;
    }

    int a[n]; // Khai báo mảng có độ dài 'n'
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao gia tri phan tu " << i + 1 << ": "; cin >> a[i];
    }

    // Hàm tìm phần tử lớn thứ k trong một mảng ko sắp xếp
    int result = findKthLargestDnC(a, 0, n - 1, k);

    // Hiển thị kết quả
    cout << "Phan tu lon thu k (" << k << ") trong mang khong sap xep: "; cin >> result;
    return 0;
}