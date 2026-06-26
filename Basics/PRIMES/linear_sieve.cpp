/*
LINEAR SIEVE / EULER SIEVE

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)

Finds all primes from 1 to n in linear time.

It also computes SPF:
    spf[x] = smallest prime factor of x

Why linear?

In normal sieve, a composite number may be marked multiple times.

In linear sieve, every composite number is marked exactly once,
using its smallest prime factor.

Useful when:
    - n <= 1e7
    - Need list of primes
    - Need SPF
    - Need fast factorization later
*/

vector<int> linearSieve(int n, vector<int>& spf) {
    vector<int> primes;
    spf.assign(n + 1, 0);

    for (int i = 2; i <= n; i++) {

        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (p > spf[i] || 1LL * i * p > n)
                break;

            spf[i * p] = p;
        }
    }

    return primes;
}
