
#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;

struct t_aresta{
    int dis;
    int x, y;
};

bool comp(t_aresta a, t_aresta b){ return a.dis < b.dis; }

#define MAXN 200200
#define MAXM 200200

int n, m;
t_aresta aresta[MAXM];

int pai[MAXN];
int peso[MAXN];

t_aresta mst[MAXM];

int procurar(int x){
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



int main(){
    int k=0;

        while(cin >> n){

            if(k++>0) cout << endl;
                int soma;
                int cont1=0;
                for(int i=0;i<n-1;i++){
                    int x,y;
                    cin >> x >> y >> soma;
                    cont1+=soma;
                }
                cout << cont1 << endl;

            int qtAres;
                cin >> qtAres;
                for(int i=1;i<=qtAres;i++){
                    cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
                }

            int tam;
                cin >> tam;
                for(int i=1;i<=tam;i++){
                    cin >> aresta[i+qtAres].x >> aresta[i+qtAres].y >> aresta[i+qtAres].dis;
                }


            for(int i = 1;i <= n;i++) pai[i] = i;

            sort(aresta+1, aresta+qtAres+1+tam, comp);

            int contador=0;
            int tam2=0;
            for(int i = 1;i <= qtAres+tam;i++){

                if( procurar(aresta[i].x) != procurar(aresta[i].y) ){

	                    join(aresta[i].x, aresta[i].y);

	                    mst[tam2] = aresta[i];
	                    contador+=mst[tam2].dis;



	                  		aresta[i].x = aresta[i].y;

	                    tam2++;

                }


            }
            cout << contador << endl;
            //k++;
        }


    return 0;
}
