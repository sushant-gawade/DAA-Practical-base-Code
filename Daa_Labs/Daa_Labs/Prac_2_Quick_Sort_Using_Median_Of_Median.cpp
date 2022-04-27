#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <chrono>
using namespace std;
using namespace std::chrono;

int DIVISIONS(int arr[], int l, int r, int k);
int MEDIANOFMEDIAN(int arr[], int l, int r, int k);

void SORTQUICK(int arr[], int l, int h)
{
    if (l < h)
    {

        int n = h - l + 1;

        int med = MEDIANOFMEDIAN(arr, l, h, n / 2);

        int p = DIVISIONS(arr, l, h, med);

        
        SORTQUICK(arr, l, p - 1);
        SORTQUICK(arr, p + 1, h);
    }
}

int findMedian(int arr[], int n)
{
    sort(arr, arr + n);
    return arr[n / 2];
}

int MEDIANOFMEDIAN(int arr[], int l, int r, int k)
{

    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1;

        int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++)
            median[i] = findMedian(arr + l + i * 5, 5);
        if (i * 5 < n)
        {
            median[i] = findMedian(arr + l + i * 5, n % 5);
            i++;
        }

        int medOfMed = (i == 1) ? median[i - 1] : MEDIANOFMEDIAN(median, 0, i - 1, i / 2);

        int pos = DIVISIONS(arr, l, r, medOfMed);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return MEDIANOFMEDIAN(arr, l, pos - 1, k);

        return MEDIANOFMEDIAN(arr, pos + 1, r, k - pos + l - 1);
    }

    return INT_MAX;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int DIVISIONS(int arr[], int l, int r, int x)
{

    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(&arr[i], &arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, T, i;
    cout << "\nPlease Enter the size : ";
    scanf("%d", &n);
    int arr[n + 1];
    int temp[n + 1];

    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % n + 1;
        temp[i] = arr[i];
    }

    printArray(arr, n);

    auto start = high_resolution_clock::now();
    SORTQUICK(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();

    cout << "Array After Sorting";
    printArray(arr, n);
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\n\nTime Taken To Sort the Array using medians of medians algorithm : " << duration.count() << " nanoseconds" << endl
         << endl
         << endl;



      for (i = 0; i < n; i++)
    {
        arr[i]=temp[i];
    }


    return 0;
}