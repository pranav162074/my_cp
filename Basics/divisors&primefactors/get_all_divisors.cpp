/*GET ALL DIVISORS
TIME COMPLEXITY: O(sqrt(n))
SPACE COMPLEXITY: O(number of divisors)

APPROACH:
Every divisor i of n has a corresponding divisor n/i.

Instead of checking all numbers from 1 to n,
iterate only until sqrt(n).

If i divides n:
    - insert i
    - insert n/i

However, when i*i == n (perfect square),
i and n/i are the same divisor, so insert it only once.

The divisors are NOT guaranteed to be sorted.
*/
vector<int> getDivisors(int n) {
    vector<int> divisors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);

            if (i != n / i)
                divisors.push_back(n / i);
        }
    }

    return divisors;
}

