/*Count Distinct Prime Factors
Returns the number of distinct prime factors.

Example:
12 = 2² × 3

Answer = 2
*/

int countDistinctPrimeFactors(int n) {
    int cnt = 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;

            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        cnt++;

    return cnt;
}
