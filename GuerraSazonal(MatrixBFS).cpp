#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 100

int dx[] = {1 , 1 , 1 , 0 , 0 , -1 , -1 , -1};
int dy[] = {1 , 0 , -1 , 1 , -1 , 1 , 0 , -1};
char matriz[MAX][MAX];
int tam;


void bfs (int x, int y){
	
	for(int i=0;i<8;i++){
		if(matriz[x+dx[i]][y+dy[i]]=='1'){
		matriz[x+dx[i]][y+dy[i]]='0';
		bfs(x+dx[i],y+dy[i]);
		}
	}

}

int main (){
	int p=1;
	while(cin >> tam){

	for(int i=0;i<tam;i++)
		for(int j=0;j<tam;j++)
			cin >> matriz[i][j];

	int ans=0;

	for(int i=0;i<tam;i++)
		for(int j=0;j<tam;j++){
			if(matriz[i][j]=='1'){
				bfs(i,j);
				ans++;
			}
		}

		printf ("Image number %d contains %d war eagles.\n",p++,ans);

	}

	return 0;
}
