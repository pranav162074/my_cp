/*Prime Factorization with Powers ⭐ (Very useful)
TIME COMPLEXITY: O(sqrt(n))

Returns every prime factor along with its exponent.

Example:
360 = 2^3 * 3^2 * 5

Output:
{
    {2,3},
    {3,2},
    {5,1}
}
*/

vector<pair<int,int>> primeFactorization(int n) {
    vector<pair<int,int>> factors;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {

            int cnt = 0;

            while (n % i == 0) {
                cnt++;
                n /= i;
            }

            factors.push_back({i, cnt});
        }
    }

    if (n > 1)
        factors.push_back({n, 1});

    return factors;
}
