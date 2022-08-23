#define mod 1000000007

void extendedEucledianAlgo(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }

    extendedEucledianAlgo(b, a % b, x, y);

    int currx = y;
    int curry = x - (a / b) * y;

    x = currx;
    y = curry;
}

// here we need to find multiplicative inverse of n wrt mod
// mod = 1e9+7
int32_t main()
{
    int n;
    cin >> n;

    // a = n and n = mod
    // (n*b) % mod = 1 find b;

    int x, y;
    extendedEucledianAlgo(n, mod, x, y);

    cout << (x + mod) % mod << endl;
    return 0;
}