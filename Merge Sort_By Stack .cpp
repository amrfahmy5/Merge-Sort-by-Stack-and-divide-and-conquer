#include <iostream>
#include<vector>
#include<Stack>
using namespace std;
vector <int> Sort(vector <int> R, vector <int> L)
{
    int size1 = R.size();
    int size2 = L.size();
    int arr[size1+size2] ;
    int i=0, j=0,k=0 ;   //i > left , j > right , k >merged array
    while(i<size2&&j<size1)
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
    while(i<size2)
    {
        arr[k]= L[i];
        k++;
        i++;
    }
    while(j<size1)
    {
        arr[k]= R[j];
        k++;
        j++;
    }
    vector<int> float_vect;
    float_vect.insert( float_vect.begin(), arr, arr + sizeof(arr)/sizeof(arr[0]) ) ;
    return float_vect ;
}
vector  <int> mergesort(int arr[],int size)
{
    stack<vector<int>> Stack;

    for (int i = 0; i < size; i++)
    {
        vector  <int>v;
        v.push_back(arr[i]);
        Stack.push(v);
    }
    while (Stack.size()>1)
    {
        vector <int>r = Stack.top();
        Stack.pop();
        vector <int>l = Stack.top();
        Stack.pop();
        vector <int>merged=Sort(l, r);
        Stack.push(merged);
    }
    return Stack.top() ;
}
void print(vector  <int> arr)
{
    for(int i:arr)
        cout<<i << " " ;
    cout <<endl ;
}
int main()
{
    int arr[8]= {3,4,2,1,9,0,5,6};
    int len =sizeof(arr)/sizeof(arr[0]);
    vector  <int> v= mergesort(arr,len);
    print(v);
    return 0;
}
