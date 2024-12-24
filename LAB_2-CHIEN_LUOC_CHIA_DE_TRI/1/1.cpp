#include <iostream>

using namespace std;

// Hàm gộp 2 mảng đã sắp xếp thành một mảng đã được sắp xếp
void merge(int parent[], int left, int middle, int right) {
    // Biến 'nTmp' + 'i' lưu số lượng phần tử của mảng con thứ 'i' (i = 1,2)
    // Mảng con thứ 1 (left, middle) của mảng cha
    // Mảng con thứ 2 (middle + 1, right) của mảng cha
    int nTmp1 = middle - left + 1, nTmp2 = right - middle;
    // Mảng 'tmp' + 'i' lưu giá trị các phần tử của mảng con thứ 'i' (i = 1,2)
    int tmp1[nTmp1], tmp2[nTmp2];

    // Sao chép giá trị của mảng cha cho mảng con thứ 1
    for (int i = 0; i < nTmp1; i++) {
        tmp1[i] = parent[left + i];
    }
    // Sao chép giá trị của mảng cha cho mảng con thứ 2
    for (int i = 0; i < nTmp2; i++) {
        tmp2[i] = parent[middle + 1 + i];
    }

    // Biến 'indexTmp' + 'i' cập nhật chỉ số mảng con thứ 'i' (i = 1,2)
    int indexTmp1 = 0, indexTmp2 = 0;
    // Gộp hai mảng con đã sắp xếp thành một mảng cha đã được sắp xếp
    // Kiểm tra liên tục chỉ số của mảng con thứ 1 và thứ 2s
    while (indexTmp1 < nTmp1 && indexTmp2 < nTmp2) {
        // Kiểm tra giá trị phần tử của mảng con thứ 1 và 2 để sao chép lần lượt từng giá trị phần tử vào mảng cha
        // TH1: Giá trị phần tử của mảng con thứ 1 <= thứ 2
        if (tmp1[indexTmp1] <= tmp2[indexTmp2]) {
            parent[left] = tmp1[indexTmp1];
            left++; indexTmp1++;
        }
        // TH2: Giá trị phần tử của mảng con thứ 1 > thứ 2
        else {
            parent[left] = tmp2[indexTmp2];
            left++; indexTmp2++;
        }
    }
    
    // Sao chép các phần tử còn lại của mảng con thứ 1 (nếu có) vào mảng cha
    while (indexTmp1 < nTmp1) {
        parent[left] = tmp1[indexTmp1];
        left++; indexTmp1++;
    }

    // Sao chép các phần tử còn lại của mảng con thứ 2 (nếu có) vào mảng cha
    while (indexTmp2 < nTmp2) {
        parent[left] = tmp2[indexTmp2];
        left++; indexTmp2++;
    }
}

// Hàm sắp xếp các phần tử của mảng bằng thuật toán Merge Sort
void mergeSort(int a[], int left, int right) {
    if (left >= right) return; // Điều kiện dừng của đệ quy
    int middle = (left + right) / 2; 
    // Đệ quy sắp xếp mảng con thứ 1 (mảng con bên trái)
    mergeSort(a, left, middle);
    // Đệ quy sắp xếp mảng con thứ 2 (mảng con bên phải)
    mergeSort(a, middle + 1, right);
    // Gộp 2 mảng con đã được sắp xếp thành 1 mảng con đã được sắp xếp
    merge(a, left, middle, right);
}

int main() {
    int n; // Biến lưu số lượng phần tử của mảng
    cout << "Nhap vao so luong phan tu cua mang (>0): "; cin >> n;
    
    // Kiểm tra giá trị đầu vào
    if (n <= 0) {
        cout << "So luong phan tu cua mang phai (>0)\n";
        return 0;
    }

    int a[n]; // Khai báo mảng có độ dài 'n'
    // Nhập giá trị các phần tử của mảng
    for (int i = 0 ; i < n; i++) {
        cout << "Nhap vao gia tri cua phan tu " << i + 1 << ": "; cin >> a[i];
    }

    // Gọi hàm đệ quy để sắp xếp mảng
    mergeSort(a, 0, n - 1);

    // Hiển thị kết quả
    cout << "Mang sau khi duoc sap xep tu be den lon: ";
    for (int i = 0 ; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}