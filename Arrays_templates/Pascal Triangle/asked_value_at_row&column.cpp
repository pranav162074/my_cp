// Simple formula: (R-1)C(C-1)

long long nCr(int n, int r) {
    if (r > n) return 0;

    r = min(r, n - r);

    long long ans = 1;

    for (int i = 0; i < r; i++) {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }

    return ans;
}
