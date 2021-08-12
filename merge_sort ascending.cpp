#include<iostream>
using namespace std;

merge_sort_halfs(int arr[], int startind, int midind, int endind)
{
    int leftarrsz = (midind-startind+1);
    int leftarr [100];
    for(int ind = 0; ind < leftarrsz; ind++)
    {
        leftarr[ind] = arr[startind+ind];
    }
    int rightarrsz = (endind-(midind+1)+1);
    int rightarr [100];
    for(int ind = 0; ind < rightarrsz; ind++)
    {
        rightarr[ind] = arr[midind+1+ind];
    }
    int leftind = 0;
    int rightind = 0;
    for(int ind  = startind; ind <= endind; ind++)
    {
        if(leftind == leftarrsz)
        {
            arr[ind] = rightarr[rightind];
            rightind++;
        }
        else if(rightind == rightarrsz)
        {
            arr[ind] = leftarr[leftind];
            leftind++;
        }
        else if(leftarr[leftind] <= rightarr[rightind])
        {
            arr[ind] = leftarr[leftind];
            leftind++;
        }
        else
        {
            arr[ind] = rightarr[rightind];
            rightind++;
        }
    }
}

void merge_sort(int arr[] , int startind, int endind)
{
    // remain 1 element
    if(startind  == endind)
    {
        return ;
    }
    // remain more than 1 element
    else if(startind < endind)
    {
        int midind  = (startind + endind) / 2;

        merge_sort(arr, startind, midind);
        merge_sort(arr, midind+1, endind);

        merge_sort_halfs(arr, startind, midind, endind);
    }
}

int main()
{
    int arr[] = {14,7,3,12,9,11,6,2};
    int sz  = sizeof(arr) / sizeof(int);
    merge_sort(arr, 0, sz-1);
    for(int ind  = 0; ind < sz; ind++)
    {
        cout << arr[ind] << " ";
    }
    cout << endl;
    return 0;
}
