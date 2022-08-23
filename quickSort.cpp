#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x // precision of is x and places is y

//2,7,8,6,1,5,4
int partition(int *arr, int n, int s, int e)
{
    int pivot = arr[e];
    int i = s - 1;
    int j = s;

    while (j < e)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }

    swap(arr[i + 1], arr[e]);
    return i + 1;
}

void quickSort(int *arr, int n, int l, int h)
{
    if (l >= h)
        return;
    int p = partition(arr, n, l, h);

    quickSort(arr, n, l, p - 1);
    quickSort(arr, n, p + 1, h);
}

int32_t main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, n, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}