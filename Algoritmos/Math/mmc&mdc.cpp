int gdc(int a, int b){return b == 0? a: gdc(b, a%b); }
int lcm(int a, int b){return a*(b/gdc(a, b));}