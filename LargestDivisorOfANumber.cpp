// optimize to root n
int findlargestDivisor(int x) {
	int divisor = 1;
    for(int i=2; i <= sqrt(x); i++) {
        if(x%i == 0) {
			divisor = i;
			break;
		}
	}
    return divisor;
}