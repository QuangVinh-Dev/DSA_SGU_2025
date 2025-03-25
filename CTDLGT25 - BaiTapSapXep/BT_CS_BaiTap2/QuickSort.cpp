#include<iostream>
using namespace std;

// Phan vung mang
int Partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Đưa pivot về đúng vị trí
    return i + 1; // Trả về vị trí mới của pivot
}

// Hàm sắp xếp QuickSort
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = Partition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[1000];
    int n;
    
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int low = 0, high = n - 1; // Thêm biến low và high

    QuickSort(arr, low, high); // Gọi hàm QuickSort với giới hạn hợp lệ

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
