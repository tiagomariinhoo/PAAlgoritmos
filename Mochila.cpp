#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1001
#define MIN -2000000
#define INF -9000000000000000000
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//g++ sol.cpp -std=c++11 -o sol.exe && sol.exe < in.txt
int peso[MAX];
int valor[MAX];
int pd[MAX][MAX];
int n,s;

int knapsack(int obj, int aguenta){
	if(pd[obj][aguenta] >= 0) return pd[obj][aguenta];
	if(obj == n or aguenta == 0) return 0;
	int nColoca = knapsack(obj+1, aguenta);

	if(peso[obj] <= aguenta){
		int coloca = valor[obj] + knapsack(obj+1, aguenta - peso[obj]);
		return pd[obj][aguenta] = max(nColoca, coloca);
	}
	return pd[obj][aguenta] = nColoca;
}

int main(){
	ss(s,n);
	memset(pd, -1, sizeof pd);
		for(int i=0;i<n;i++) ss(peso[i], valor[i]);
	cout << knapsack(0, s) << endl;

	return 0;
}