#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define MAX 110
#define MAXN 120
#define MIN -2000000
#define INF 0x3f3f3f3f
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<int, ii > iii;
#define F first
#define S second
//g++ a.cpp -o a.exe && a.exe < in
int n, tab[MAXN][MAXN], dist[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dijkstra(){
	memset(dist,INF,sizeof(dist));

	dist[1][1] = 0; // Primeiro vértice

	priority_queue< iii, vector<iii>, greater<iii> > heap; //Pq que contem os proximos vertices
	heap.push(iii(0, ii(1,1)));

	while(!heap.empty()){
		int d = heap.top().F, i = heap.top().S.F, j = heap.top().S.S; //Guarda o elemento do topo
		heap.pop(); //Retira da fila
	
		if(d > dist[i][j]) continue;

		//Verifica se está nos limites da matriz e encontra um novo menor caminho repete para os vizinhos
		for(int p=0;p<4;p++){
			i_ = i + dx[p];
			j_ = j + dy[p];

			if(i_>=1 and i<=n and j>=1 and j<=n and dist[i][j] + tab[i_][j_] < dist[i_][j_]){
			//atualiza a menor distância até ele e coloca na heap novamente
			dist[i_][j_] = dist[i][j]+tab[i_][j_];
			heap.push(iii(dist[i_][j_],ii(i_,j_)));

			}
		}
	}
	return dist[n][n];
}


int main (){

	s(n);

	for(int i = 1; i <= n; i++)
		for(int j =1; j <= n; j++)
			s(tab[i][j]);
		
	cout << dijkstra() << endl;


	return 0;
}