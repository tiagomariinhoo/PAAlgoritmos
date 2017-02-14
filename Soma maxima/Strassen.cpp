#include <bits/stdc++.h>
#define INF -1000000001
#define DEBUG cout << "AQUI" << endl;
#define int long long
using namespace std;

vector <vector <int> > sumMatrix (vector <vector<int> > vec, vector <vector <int> > vec2 ){

    vector <vector<int> > aux(1000);

    for(int i=0;i<vec[0].size();i++){
        for(int j=0;j<vec[0].size();j++){
            aux[i].push_back(vec[i][j]+vec2[i][j]);
        }
    }

    return aux;
}

vector <vector <int> > subMatrix (vector <vector<int> > vec , vector<vector <int> >  vec2 ){

    vector <vector<int> > aux(1000);

    for(int i=0;i<vec[0].size();i++){
        for(int j=0;j<vec[0].size();j++){
            aux[i].push_back(vec[i][j]-vec2[i][j]);
        }
    }

    return aux;
}


vector <vector<int> > dividir(vector <vector<int> > vec, vector <vector<int> > vec2){

        if(vec[0].size()==1){
            vector <vector<int> > aux2(1000);

            aux2[0].push_back(vec[0][0]*vec2[0][0]);

            return aux2;
        }

    vector <vector<int> > A11(1000);
    vector <vector<int> > A12(1000);
    vector <vector<int> > A21(1000);
    vector <vector<int> > A22(1000);
    vector <vector<int> > B11(1000);
    vector <vector<int> > B12(1000);
    vector <vector<int> > B21(1000);
    vector <vector<int> > B22(1000);


    for(int i=0; i<vec[0].size()/2;i++){
        for(int j=0;j<vec[0].size()/2;j++){
            A11[i].push_back(vec[i][j]);
            B11[i].push_back(vec2[i][j]);

        }
    }

    for(int i=0;i<vec[0].size()/2;i++){
        for(int j=vec[0].size()/2;j<vec[0].size();j++){
            A12[i].push_back(vec[i][j]);
            B12[i].push_back(vec2[i][j]);

        }
    }

    int linha=0;
    for(int i=vec[0].size()/2;i<vec[0].size();i++){
        for(int j=0;j<vec[0].size()/2;j++){
            A21[linha].push_back(vec[i][j]);
            B21[linha].push_back(vec2[i][j]);
        }
        linha++;
    }

    linha=0;
    int coluna=0;
    for(int i=vec[0].size()/2;i<vec[0].size();i++){
        for(int j=vec[0].size()/2;j<vec[0].size();j++){
            A22[linha].push_back(vec[i][j]);
            B22[linha].push_back(vec2[i][j]);
        }
        linha++;
    }



    vector <vector<int> > P1(1000);
    vector <vector<int> > P2(1000);
    vector <vector<int> > P3(1000);
    vector <vector<int> > P4(1000);
    vector <vector<int> > P5(1000);
    vector <vector<int> > P6(1000);
    vector <vector<int> > P7(1000);

    vector <vector<int> > aux3(1000);


    P1 = dividir(sumMatrix(A11,A22),sumMatrix(B11,B22));
    P2 = dividir(sumMatrix(A21,A22),B11);
    P3 = dividir(A11,subMatrix(B12,B22));
    P4 = dividir(A22,subMatrix(B21,B11));
    P5 = dividir(sumMatrix(A11,A12),B22);
    P6 = dividir(subMatrix(A21,A11),sumMatrix(B11,B12));
    P7 = dividir(subMatrix(A12,A22),sumMatrix(B21,B22));
    vector <vector <int> > C11(1000);
    vector <vector <int> > C12(1000);
    vector <vector <int> > C21(1000);
    vector <vector <int> > C22(1000);

    vector <vector <int> > aux(1000);
    C11 = sumMatrix(subMatrix(sumMatrix(P1,P4),P5),P7);
    C12 = sumMatrix(P3,P5);
    C21 = sumMatrix(P2,P4);
    C22 = sumMatrix(subMatrix(P1,P2),sumMatrix(P3,P6));

    int m=0,n=0;

    for(int i=0;i<C11[0].size();i++){
        n=0;
        for(int j=0;j<C11[0].size();j++){
            aux[i].push_back(C11[m][n]);
            n++;
        }
        m++;
    }

    m=0;
    for(int i=0;i<C11[0].size();i++){
        n=0;
        for(int j=C11[0].size();j<C11[0].size()+C12[0].size();j++){
            aux[i].push_back(C12[m][n]);
            n++;
        }
        m++;
    }

    m=0;
    for(int i=C11[0].size();i<C11[0].size()*2;i++){
        n=0;
        for(int j=0;j<C11[0].size();j++){
            aux[i].push_back(C21[m][n]);
            n++;
        }
        m++;
    }

    m=0;
    for(int i=C11[0].size();i<C11[0].size()*2;i++){
        n=0;
        for(int j=0;j<C11[0].size();j++){
            aux[i].push_back(C22[m][n]);
            n++;
        }
        m++;
    }

    return aux;
}

vector < vector<int> > verificarMatriz(vector < vector<int> > vec,int tamanho){
    vector < vector<int> > aux(1000);
    aux=vec;

    int potencia=2;
    int contador=1;

    while(potencia<=tamanho){
        potencia*=2;
            if(potencia==tamanho){
                return aux;
            } else if (potencia>tamanho){
                int qt = potencia-tamanho;
                for(int i=0;i<tamanho;i++){
                    for(int j=0;j<qt;j++){
                        aux[i].push_back(0);
                    }
                }

                for(int i=tamanho;i<potencia;i++){
                    for(int j=0;j<potencia;j++){
                        aux[i].push_back(0);
                    }
                }
            }
    }


}

int main(){ //Strassen algorithm
    //Funciona apenas com matrizes 2^n

    vector < vector<int> > vec(1000);
    vector < vector<int> > vec2(1000);

    int count = 0;
    int tam;

    cout << "Tamanho das matrizes : " << endl;
    int tamanho;
    cin >> tamanho;

    cout << "Primeira matriz : " << endl;
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            int element;
            cin >> element;
            vec[i].push_back(element);
        }
    }

    cout << "Segunda matriz : " << endl;
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            int element;
            cin >> element;
            vec2[i].push_back(element);
        }
    }
    vector < vector<int> > auxiliar(1000);
    vector < vector<int> > auxiliar2(1000);

    auxiliar = verificarMatriz(vec,tamanho);
    auxiliar2 = verificarMatriz(vec2,tamanho);

    vector <vector <int> > resultado(1000);
    resultado = dividir(auxiliar,auxiliar2);

    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            cout << resultado[i][j] << " ";
        } cout << endl;
    }

    return 0;
}
