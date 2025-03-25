#include<iostream>
#include<ctime>
#include<cstdlib>
#include<time.h>
using namespace std;
//Ham tao mang ngau nhien
void createArray_Random(int arr[],int size)
{
    for(int i=0; i < size;i++)
    {
        arr[i]=rand()%(size*10);//so ngau nhien tu 0->size*10
    }
}

//Heap sort
void Heapify(int arr[],int n,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && arr[left]>arr[largest]) largest = left;
    if(right<n && arr[right]>arr[largest]) largest =right;
    // Nếu largest thay đổi, hoán đổi và đệ quy
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}
    //Ham sap xep Heap
void HeapSort(int arr[],int n)
{
    for(int i=(n/2)-1;i>=0;i--) Heapify(arr,n,i);
    //doi cho node dau tien voi node cuoi cung
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        Heapify(arr,i,0);
    }
}
    //ham
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
    //Ham sap xep Merge
void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

//Phan vung mang
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Đưa pivot về đúng vị trí
    return i + 1; // Trả về vị trí mới của pivot
}
//Ham sap xep QuickSort
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = Partition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}



//Hàm đo thời gian chạy
void MeasureTime(int size)
{
    int* arr=new int[size];


    createArray_Random(arr,size);

    clock_t start, end;

    double  time_use_Heap,time_use_Merge,time_use_Quick;
    //Đo thời gian thực hiện heap sort
    int *arr_Heap=new int [size];//cấp phát mảng động
    //Cấp phát mảng ngẫu nhiên
    copy(arr,arr+size,arr_Heap);// Sao chép nội dung của arr vào arr_heap để đảm bảo cùng dữ liệu ban đầu
    createArray_Random(arr_Heap,size);
    start=clock();//bắt đầu đo thời gian
    HeapSort(arr_Heap,size);//gọi hàm Heáport để sắp xếp mảng arr_Heap
    end =clock();//kết thúc đo thời gian
    time_use_Heap=(double)(end-start)/CLOCKS_PER_SEC;//tính thời gian chạy đổi sang giây
    delete[] arr_Heap;//giải phóng bộ nhớ

    //Đo thời gian thực hiện merge sort
    int *arr_Merge=new int [size];
    copy(arr,arr+size,arr_Merge);
    createArray_Random(arr_Merge,size);
    start=clock();
    MergeSort(arr_Merge,0,size-1);
    end=clock();
    time_use_Merge=(double)(end-start)/CLOCKS_PER_SEC;
    delete[] arr_Merge;

    //Đo thời gian thực hiện quick sort
    int * arr_Quick=new int [size];
    copy(arr,arr+size,arr_Quick);
    createArray_Random(arr_Quick,size);
    start=clock();
    QuickSort(arr_Quick,0,size-1);
    end=clock();
    time_use_Quick=(double)(end-start)/CLOCKS_PER_SEC;
    delete[] arr_Quick;

    //Xuat thoi gian thuc hien
        cout<<"Size: "<<size<<endl;
    cout<<"Thoi gian thuc hien HeappSort: "<<time_use_Heap<<"s"<<endl;
    cout<<"Thoi gian thuc hien MergeSort: "<<time_use_Merge<<"s"<<endl;
    cout<<"Thoi gian thuc hien QuickSort: "<<time_use_Quick<<"s"<<endl;
    
    delete[] arr;
}



int main()
{
    srand(time(0));
    // taoj kich thuoc cho mang ngau nhien
    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    cout<<"Đang chờ thời gian chạy ..."<<endl;
    for(int i=0;i<5;i++)
    {
        MeasureTime(sizes[i]);
    }
    return 0;
}
