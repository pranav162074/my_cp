long long findGcd(long long a, long long b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return (a == 0) ? b : a;
}

long long findLcm(long long a, long long b) {
    return (a / findGcd(a, b)) * b;
}


/*
in general, just use in built functions
*/
