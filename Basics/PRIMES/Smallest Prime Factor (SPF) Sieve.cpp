/*Smallest Prime Factor (SPF) Sieve ⭐⭐⭐⭐⭐
TIME COMPLEXITY:
    Preprocessing: O(n log log n)

Query:
    O(1)

spf[x] stores the smallest prime factor of x.

Example:

spf[12] = 2
spf[15] = 3
spf[49] = 7

Very useful for answering multiple prime-factorization
queries efficiently.
*/

vector<int> SPF(int n) {
    vector<int> spf(n + 1);

    for (int i = 0; i <= n; i++)
        spf[i] = i;

    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    return spf;
}
