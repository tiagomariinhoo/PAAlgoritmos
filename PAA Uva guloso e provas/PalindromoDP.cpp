#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000
#define D cout << "DEBUG" << endl
string line;
int dp[MAX][MAX];

int cont(int esq, int dir){

	cout << "Esq : " << esq << endl << "Dire : " << dir << endl;
	cout << "dp esq dir : " << dp[esq][dir] << endl;
	cout << "line esq : " << line[esq] << " - " << "line dir : " << line[dir] << endl;

	int tot=-2;
	if(esq>dir) return 0;

	else if(esq==dir) return 1;

	if(dp[esq][dir] != -1) {
		cout << "aq-------" << endl;
		return dp[esq][dir];
		
	}
	if(line[esq] == line[dir]){
		cout << "AQUI" << endl;
		tot = cont(esq+1,dir-1) + 2;
	} else {
		int esq1 = cont(esq+1,dir);
		int dir1 = cont(esq,dir-1);
		tot = max(tot, max(esq1,dir1)); 
	}

	return dp[esq][dir] = tot;

}


int main (){
	int t;
		cin >> t;
		getchar();
		while(t--){
			getline(cin,line);
			for(int i=0;i<MAX;i++)
				for(int j=0;j<MAX;j++)
					dp[i][j]=-1;

			if(line.size()==0 or line[0]=='\n'){
				cout << "0" << endl;
				continue;
			}
			
			cout << cont(0,line.size()-1) << endl;


		}

	return 0;
}