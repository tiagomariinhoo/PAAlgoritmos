#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 2000
#define D cout << "DEBUG" << endl

int n, time_s, visit[MAX];
vector<int> ADJ[MAX];

int dfs(int u, int pai, vector<pair<int,int> >& ans){
	//cout << "U : " << u << endl;
	int menor = visit[u] = time_s++;
	int filhos = 0;

	for(int i=0;i<ADJ[u].size();i++){
		//cout << "Adj u i : " << ADJ[u][i] << endl;
		if(visit[ADJ[u][i]]==0){
		filhos++;
		int m = dfs(ADJ[u][i], u , ans);
		menor = min(menor,m);
			if(visit[u]<m){
				ans.push_back(make_pair(u,ADJ[u][i]));
			} 
		}else if (ADJ[u][i]!=pai){
			menor = min(menor,visit[ADJ[u][i]]);
		}
	}
	return menor;
}

vector<pair<int,int> > get_articulacoes(){
	vector<pair<int,int> > ans;
	time_s = 1;
	memset(visit, 0 , n*sizeof(int));
	for(int i=0;i<n;i++){
		dfs(i,-1,ans);
	}
	return ans;
}

int main (){
	//int n;
	while(cin >> n){
		for(int i=0;i<MAX;i++){
			ADJ[i].clear();
		}
		cout << endl;
		for(int i=0;i<n;i++){
			int element,tam;
			char a;
				cin >> element >> a >>  tam >> a;
					for(int j=0;j<tam;j++){
						int t;
							cin >> t;
							ADJ[element].push_back(t);
					}
		}

		/*for(int i=0;i<n;i++){
			for(int j=0;j<ADJ[i].size();j++){
				cout << i << " - " << ADJ[i][j] << " ";
			} cout << endl;
		}*/

		vector<pair<int,int> > vec = get_articulacoes();

		/*for(int i=0;i<vec.size();i++){
			cout << "Vec first : " << vec[i].first << endl;
			cout << "Vec second : " << vec[i].second << endl;
		}*/

		sort(vec.begin(),vec.end());

		cout << vec.size() << " critical links" << endl;
		for(int i=0;i<vec.size();i++){
			if(vec[i].second<vec[i].first) swap(vec[i].second,vec[i].first);
			cout << vec[i].first << " - " << vec[i].second << endl;
		}
		if(!n) break;
	}


	return 0;
}