#include <iostream>
using namespace std;
    int partition_arr(int arr[], int startind, int endind){
    ///Partition the array here and return the index of the pivot item after
    int pivot = arr[endind];
    int partitionind = startind;
    for(int ind = startind; ind < endind; ind++)
    {
        if(arr[ind] <= pivot)
        {
            swap(arr[ind], arr[partitionind]);
            partitionind++;
        }
    }
    swap(arr[partitionind], arr[endind]);
    return partitionind;
}
void QuickSort(int arr[], int startind, int endind){
    if(startind>=endind){
        return ;
    }

    else if(startind < endind)
    {
       ///Partition the array
     int partitionind  = partition_arr(arr, startind, endind);
    ///QuickSort the left subarray
    QuickSort(arr, startind, partitionind-1);
    ///QuickSort the right subarray
    QuickSort(arr, partitionind+1, endind);
    }
}

int main()
{
    int arr[]={2,8,7,1,3,5,6,4};
    int sz=sizeof(arr)/sizeof(int);
    QuickSort(arr,0,sz-1);
    ///printing the output
    for(int ind=0;ind<sz;ind++){
    cout<< arr[ind] <<" ";
    }
    cout<<endl;
    return 0;
}

