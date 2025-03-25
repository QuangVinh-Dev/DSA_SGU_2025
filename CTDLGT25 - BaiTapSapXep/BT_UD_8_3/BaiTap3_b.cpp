#include<iostream>
using namespace std;
struct PhongThi{
    int SoPhong;//1-200
    char Nha;//A-Z
    int KhaNangChua;//10-250
};

//Ham in thong tin phong thi
void inPhongThi(PhongThi pt){
    cout<<"So phong: "<<pt.SoPhong<<endl;
    cout<<"Nha: "<<pt.Nha<<endl;
    cout<<"Kha nang chua: "<<pt.KhaNangChua<<endl;
}

//Ham heapìy cho SoPhong thi

void HeapifySoPhong (PhongThi arr[],int n,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && arr[left].SoPhong>arr[largest].SoPhong) largest=left;
    if(right<n && arr[right].SoPhong >arr[largest].SoPhong) largest=right;
    if(largest !=i){
        swap(arr[i],arr[largest]);
        HeapifySoPhong(arr,n,largest);
    }
}
void HeapSortSoPhong(PhongThi arr[],int n)
{
    for(int i=n/2 +1;i>=0;i--) HeapifySoPhong(arr,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        HeapifySoPhong(arr,i,0);
    }
}

//Ham heapify cho Nha 
void HeapifyNha (PhongThi arr[],int n,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;
    if(left<n && (arr[left].Nha<arr[smallest].Nha || (arr[left].Nha==arr[smallest].Nha && arr[left].SoPhong<arr[smallest].SoPhong))) smallest=left;
    if(right<n && (arr[right].Nha<arr[smallest].Nha || (arr[right].Nha==arr[smallest].Nha && arr[right].SoPhong<arr[smallest].SoPhong))) smallest=right;
    if(smallest !=i)
    {
        swap(arr[i],arr[smallest]);
        HeapifyNha(arr,n,smallest);
    }
}
//Ham heapSort cho Nha
void HeapSortNha(PhongThi arr[],int n)
{
    for(int i=n/2 +1;i>=0;i--)  HeapifyNha(arr,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        HeapifyNha(arr,0,i);
    }
}
//Ham heapify cho KhaNangChua
void HeapifyKhaNangChua(PhongThi arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].KhaNangChua > arr[largest].KhaNangChua)
        largest = left;
    if (right < n && arr[right].KhaNangChua > arr[largest].KhaNangChua)
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        HeapifyKhaNangChua(arr, n, largest);
    }
}
//Ham heapSort cho KhaNangChua
void HeapSortKhaNangChua(PhongThi arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapifyKhaNangChua(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        HeapifyKhaNangChua(arr, i, 0);
    }
}
int main()
{
    // Dữ liệu mẫu
    PhongThi rooms[] = {
        {1, 'A', 50},
        {2, 'B', 100},
        {3, 'A', 75},
        {4, 'C', 25},
        {5, 'B', 150}
    };
    int n = 5;

    // 1. Sắp xếp giảm dần theo khả năng chứa
    cout << "Sap xep giam dan theo kha nang chua:\n";
    HeapSortKhaNangChua(rooms, n);
    for (int i = 0; i < n; i++)
        inPhongThi(rooms[i]);
    cout << endl;

    // Reset mảng về trạng thái ban đầu
    PhongThi rooms2[] = {
        {1, 'A', 50},
        {2, 'B', 100},
        {3, 'A', 75},
        {4, 'C', 25},
        {5, 'B', 150}
    };

    // 2. Sắp xếp tăng dần theo Nhà, rồi Số phòng
    cout << "Sap xep tang dan theo Nha, So phong:\n";
    HeapSortSoPhong(rooms2, n);
    for (int i = 0; i < n; i++)
        inPhongThi(rooms2[i]);
    cout << endl;

    // Reset mảng về trạng thái ban đầu
    PhongThi rooms3[] = {
        {1, 'A', 50},
        {2, 'B', 100},
        {3, 'A', 75},
        {4, 'C', 25},
        {5, 'B', 150}
    };

    // 3. Sắp xếp tăng dần theo Nhà, giảm dần theo Khả năng chứa
    cout << "Sap xep tang dan theo Nha, giam dan theo kha nang chua:\n";
    HeapSortNha(rooms3, n);
    for (int i = 0; i < n; i++)
        inPhongThi(rooms3[i]);
    return 0;
}