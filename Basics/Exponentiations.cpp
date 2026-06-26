/*
Small exponent (<=20)
    -> Simple Power

Large exponent
    -> Binary Exponentiation

Answer required modulo M
    -> Modular Exponentiation
*/

//NORMAL POWER()
//Time Complexity: O(exp)
int power(int base, int exp) {
    int result = 1;
    while (exp--)
        result *= base;
    return result;
}


//BINARY EXPONENTIATION
//Time Complexity: O(log exp)
long long binpow(long long base, long long exp) {
    long long result = 1;

    while (exp) {
        if (exp & 1)
            result *= base;

        base *= base;
        exp >>= 1; // means divide exp by 2
    }

    return result;
}


//MODULAR EXPONENTIATION
// Time Complexity: O(log exp)
long long modpow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    while (exp) {
        if (exp & 1)
            result = result * base % mod;

        base = base * base % mod;
        exp >>= 1; // means divide exp by 2
    }

    return result;
}



/* EXPLANATION: BINARY EXPONENTIATION

Binary Exponentiation (also called Fast Exponentiation or Exponentiation by Squaring)
is an algorithm used to compute base^exp efficiently.

Instead of multiplying the base by itself 'exp' times, it repeatedly squares the
base and processes the exponent using its binary representation.

Example:
    Compute 2^13

    Normal Method:
        2 × 2 × 2 × ... (13 multiplications)

    Binary Exponentiation:
        13 = 1101 (binary)

        Since 13 = 8 + 4 + 1,

        2^13
        = 2^(8+4+1)
        = 2^8 × 2^4 × 2^1

        These powers are obtained by repeatedly squaring:
            2^1 = 2
            2^2 = 4
            2^4 = 16
            2^8 = 256

        Answer:
            256 × 16 × 2 = 8192

The algorithm works as follows:

1. Initialize result = 1.

2. While exponent > 0:

    a) If the current exponent is odd
       (exp & 1 == true),
       multiply result by the current base.

    b) Square the base.
       (base = base * base)

    c) Divide exponent by 2.
       (exp >>= 1)

3. When exponent becomes 0,
   result contains base^exp.

Time Complexity:
    O(log exp)

Space Complexity:
    O(1)

Why is it faster?

Each iteration halves the exponent.

Example:

    exp = 1000

    Instead of performing 1000 multiplications,

    Binary Exponentiation performs only

        log2(1000) ≈ 10

    iterations.

When to use:

- Large exponents
- Number Theory
- Competitive Programming
- Matrix Exponentiation
- Modular Arithmetic
- Whenever exponent can be as large as 10^9 or 10^18

Advantages:

- Extremely fast
- Standard Competitive Programming algorithm
- Easy to modify into Modular Exponentiation

*/
