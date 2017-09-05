long long fac[N], ifac[N];
long long PowerMod(long long a, long long n){
    long long ret = 1;
    while (n){
        if (n & 1){
            ret *= a;
            ret %= MOD;
        }
        a *= a;
        a %= MOD;
        n /= 2;
    }
    return ret;
}
inline void pre(){
    int i;
    fac[0] = 1;
    for (i = 1; i < N; i++){
        fac[i] = (i * fac[i - 1]) % MOD;
    }
    ifac[N - 1] = PowerMod(fac[N - 1], MOD - 2);
    for (i = N - 2; i >= 0; i--){
        ifac[i] = ((i + 1) * ifac[i + 1]) % MOD;
    }
}
long long com(int n, int r){
    long long ret = fac[n];
    ret *= ifac[r];
    ret %= MOD;
    ret *= ifac[n - r];
    ret %= MOD;
    return ret;
}