#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAXN 5001
#define MAX 100100
#define INF 1e9
#define D cout << "DEBUG" << endl
int n,k;
int pai[MAX], peso[MAX];

int find(int x){
	if(pai[x]==x) return x;
	return pai[x] = find(pai[x]);
}

void join (int x, int y){
	pai[find(x)] = find(y);
}

int main (){

	cin >> n >> k;

	for(int i=1;i<=n;i++)pai[i]=i;

	char t;
	int a,b;
		for(int i=0;i<k;i++){
			cin >> t >> a >> b;
				if(t=='C'){
					if(find(a)==find(b))
						cout << "S" << endl;
					else 
						cout << "N" << endl;
					
				} else 
					join(a,b);
				
		}

}