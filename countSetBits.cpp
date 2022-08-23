int totalSetBits(int n) {
    return (__builtin_popcount(n));
}

int totalSetBits(int n) {
    int ct = 0;
    while(n) {
        n = (n & (n-1));
        ct++;
    }
    return ct;
}