#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

struct Car{
	int x;
	int y;
	char dir;
	int temp;
	int espera;

}

vector<char> vec[20];
/*
v < < < < < ! < < < < < ! < < < < < < 
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
! > > > > > ! > > > > > ! > > > > > !
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
v < < < < < ! < < < < < ! < < < < < !
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
v * * * * * v * * * * * ^ * * * * * ^
> > > > > > > > > > > > ! > > > > > ^
*/

/*
	1 - Carros		
		Guardar todas as posições de cada carro
		x,y : coordenada atual 
		dir : direção atual
		temp : temporizador, na hora de passar pelo semaforo

		A cada repetição, faz todos os carros andarem em 1
		Caso o carro esteja no sinal, só diminui seu temp (caso
		esteja passando)

	2 - Semaforos
		Guardar todas as coordenadas dos semaforos
		Assim que o carro chegar, calcula pra onde ele vai
		Verifica o fluxo de veiculos da vertical e horizontal
		Dar prioridade caso um carro esteja esperand por mt tempo


*/


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0;i<19;i++){
		string s;
		getline(cin, s);
		// cout << s << endl;
		for(int j=0;j<sz(s);j++) if(s[j] != ' ') vec[i].pb(s[j]);
	}



	return 0;
}
