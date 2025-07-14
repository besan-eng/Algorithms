#include <iostream>
#include <algorithm>


using namespace std;
#include <iostream>



void printArray(int arr[],int n){
    cout<<"the elements of array:";
    for (int i=0;i<n-1;i++)
    cout<<arr[i]<<"";

}
void bubbleSort(int arr[],int n){
for(int i=0;i<n-1;i++)
    for (int j=0;j<n-1;j++)
    if(arr[j]>arr[j+1])
    swap(arr[j],arr[j+1]);
}

void insertionSort(int arr[],int n){
for (int i=0;i<n-1;i++){
    int key=arr[i];
    int j=i-1;
    while (j>=0 && arr[j]>key)
        arr[j+1]=arr[j--];
    arr[j+1]=key;
}
}
void selectionSort(int arr[], int n){

for(int i=0;i<n-1;i++){

    int minIdx=i;
    for(int j=i+1;j<n;j++)
        if (arr[j]<arr[minIdx])
        minIdx=j;
    swap(arr[i],arr[minIdx]);
}


}
int partition(int arr[],int low,int high){
int pivot=arr[high];
int i=low-1;
for(int j=low;j<=high-1;j++){
    if (arr[j]<pivot){
        i++;
        swap(arr[i],arr[j]);
    }
}
swap(arr[i+1],arr[high]);
return i+1;

}

void quickSort(int arr[],int low,int high){
if (low<high){
    int pi = partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
}

}
int linearSearch(int arr[],int n,int target){

for(int i=0;i<n;i++)
    if(arr[i]==target)
    return i;
return -1;
}
int binarySearch(int arr[],int n,int target){
int left=0;
int right=n-1;
while(left<=right){
    int mid =(left+right)/2;
    if(arr[mid]==target){


        return mid;
        }
    else if(arr[mid]<target){


      left=mid+1;}

    else{


      right= mid-1;
      }

}
return -1;
}


int main()
{
    const int MAX=6;
    int arr[MAX],n,choice,target;
    cout<<"enter the elements :"<<endl;
    cin>>n;



    cout<<"enter the elements:"<<endl;
    for(int i=0;i<n;i++)
            cin>>arr[i];

    cout<<"choose the operation:"<<endl;
    cout<<"1-Bubble sort"<<endl;
    cout<<"2-Insertion Sort"<<endl;
    cout<<"3-Quick Sort"<<endl;
    cout<<"4-Selection srort"<<endl;
    cout<<"5-Linear Search"<<endl;
    cout<<"6-Binary Search"<<endl;

    cout<<"Choice:"<<endl;
    cin>>choice;

    switch(choice){
    case 1:
        bubbleSort(arr,n);

        break;
    case 2:
        insertionSort(arr,n);

        break;
    case 3:
        quickSort(arr,0,n-1);

        break;
    case 4:
        selectionSort(arr,n);

        break;
       default:
           cout<<"invalid input"<<endl;
           break;
    }
    cout<<"the array after sort"<<endl;
    for (int i=0;i<n;i++){
        cout<<arr[i];
    }
    int index = binarySearch(arr,n,target);
    if (index !=-1){
        cout<<"the element found"<<endl;
    }
    else {
        cout<<"the element not found"<<endl;
    }



    return 0;
}
