#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 202000

vector < int > vec[101];
int grau[101];
vector <int> q;
int main (){
	int n,m;


		while(cin >> n >> m, n+m){

        for(int i=0;i<101;i++){
            grau[i]=0;
            vec[i].clear();
            q.clear();
        }

			for(int i=0;i<m;i++){
				int a,b;
				cin >> a >> b;
				vec[a].push_back(b);
				grau[b]++;
			}

			for(int i=1;i<=n;i++) if(grau[i]==0) q.push_back(i);

        int ini=0;

        while(ini<q.size()){

            int atual = q[ini];
                for(int i=0;i<vec[atual].size();i++){
                    int v = vec[atual][i];
                    //cout << "v : " << v << endl;
                    grau[v]--;

                    if(grau[v]==0)q.push_back(v);
                }

        ini++;
        }

        for(int i=0;i<q.size();i++){
            cout << q[i] << " ";
        } cout << endl;

	}

	return 0;
}
