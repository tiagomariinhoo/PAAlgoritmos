#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 100001
#define MIN -2000000
#define INF 90000000
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

int n,s;
int peso[501];
int valor[501];
int pd[501][501];
int ans = 0;
int picks[501][501];

/*
	TIAGO LIMA MARINHO
	KNAPSACK PICK ITENS

*/

/*int knap(int obj, int aguenta, int qt){
	ans = max(ans, qt);
	// cout << obj << " " << aguenta << endl;
	if(pd[obj][aguenta]>=0) return pd[obj][aguenta];
	if(!aguenta or obj == n) return pd[obj][aguenta] = 0;
	
	int nColoca = knap(obj+1, aguenta, qt);

	if(peso[obj] <= aguenta){
		int coloca = valor[obj] + knap(obj+1, aguenta - peso[obj], qt+1);
		
		if(coloca > nColoca)
			picks[obj][aguenta] = 1;
		 else  
			picks[obj][aguenta] = -1;
		

			return pd[obj][aguenta] = max(nColoca, coloca);
	}
	return pd[obj][aguenta] = nColoca;
}*/

int knap(int obj, int aguenta, int cc){
	int take, dontTake;

	take = dontTake = 0;
	cc++;
	
	if(obj==0){
		if(peso[0]<=aguenta){
			picks[obj][aguenta]=1;
			pd[obj][aguenta] = valor[0];
			return valor[0];
		} else {
			picks[obj][aguenta] = -1;
			pd[obj][aguenta] = 0;
			return 0;
		}
	}

	if(peso[obj] <= aguenta){
		take = valor[obj] + knap(obj-1, aguenta - peso[obj],cc);
		dontTake = knap(obj-1, aguenta,cc);
		pd[obj][aguenta] = max(take, dontTake);
		ans = max(ans,cc);
		if(take > dontTake) picks[obj][aguenta]=1;
		else picks[obj][aguenta]=-1;

		return pd[obj][aguenta];
	}
}

void printPicks(){
	int aguenta = s;
	for(int i = n-1; i>=0;i--)
		if(picks[i][aguenta]==1){
			cout << valor[i] << " - " << peso[i] << endl;
			aguenta -= peso[i];
		}
}

int main(){
	ss(n,s);
	memset(pd,-1,sizeof pd);

	for(int i=0;i<n;i++) ss(valor[i], peso[i]);

	cout << knap(n-1,s, 0) << endl;


	
	cout << ans << endl;
	cout << " ------ " << endl;
	printPicks();
	

	return 0;
}

