#include<iostream>
using namespace std;
//Ham tao Heap
void Heapify(int arr[],int n,int i)
{
    int left =2*i+1;//con ben trai
    int right =2*i+2;// con ben phai
    int Largest=i;//node cha
    //Neu con ben trai hoac con ben phai lon hon node cha thi thay doi node cha
    if(left<n && arr[left]>arr[Largest])
    {
        Largest=left;
    }  
    //Neu con ben phai lon hon node cha thi thay doi node cha
    if(right<n && arr[right]>arr[Largest])
    {
        Largest=right;
    }
    //Neu node cha khong phai la lon nhat thi thay doi vi tri
    if( Largest !=i)
    {
        swap(arr[i],arr[Largest]);
        Heapify(arr,n,Largest);
    }
}
//Ham sap xep Heap
void SortHeap(int arr[], int n) 

{

    for(int i=n/2 -1;i >=0;i--)
    {
        Heapify(arr,n,i);
    }
    //Doi cho node dau tien voi node cuoi cung
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        Heapify(arr,i,0);
    }
}
int main()
{
    int arr[1000];
    int n;
    cout<<"Nhap so phan tu cua mang: ";cin>>n;
    cout<<"Nhap mang: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    SortHeap(arr,n);
    cout<<"Mang sau khi sap xep: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
