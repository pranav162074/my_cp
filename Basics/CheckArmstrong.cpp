bool isArmstrong(int n) {
    int original = n;
    int digits = 0;

    int temp = n;
    while (temp) {
        digits++;
        temp /= 10;
    }

    temp = n;
    int sum = 0;
    while (temp) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}
