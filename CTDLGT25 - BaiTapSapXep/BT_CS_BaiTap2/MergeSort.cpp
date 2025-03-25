#include <iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;   // Kích thước mảng con bên trái
    int n2 = high - mid;      // Kích thước mảng con bên phải

    int left[n1], right[n2];  // Tạo mảng tạm để lưu hai mảng con

    // Sao chép phần tử vào mảng tạm left[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];

    // Sao chép phần tử vào mảng tạm right[]
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;  // Chỉ số cho mảng left, right và mảng gốc arr

    // Trộn hai mảng con lại theo thứ tự tăng dần
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {  // Chọn phần tử nhỏ hơn để đưa vào arr[k]
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng left[] nếu có
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng right[] nếu có
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main() {
    int arr[1000];
    int array_size;

    cout << "Nhap so phan tu cua mang: ";
    cin >> array_size;

    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < array_size; i++) {
        cin >> arr[i];
    }

    // Gọi MergeSort với chỉ số đầu là 0 và cuối là array_size - 1
    MergeSort(arr, 0, array_size - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < array_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
