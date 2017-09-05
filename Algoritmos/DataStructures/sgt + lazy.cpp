#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int n; // array size
int sgt[4*maxn], a[maxn], lzy[4*maxn], ar[maxn];
int left(int p){return (p << 1); }
int right(int p){return (p << 1) + 1;}
void build(int id = 1, int lf = 0, int rg = n - 1){ //0 -index
	lzy[id] = 0;
	if(lf == rg)sgt[id] = a[lf]; // change
	else{
		int md = (lf + rg)>>1;
		build(left(id), lf, md);
		build(right(id), md + 1, rg);
		sgt[id] = sgt[left(id)] + sgt[right(id)]; // change
	}
}
void lazy(int id, int lf, int rg){
	if(lzy[id]){ // change
		sgt[id] = (rg - lf + 1) * lzy[id];
		if(rg != lf)lzy[left(id)] = lzy[right(id)] = lzy[id];
		lzy[id] = 0;
	}
}
void update(int val, int esq, int dir, int lf = 0, int rg = n - 1, int id = 1){
	lazy(id, lf, rg);
	if(lf > dir || rg < esq)return;
	if(lf >= esq && rg <= dir){ // change
		lzy[id] = val;
		lazy(id, lf, rg);
		if(lf != rg){ 
			lzy[left(id)]+= val;
			lzy[right(id)]+= val;
		}
		return;
	}
	int md = (lf + rg)>>1;
	update(val, esq, dir, lf, md, left(id));
	update(val, esq, dir, md + 1, rg, right(id));
	sgt[id] = sgt[left(id)] + sgt[right(id)]; // change
}
int query(int esq, int dir , int lf = 0, int rg = n - 1, int id = 1){
	if(lf > dir || rg < esq)return 0;
	lazy(id, lf, rg);
	if(esq <= lf && rg<=dir)return sgt[id];
	int md = (lf + rg)>>1;
	int l = query(esq, dir, lf, md, left(id));
	int r = query(esq, dir, md+1, rg, right(id));
	return (l + r); // change
}
