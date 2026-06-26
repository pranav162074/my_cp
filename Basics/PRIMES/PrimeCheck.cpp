/*
TIME COMPLEXITY: O(sqrt(n))
SPACE COMPLEXITY: O(1)

A number is prime if it has exactly two divisors:
1 and itself.

We only need to check divisibility up to sqrt(n).
If n has a divisor greater than sqrt(n),
its corresponding divisor will be smaller than sqrt(n).
*/

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}
