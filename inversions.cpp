#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x // precision of is x and places is y

int merge(int arr[], int n, int l, int m, int h)
{
    int n1=m-l+1, n2=h-m;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[i+l];

    for (int i = 0; i < n2; i++)
        right[i] = arr[i+m+1];

    int i = 0, j = 0;
    int k = l, inversions = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i];
            i++;
        }
        else
        {
            inversions += n1 - i;
            arr[k++] = right[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = left[i++];
    }

    while (j < n2)
    {
        arr[k++] = right[j++];
    }

    // for (int i = 0; i < n; i++)
    //     arr[i] = tmp[i];

    return inversions;
}

int count_inversions(int *arr, int n, int l, int h)
{
    if (l >= h)
        return 0;
    int m = l + (h - l) / 2;
    int ct=0;
    ct += count_inversions(arr, n, l, m);
    ct += count_inversions(arr, n, m + 1, h);
    ct += merge(arr, n, l, m, h);
    return ct;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << count_inversions(arr, n, 0, n - 1) << endl;
    }
}