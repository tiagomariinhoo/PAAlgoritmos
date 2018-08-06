

#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;

struct t_aresta{
    double dis;
    double x, y;
};

bool comp(t_aresta a, t_aresta b){ return a.dis < b.dis; }

#define MAXN 200000
#define MAXM 200000

double n, m;
t_aresta aresta[MAXM];

double pai[MAXN];
double peso[MAXN];

t_aresta mst[MAXM];

double procurar(int x){
    if(pai[x] == x) return x;
    return pai[x] = procurar(pai[x]);
}

void join(int a, int b){

    a = procurar(a);
    b = procurar(b);
     if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
}

void krusInit(){
    for(int i=0;i<20000;i++){
                    pai[i]=i;
                    peso[i]=0;
                    mst[i].x = 0;
                    mst[i].y = 0;
                    mst[i].dis = 0;
                    aresta[i].x = 0;
                    aresta[i].y = 0;
                    aresta[i].dis = 0;
    }
}

int main(){

    int n,m;

        cin >> n >> m;
            krusInit();

        for(int i=1;i<=m;i++){
            cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
        }

            sort(aresta+1, aresta+m+1, comp);

            for(int i=1;i<=m;i++){
            }

            int contador=0;
            int tam2=0;

            for(int i = 1; i <= m ; i++){


                if( procurar(aresta[i].x) != procurar(aresta[i].y)){

	                    join(aresta[i].x,aresta[i].y);

	                    mst[tam2] = aresta[i];
	                    contador+=mst[tam2].dis;

	                    tam2++;
                }

            }
            cout << contador << endl;


    return 0;
}
