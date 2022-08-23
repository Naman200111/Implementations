// primes store total 664579 prime numbers

vector<int> helper(10000000, 1);
vector<int> primes;

void sieve()
{
    helper[1] = 0; // non prime
    for (int i = 2; i <= 10000000; i++)
    {
        if (helper[i] == 1)
        {
            // i is prime
            primes.push_back(i);
            for (int j = i * i; j <= 10000000; j += i)
                helper[j] = 0;
        }
    }
}