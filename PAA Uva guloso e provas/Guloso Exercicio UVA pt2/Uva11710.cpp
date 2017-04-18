
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
    FILE *file;
    file = fopen("saida.txt", "w");
    int n,m;
        while(cin >> n >> m , n+m){

            krusInit();

        vector< pair < int , string > > vec;

        for(int i=0;i<n;i++){
            string aux;
                cin >> aux;
                    pair < int, string >  pa;
                    pa.first = 0;
                    pa.second = aux;
                        vec.push_back(pa);
        }

        for(int i = 1;i <= m;i++){

            string aux, aux2;
            int custo;

            cin >> aux >> aux2 >> custo;

                for(int j=0; j<vec.size() ;j++){
                    if(vec[j].second == aux){
                      aresta[i].x = j;
                       vec[j].first++;
                    } if(vec[j].second == aux2){
                       aresta[i].y = j;
                       vec[j].first++;
                    }
                }

                aresta[i].dis = custo;
        }

        sort(vec.begin(),vec.end());

        string aux;
        cin >> aux;


            for(int i = 1;i <= n+1;i++) pai[i] = i;

            sort(aresta+1, aresta+m+1, comp);

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
            if(tam2<n-1) {
                    fprintf (file, "Impossible\n" );
                cout << "Impossible" << endl;
                continue;
            }
            fprintf (file, "%d\n",contador);
            cout << contador;
            cout << endl;
        }


    return 0;
}
