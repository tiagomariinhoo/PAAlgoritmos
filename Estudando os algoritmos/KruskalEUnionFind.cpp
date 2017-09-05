
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
    cout << "Peso a : " << peso[a] << endl;
    cout << "Peso b : " << peso[b] << endl;
     if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
    cout << "--- peso depois ---" << endl;
    cout << "Peso a : " << peso[a] << endl;
    cout << "Peso b : " << peso[b] << endl;

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
        while(cin >> n >> m , n+m){

            krusInit();

        for(int i=1;i<=m;i++){
            cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
        }

            sort(aresta+1, aresta+m+1, comp);

            for(int i=1;i<=m;i++){
                cout << "Aresta i x : " << aresta[i].x << endl;
                cout << "Aresta i y : " << aresta[i].y << endl;
                cout << "Aresta i dis : " << aresta[i].dis << endl;
            }

            int contador=0;
            int tam2=0;

            for(int i = 1; i <= m ; i++){

                cout << "Aresta i x : " << aresta[i].x << endl;
                cout << "Aresta i y : " << aresta[i].y << endl;
                cout << "Aresta i dis : " << aresta[i].dis << endl;


                if( procurar(aresta[i].x) != procurar(aresta[i].y)){
                    cout << "Entrou no if ----------- PAIS DIFRENTES " << endl;
                    cout << "procurar aresta i x : " << procurar(aresta[i].x) << endl;
                    cout << "procurar aresta i y : " << procurar(aresta[i].y) << endl;
                    cout << "-------" << endl;

	                    join(aresta[i].x,aresta[i].y);
                    cout << "Depois do join : " << endl;
                    cout << "procurar aresta i x : " << procurar(aresta[i].x) << endl;
                    cout << "procurar aresta i y : " << procurar(aresta[i].y) << endl;
                    cout << "-------" << endl;

	                    mst[tam2] = aresta[i];
	                    contador+=mst[tam2].dis;

                    cout << "aresta dis : "  << aresta[i].dis << endl;
                    cout << "Arvore minima : " << contador << endl;

	                    tam2++;
                }

            }
            cout << "-----------" << endl;
            cout << "Tam 2 : " << tam2 << endl;
            cout << "Arvore minima final : " << endl;
            cout << contador << endl;
        }
        /* Estudando o Kruskal :
            - Se o grafo tiver parte não interligadas por exemplo :
            1 2 15
            1 3 10
            2 3 1
            4 5 20 , notável que overtice 4 e 5 não tem nenhuma ligação com os outros, o tam2 vai ser menor que n-1.

            - O procurar, procura o pai de cada um ,todos começam sendo o pai dele mesmo, mas como ordenamos a aresta no começo, escolherá sempre o melhor caminho
            - O join vai fazer o pai de um ser o pai do outro
        */


    return 0;
}
