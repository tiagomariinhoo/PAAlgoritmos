#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)

struct t_aresta{
    int dis;
    int x, y;
    int visited;
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

    int cases;
        cin >> cases;
       // FILE *file;
          //  file = fopen("saida.txt", "w");
    int k=1;
        while(k!=cases+1){
        if(k!=1) cout << endl; //fprintf(file, "\n" );

            cin >> n >> m;
			vector <string> vec;

            for(int i = 1;i <= m;i++){
                string st1,st2;
                int cam;
            	cin >> st1 >> st2 >> cam;
                    if(vec.size()==0){
                        vec.push_back(st1);
                        aresta[i].x = 1;
                        vec.push_back(st2);
                        aresta[i].y = 2;
                        aresta[i].dis = cam;

                        //cout << "Aresta x : " << aresta[i].x << endl << "Aresta y : " << aresta[i].y << endl;
                        continue;
                    }

                    int aux1=0,aux2=0;

                        for(int j=0;j<vec.size();j++){
                            if(st1==vec[j]){
                                aux1++;
                                aresta[i].x = j+1;
                            }
                            if(st2==vec[j]){
                                aux2++;
                                aresta[i].y = j+1;
                            }
                            if(aux1>=1 && aux2>=1) break;
                        }

                        if(aux1==0){
                            vec.push_back(st1);
                            aresta[i].x = vec.size();
                        }
                        if(aux2==0){
                            vec.push_back(st2);
                            aresta[i].y = vec.size();
                        }
                        aresta[i].dis = cam;
               // cout << "Aresta x : " << aresta[i].x << endl << "Aresta y : " << aresta[i].y << endl;
            }


            //for(int i=0;i<vec.size();i++) cout << "String : " << vec[i] << " " << "Numero : " << i+1 << endl;

            for(int i = 1;i <= n;i++) pai[i] = i;

            sort(aresta+1, aresta+m+1, comp);

            int tam = 0;
            int contador=0;

            for(int i = 1;i <= m;i++){

                if( procurar(aresta[i].x) != procurar(aresta[i].y) ){


	                    join(aresta[i].x, aresta[i].y);

	                    mst[++tam] = aresta[i];

	                    contador+=mst[tam].dis;

	                  		aresta[i].x = aresta[i].y;
                	}

                }

                //for(int i=0;i<tam;i++){
                //    cout << "Mst x : " << mst[i].x << " " << "Mst y : " << mst[i].y << " " << "Caminho : " << mst[i].dis << endl;
                //}

            //fprintf(file, "%d\n", contador);
            //fputc("\n");

            cout << contador << endl;
        k++;
        }

        //fclose(file);


    return 0;
}
