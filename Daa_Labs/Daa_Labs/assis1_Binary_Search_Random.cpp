#include<bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

int main()
{
    int size;
    cout<<"\nEnter the size -> ";
    cin>>size;
    int arr[size];
    cout<<"\n Input the array elements seprated by space \n";
    for(int i = 0; i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    sort(arr,arr+size);
    int left = 0;
    int right = size-1;
     int element;
     cin>>element;
    cout<<"\nValue To Check-> "<<element<<endl;
   
       auto start = high_resolution_clock::now();
    while(left<=right)
    {
        int mid= (rand() % (right - left + 1)) + left;
        if(arr[mid]==element)
        {
             auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Time taken by function: "<< duration.count() << " nanoseconds" << endl;
            cout<<"\n Element Present \n";
            return 0;
        }
        if(arr[mid]<element)
        {
            left = mid+1;    
        }
        else
        {
            right = mid-1;
        }
    }
    cout<<"\n Element Not Present \n";
    return 0;
}