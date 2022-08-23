// modulo expansion wala power founder
int power(int x, int n, int P) {
	// we traverse in bits of n (x^n)
	// 2^5  => 101
	// ans = 2, x=4
	// x=
	int ans = 1;
	while(n) {
		int last_bit = (n&1);
		if(last_bit)
			ans = (ans * x)%P;
		n = n>>1;
		x = (x*x)%P;
	}
	return ans;
}