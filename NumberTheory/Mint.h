const long long MOD = 1e9 + 7;

long long add(long long x, long long y) {
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}

long long sub(long long x, long long y) {
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}

long long mul(long long x, long long y) {
    return (x * y) % MOD;
}

long long bin_pow(long long x, long long p) {
    if (p == 0) return 1;
    if (p & 1) return mul(x, bin_pow(x, p - 1));
    return bin_pow(mul(x, x), p / 2);
}

long long rev(long long x) {
    return bin_pow(x, MOD - 2);
}