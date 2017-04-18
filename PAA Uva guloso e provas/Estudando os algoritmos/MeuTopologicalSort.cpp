#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 202000

vector < int > vec[101];
int vetor[100];
int main (){
	int n,m;

		while(cin >> n >> m, n+m){

        for(int i=0;i<100;i++)
            vetor[i]=0;

			for(int i=0;i<m;i++){
				int a,b;
				cin >> a >> b;
				vec[b].push_back(a);
			}


			int tam = n;
			while(tam--){
				for(int i=1;i<=n;i++){
					if(vec[i].size()==0 && vetor[i]==0){
                        cout << i << " ";
						int ult = i;
						vetor[ult]=-1;

                        for(int k=1;k<=n;k++){
                            for(int j=0;j<vec[k].size();j++){
                                if(vec[k][j]==ult)
                                        vec[k].erase(vec[k].begin()+j);

                            }
                        }
                    break;
					}
				}
			}

	}

	return 0;
}
