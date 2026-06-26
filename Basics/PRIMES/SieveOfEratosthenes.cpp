/*
TIME COMPLEXITY: O(n log log n)
SPACE COMPLEXITY: O(n)

Finds all prime numbers from 1 to n.

Idea:

Initially assume every number is prime.

Starting from 2,
mark all of its multiples as composite.

Repeat for every prime.

Optimization:

If i*i > n,
all smaller multiples have already been marked.
*/

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime;
}
