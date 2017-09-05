int fastExp(int a, int b, int c) {
    int ans=1;
    while(b != 0) {
            if(b%2 == 1)ans=(ans*a)%c;
            a=(a*a)%c;
            b /= 2;
    }
    return ans;
}