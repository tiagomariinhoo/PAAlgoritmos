int digitsCount(int n, int b){
    return (int)floor(1 + log10((double)n) / log10((double)b));
}
int digitsCount(int n){
    return (int)floor(1 + log10((double)n));
}