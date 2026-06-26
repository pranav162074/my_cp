/*Prime Factorization using SPF ⭐⭐⭐⭐⭐
TIME COMPLEXITY: O(log n)

Requires the SPF array.

Repeatedly divide by the smallest prime factor.

Example:

84

84 -> 42 -> 21 -> 7 -> 1

Factors:
2 2 3 7
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

vector<int> primeFactors(int n, vector<int>& spf) {
    vector<int> factors;

    while (n != 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }

    return factors;
}
