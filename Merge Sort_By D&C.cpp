#include <iostream>
#include<vector>
#include<set>
#include<queue>
#include<stack>
using namespace std;
void Sort(int arr[], int l, int m, int r)
{
    int n1 = (m-l)+1 ;
    int n2 =(r-m);
    int  L[n1],R[n2] ;
    for(int i=0 ; i<n1 ; i++)
        L[i]=arr[l+i];
    for(int i=0 ; i<n2 ; i++)
        R[i]=arr[m+i+1];
    int i=0, j=0,k=l ;   //i > left , j > right , k >arr
    while(i<n1&&j<n2)
    {
        if(R[j]<L[i])
        {
            arr[k]=R[j];
            j++;
        }
        else if(R[j]>=L[i])
        {
            arr[k]=L[i];
            i++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]= L[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]= R[j];
        k++;
        j++;
    }
}

int mergesort(int arr[],int start,int end2)
{
    if(start<end2)
    {
        int med =start+(end2-start)/2;
        mergesort(arr,start,med);
        mergesort(arr,med+1,end2);
        Sort(arr,start,med,end2);
    }
}
int main()
{
    int arr[7]= {3,4,2,1,0,5,6};
    mergesort(arr,0,6);
    return 0;
}
