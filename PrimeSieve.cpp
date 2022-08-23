// generating prime array
int p[1000000];
void primeSieve(int *p) 
{
    for(int i=3; i<=1000000;i+=2) {
        p[i] = 1; // let all odd nos prime
    }

    for(int i=3; i<=1000000; i+=2) {
        if(p[i]==1) {
            // mark its multiple non prime
            for(int j=i*i; j<=1000000; j+=i) {
                p[j] = 0;
            }
        }
    }

    // special case
    p[2] = 1;
    p[0] = p[1] = 0;
}


// space optimized bitset version
const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

void sieve() {
    // set all bits
    b.set(); // 1,1,1,1,1.....

    b[0] = b[1] = 0;

    for(long long int i=2; i<=n; i++) {
        if(b[i]) {//prime
            primes.push_back(i);
            for(long long int j=i*i; j<=n; j+=i) {
                b[j] = 0;
            }
        }
    }
}