
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

double distancia(double x, double y, double x2, double y2){
	double dist = sqrt(((x2-x)*(x2-x))+((y2-y)*(y2-y)));
	DEBUG cout << "Distancia : " << dist << endl;
	return dist;
}


int main(){
    int k=0;
        //  DEBUG  FILE *file;
         //  DEBUG file = fopen("saida.txt","w");
    int testes;
    cin >> testes;
        while(k!= testes){

                    memset(mst,0,200000);
                    memset(aresta,0,200000);
            for(int i=0;i<200000;i++){
                    pai[i]=i;
                    peso[i]=0;
            }

        	if(k!=0) cout << endl;
        	k++;
            int m;
            	cin >> m;
            	vector<double> vec;

                vector< pair < double, double > > vec2;

            	for(int i=1;i<=m;i++){
                    double x,y;
                    cin >> x >> y;
                    pair < double, double > pa;
                    pa.first = x;
                    pa.second = y;
                    vec2.push_back(pa);
                    vec.push_back(x);
                	vec.push_back(y);
                	pai[i]=i;
                }
                int tam=1;
                for(int i=0;i<vec2.size();i++){
                    int iaux,jaux;
                    for(int j=i+1;j<vec2.size();j++){
                        double teste = distancia(vec2[i].first,vec2[i].second,vec2[j].first,vec2[j].second);

                    aresta[tam].x = i;
                    aresta[tam].y = j;
                    aresta[tam].dis = teste;
                    tam++;

                    }

                }


                sort(vec.begin(),vec.end());
                DEBUG cout << "Vec size :  " << vec[vec.size()-1] << endl;
                n = vec[vec.size()-1];


            //for(int i = 1;i <= n;i++) pai[i] = i;

            sort(aresta+1, aresta+tam+1, comp);

            double contador=0;
            int tam2=0;
            for(int i = 1;i <=tam;i++){

                //if( procurar(aresta[i].x) != procurar(aresta[i+1].x) || procurar (aresta[i].y) != procurar (aresta[i+1].y) || procurar (aresta[i].y) != procurar (aresta[i+1].y)|| procurar (aresta[i].y) != procurar (aresta[i+1].y)){
                    if(procurar(aresta[i].x) != procurar(aresta[i].y)){
	                    DEBUG cout << "Dis : " << aresta[i].dis << endl;
	                    join(aresta[i].x, aresta[i].y);

	                    mst[tam2] = aresta[i];
	                    contador+=mst[tam2].dis;

                        //aresta[i].x = aresta[i].y;

	                    tam2++;

                }


            }
            printf ("%.2lf", contador);

            cout << endl;


            //fprintf (file,"%.2lf\n\n",contador);
            //k++;
        }

    return 0;
}
