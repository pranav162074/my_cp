/*
Finds all prime numbers in the range [L, R].

TIME COMPLEXITY:
O((R-L+1) log log R)

SPACE COMPLEXITY:
O(R-L+1)

Use when:

R can be as large as 10^12
but

R-L <= 10^6

Classic Sieve cannot be built up to 10^12,
so we sieve only the required interval.
*/

vector<long long> segmentedSieve(long long L, long long R) {
    long long limit = sqrt(R);

    // Simple sieve up to sqrt(R)
    vector<bool> isPrime(limit + 1, true);
    vector<long long> primes;

    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    for (long long i = 2; i <= limit; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }

    // Segmented sieve
    vector<bool> segment(R - L + 1, true);

    for (long long prime : primes) {

        // First multiple of prime inside [L, R]
        long long first = max(prime * prime,
                              ((L + prime - 1) / prime) * prime);

        for (long long j = first; j <= R; j += prime)
            segment[j - L] = false;
    }

    vector<long long> ans;

    for (long long i = L; i <= R; i++) {
        if (i > 1 && segment[i - L])
            ans.push_back(i);
    }

    return ans;
}
