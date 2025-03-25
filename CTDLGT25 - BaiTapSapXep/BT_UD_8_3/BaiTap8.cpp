#include <iostream>
using namespace std;

void Merge(int arr[],int B[], int low, int mid, int high) {
    int left_array = mid - low + 1;   // Kích thước mảng con bên trái
    int right_array = high - mid;      // Kích thước mảng con bên phải

    int left[left_array], right[right_array]; // tạo mảng tạm để lưu hai mảng con

    // Sao chép phần tử vào mảng tạm left[]
    for (int i = 0; i < left_array; i++)
        left[i] = arr[low + i];

    // Sao chép phần tử vào mảng tạm right[]
    for (int j = 0; j < right_array; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;  // Chỉ số cho mảng left, right và mảng gốc arr
    int coutn =0;
    // Trộn hai mảng con lại 
    while (i < left_array && j < right_array) {
        if (left[i] <= right[j]) {  // Chọn phần tử nhỏ hơn để đưa vào arr[k]
            arr[k] = left[i];
            B[left[i]-1] += coutn;// cập nhật số phần tử trrong phần tử left[i]
            i++;
        } else {
            arr[k] = right[j];
            coutn++;//right[j] nhỏ hơn left[i] ,tăng số phần tử lớn phía trước
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng left[] nếu có
    while (i < left_array) {
        arr[k] = left[i];
        B[left[i]-1] += coutn;// cập nhật số phần tử nghịch thế còn lại
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng right[] nếu có
    while (j < right_array) {
        arr[k] = right[j];
        B[right[j]-1] += coutn;// cập nhật số phần tử nghịch thế còn lại
        j++;
        k++;
    }
}

void MergeSort(int arr[],int B[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr,B, low, mid);
        MergeSort(arr,B, mid + 1, high);
        Merge(arr,B, low, mid, high);
    }
}

int main() {
    int arr[1000],B[1000]={0};//khởi tạo mảng B chứa số phần tử nghịch thế n
    int array_size;

    cout << "Nhap so phan tu cua mang: ";
    cin >> array_size;

    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < array_size; i++) {
        cin >> arr[i];
    }

    // Gọi MergeSort để tìm mảng nghịch thế
    MergeSort(arr,B, 0, array_size - 1);

    cout << "Mang nghich the B : ";
    for (int i = 0; i < array_size; i++) {
        cout << B[i] << " ";
    }

    return 0;
}
