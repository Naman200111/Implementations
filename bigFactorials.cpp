void largeFactorial(int n)
{
    // we will store individual value in array
    int m = 10000;
    vector<int> helper(m);
    helper[m - 1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            int val = helper[j];
            int multiplier = i;

            int prod = val * multiplier + carry;
            int newPlaceValue = prod % 10;
            carry = prod / 10;

            helper[j] = newPlaceValue;
        }
    }

    int idx = -1;
    for (int i = 0; i < m; i++)
    {
        if (helper[i] != 0)
        {
            idx = i;
            break;
        }
    }

    for (int i = idx; i < m; i++)
        cout << helper[i];
    cout << endl;
}


