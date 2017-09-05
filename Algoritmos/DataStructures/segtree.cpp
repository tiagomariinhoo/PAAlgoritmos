#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n; // array size
int sgt[4*maxn];
int a[maxn];
int left(int p){return (p << 1); }
int right(int p){return (p << 1) + 1;}
void build(int id = 1, int lf = 0, int rg = n - 1) {
	if(lf == rg)sgt[id] = (a[lf]&1); // change
	else{
		int md = (lf + rg) >> 1;
		build(left(id), lf, md);
		build(right(id), md + 1, rg);
		sgt[id] = sgt[left(id)] + sgt[right(id)]; // change
	}
}
void update(int idx, int val, int lf = 0, int rg = n-1, int id = 1) {
	if(lf == rg) { // change
		a[idx] = val;
		if(val&1)sgt[id] = 1;
		else sgt[id] = 0;
	}
	else {
		int md = (lf + rg)>>1;
		if(lf <= idx && idx <= md) { 
			update(idx, val, lf, md, left(id));
		}else {
			update(idx, val, md+1, rg, right(id));
		}
		sgt[id] = sgt[left(id)] + sgt[right(id)]; // change
	}
}
int query(int esq, int dir, int lf = 0, int rg = n-1, int id = 1) {
	if(dir < lf || rg < esq)return 0;
	if(esq <= lf && rg <= dir)return sgt[id];
	int md = (lf + rg) >> 1;
	int l = query(esq, dir, lf, md, left(id));
	int r = query(esq, dir, md + 1, rg, right(id));
	return (l + r); // change
}
