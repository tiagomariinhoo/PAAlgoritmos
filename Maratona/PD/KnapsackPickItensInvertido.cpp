#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 501
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
int peso[MAX];
int valor[MAX];
int pd[MAX][MAX];
int ans = 0;
int picks[MAX][MAX];
/*
int knap(int obj, int aguenta){
	if(pd[obj][aguenta]!=0) return pd[obj][aguenta];
	if(obj==0){
		if(peso[0]<=aguenta){
			picks[obj][aguenta]=1;
			pd[obj][aguenta] = valor[0];
			return valor[0];
		} else {
			picks[obj][aguenta] = -1;
			return pd[obj][aguenta] = 0;
		}
	}
	int take = 0, dontTake = 0;

	if(peso[obj]<=aguenta){
		take = valor[obj] + knap(obj-1, aguenta - valor[obj]);
		dontTake = knap(obj-1, aguenta);

		pd[obj][aguenta] = max(take, dontTake);

		if(take > dontTake) picks[obj][aguenta] = 1;
		else picks[obj][aguenta] = -1
	}
	return pd[obj][aguenta];
}*/

int knap(int obj, int aguenta){
	if(pd[obj][aguenta] != 0) return pd[obj][aguenta];
	if(obj == n or aguenta==0){
		pd[obj][aguenta] = 0;
		return picks[obj][aguenta] = 0;
	}
	// picks[obj][aguenta] = 1;
	if(peso[obj] <= aguenta){
		int take = 0, dontTake = 0;
		take = valor[obj] + knap(obj+1, aguenta - peso[obj]);
		dontTake = knap(obj+1,aguenta);
		if(take >= dontTake) picks[obj][aguenta] = 1;
		else picks[obj][aguenta] = -1;

		return pd[obj][aguenta] = max(take,dontTake);
	}
	 // picks[obj][aguenta] = 1;
	return pd[obj][aguenta] = 0;
}

void printPicks(){
	int aguenta = s;
	for(int i=0;i<n;i++){
		if(picks[i][aguenta] == 1){
			cout << valor[i] << " - " << peso[i] << endl;
			aguenta -= peso[i];
		}
	}
}

int main(){

	ss(n,s);
	vector<ii> vec;

	for(int i=0;i<n;i++){
		int a,b;
		ss(a,b);
			vec.pb(mp(a,b));
	}

	for(int i=0;i<vec.size();i++){
		valor[i] = vec[i].F;
		peso[i] = vec[i].S;
	}

	cout << knap(0 , s) << endl;
	printPicks();
	return 0;
}