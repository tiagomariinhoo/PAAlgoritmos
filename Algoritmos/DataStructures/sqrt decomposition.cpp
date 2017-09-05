int a[MAX];
int sum[MAX];
int k; // sqrt(n)
void update(int id, int vl){ // update index id with value vl
	sum[id / k] = sum[id / k] - a[id] + vl;
	a[id] = vl;
}
int query(int lf, int rg) { // query in range lf to rg
	int res = 0;
	int now = lf;
	while((now + 1) % k != 0 and now <= rg)res += a[now++];
	while(now + k <= rg)res += sum[now / k], now+=k;
	while(now <= rg)res += a[now++];
	return res;
}
