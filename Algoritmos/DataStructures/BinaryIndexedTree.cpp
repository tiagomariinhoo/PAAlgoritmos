#define lsone(x) (x&(-x))
const int N = 123456;
int bit[N];
void update(int x, int val){for(++x;x < N; x+= x&-x)bit[x] += val;}
int query(int x) {int sum = 0;for(++x;x > 0; x -= x&-x)sum += bit[x];return sum;}
