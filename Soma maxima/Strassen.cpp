#include <bits/stdc++.h>
#define INF -10000000001
#define DEBUG cout << "AQUI" << endl;
using namespace std;

vector <vector <long long> > sumMatrix (vector <vector<long long> > vec, vector <vector <long long> > vec2 ){

    vector <vector<long long> > aux(10000);

    for(long long i=0;i<vec[0].size();i++){
        for(long long j=0;j<vec[0].size();j++){
            aux[i].push_back(vec[i][j]+vec2[i][j]);
        }
    }

    return aux;
}

vector <vector <long long> > subMatrix (vector <vector<long long> > vec , vector<vector <long long> >  vec2 ){

    vector <vector<long long> > aux(10000);

    for(long long i=0;i<vec[0].size();i++){
        for(long long j=0;j<vec[0].size();j++){
            aux[i].push_back(vec[i][j]-vec2[i][j]);
        }
    }

    return aux;
}


vector <vector<long long> > dividir(vector <vector<long long> > vec, vector <vector<long long> > vec2){

        if(vec[0].size()==1){
            vector <vector<long long> > aux2(10000);

            aux2[0].push_back(vec[0][0]*vec2[0][0]);

            return aux2;
        }

    vector <vector<long long> > A11(10000);
    vector <vector<long long> > A12(10000);
    vector <vector<long long> > A21(10000);
    vector <vector<long long> > A22(10000);
    vector <vector<long long> > B11(10000);
    vector <vector<long long> > B12(10000);
    vector <vector<long long> > B21(10000);
    vector <vector<long long> > B22(10000);


    for(long long i=0; i<vec[0].size()/2;i++){
        for(long long j=0;j<vec[0].size()/2;j++){
            A11[i].push_back(vec[i][j]);
            B11[i].push_back(vec2[i][j]);

        }
    }

    for(long long i=0;i<vec[0].size()/2;i++){
        for(long long j=vec[0].size()/2;j<vec[0].size();j++){
            A12[i].push_back(vec[i][j]);
            B12[i].push_back(vec2[i][j]);

        }
    }

    long long linha=0;
    for(long long i=vec[0].size()/2;i<vec[0].size();i++){
        for(long long j=0;j<vec[0].size()/2;j++){
            A21[linha].push_back(vec[i][j]);
            B21[linha].push_back(vec2[i][j]);
        }
        linha++;
    }

    linha=0;
    long long coluna=0;
    for(long long i=vec[0].size()/2;i<vec[0].size();i++){
        for(long long j=vec[0].size()/2;j<vec[0].size();j++){
            A22[linha].push_back(vec[i][j]);
            B22[linha].push_back(vec2[i][j]);
        }
        linha++;
    }



    vector <vector<long long> > P1(10000);
    vector <vector<long long> > P2(10000);
    vector <vector<long long> > P3(10000);
    vector <vector<long long> > P4(10000);
    vector <vector<long long> > P5(10000);
    vector <vector<long long> > P6(10000);
    vector <vector<long long> > P7(10000);

    vector <vector<long long> > aux3(10000);


    P1 = dividir(sumMatrix(A11,A22),sumMatrix(B11,B22));
    P2 = dividir(sumMatrix(A21,A22),B11);
    P3 = dividir(A11,subMatrix(B12,B22));
    P4 = dividir(A22,subMatrix(B21,B11));
    P5 = dividir(sumMatrix(A11,A12),B22);
    P6 = dividir(subMatrix(A21,A11),sumMatrix(B11,B12));
    P7 = dividir(subMatrix(A12,A22),sumMatrix(B21,B22));
    vector <vector <long long> > C11(10000);
    vector <vector <long long> > C12(10000);
    vector <vector <long long> > C21(10000);
    vector <vector <long long> > C22(10000);

    vector <vector <long long> > aux(10000);
    C11 = sumMatrix(subMatrix(sumMatrix(P1,P4),P5),P7);
    C12 = sumMatrix(P3,P5);
    C21 = sumMatrix(P2,P4);
    C22 = sumMatrix(subMatrix(P1,P2),sumMatrix(P3,P6));

    long long m=0,n=0;

    for(long long i=0;i<C11[0].size();i++){
        n=0;
        for(long long j=0;j<C11[0].size();j++){
            aux[i].push_back(C11[m][n]);
            n++;
        }
        m++;
    }

    m=0;
    for(long long i=0;i<C11[0].size();i++){
        n=0;
        for(long long j=C11[0].size();j<C11[0].size()+C12[0].size();j++){
            aux[i].push_back(C12[m][n]);
            n++;
        }
        m++;
    }

    m=0;
    for(long long i=C11[0].size();i<C11[0].size()*2;i++){
        n=0;
        for(long long j=0;j<C11[0].size();j++){
            aux[i].push_back(C21[m][n]);
            n++;
        }
        m++;
    }

    m=0;
    for(long long i=C11[0].size();i<C11[0].size()*2;i++){
        n=0;
        for(long long j=0;j<C11[0].size();j++){
            aux[i].push_back(C22[m][n]);
            n++;
        }
        m++;
    }

    return aux;
}

vector < vector<long long> > verificarMatriz(vector < vector<long long> > vec,long long tamanho){
    vector < vector<long long> > aux(10000);
    aux=vec;

    long long potencia=2;
    long long contador=1;

    while(potencia<=tamanho){
        potencia*=2;
            if(potencia==tamanho){
                return aux;
            } else if (potencia>tamanho){
                long long qt = potencia-tamanho;
                for(long long i=0;i<tamanho;i++){
                    for(long long j=0;j<qt;j++){
                        aux[i].push_back(0);
                    }
                }

                for(long long i=tamanho;i<potencia;i++){
                    for(long long j=0;j<potencia;j++){
                        aux[i].push_back(0);
                    }
                }
            }
    }


}

int main(){ //Strassen algorithm
    //Funciona apenas com matrizes 2^n

    vector < vector<long long> > vec(10000);
    vector < vector<long long> > vec2(10000);

    long long count = 0;
    long long tam;

    cout << "Tamanho das matrizes : " << endl;
    long long tamanho;
    cin >> tamanho;

    cout << "Primeira matriz : " << endl;
    for(long long i=0;i<tamanho;i++){
        for(long long j=0;j<tamanho;j++){
            long long element;
            cin >> element;
            vec[i].push_back(element);
        }
    }

    cout << "Segunda matriz : " << endl;
    for(long long i=0;i<tamanho;i++){
        for(long long j=0;j<tamanho;j++){
            long long element;
            cin >> element;
            vec2[i].push_back(element);
        }
    }
    vector < vector<long long> > auxiliar(10000);
    vector < vector<long long> > auxiliar2(10000);

    auxiliar = verificarMatriz(vec,tamanho);
    auxiliar2 = verificarMatriz(vec2,tamanho);

    vector <vector <long long> > resultado(10000);
    resultado = dividir(auxiliar,auxiliar2);

    for(long long i=0;i<tamanho;i++){
        for(long long j=0;j<tamanho;j++){
            cout << resultado[i][j] << " ";
        } cout << endl;
    }

    return 0;
}
