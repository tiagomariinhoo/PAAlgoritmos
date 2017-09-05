#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)

struct t_aresta{
    int dis;
    int x, y;
    int visited;
};

bool comp(t_aresta a, t_aresta b){ return a.dis < b.dis; }

bool comp2(t_aresta a, t_aresta b){ return a.dis > b.dis; }

#define MAXN 200200
#define MAXM 200200

int n, m;
t_aresta aresta[MAXM],aresta2[MAXM];

int pai[MAXN],pai2[MAXN];
int peso[MAXN],peso2[MAXN];

t_aresta mst[MAXM],mst2[MAXM];

int procurar(int x){
    if(pai[x] == x) return x;
    return pai[x] = procurar(pai[x]);
}

int procurar2(int x){
    if(pai2[x] == x) return x;
    return pai[x] = procurar2(pai2[x]);
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

void join2(int a, int b){

    a = procurar2(a);
    b = procurar2(b);

    if(peso2[a] < peso2[b]) pai2[a] = b;
    else if(peso2[b] < peso2[a]) pai2[b] = a;
    else{
        pai2[a] = b;
        peso2[b]++;
    }

}

int main(){

    int cases;
        cin >> cases;
    int k=1;
        while(k!=cases+1){
      cin >> n >> m;

            for(int i = 1;i <= m;i++){
                cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
            }

            for(int i = 1;i <= n;i++) pai[i] = i;

            sort(aresta+1, aresta+m+1, comp2);

            int tam = 1;
            int contador=0;
            int aux2=0,aux=1000001;
            for(int i = 1;i <= m;i++){

                if( procurar(aresta[i].x) != procurar(aresta[i].y) ){

	                    join(aresta[i].x, aresta[i].y);

	                    mst[tam] = aresta[i];

	                    contador+=mst[tam].dis;

	                  		aresta[i].x = aresta[i].y;
                        tam++;
                	} else {
                        aux2+=aresta[i].dis;
                	}

                }

            cout << aux2 << endl;

        k++;
        }

    return 0;
}
