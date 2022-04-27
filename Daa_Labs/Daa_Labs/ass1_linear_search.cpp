#include<bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
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
   
   auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i<size;i++)
    {
        if(arr[i]==element)
        {
             auto stop = std::chrono::high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "Time taken by function: "<< duration.count() << " nanoseconds" << endl;
            cout<<"\n Number Founded \n";
            return 0;
        }
    }
    cout<<"\n Element Not Present \n";
    return 0;
}

    // operation to be timed ...

 