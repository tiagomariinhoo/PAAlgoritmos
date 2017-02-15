#include <bits/stdc++.h>
#define INF -10000000001
#define DEBUG cout << "AQUI" << endl;
using namespace std;

vector <vector <long long> > sumMatrix (vector <vector<long long> > vec, vector <vector <long long> > vec2 ){

    vector <vector<long long> > aux(vec[0].size());

    for(long long i=0;i<vec[0].size();i++){
        for(long long j=0;j<vec[0].size();j++){
            aux[i].push_back(vec[i][j]+vec2[i][j]);
        }
    }

    return aux;
}

vector <vector <long long> > subMatrix (vector <vector<long long> > vec , vector<vector <long long> >  vec2 ){

    vector <vector<long long> > aux(vec[0].size());

    for(long long i=0;i<vec[0].size();i++){
        for(long long j=0;j<vec[0].size();j++){
            aux[i].push_back(vec[i][j]-vec2[i][j]);
        }
    }

    return aux;
}


vector <vector<long long> > dividir(vector <vector<long long> > vec, vector <vector<long long> > vec2){

        if(vec[0].size()==1){
            vector <vector<long long> > aux2(vec[0].size());

            aux2[0].push_back(vec[0][0]*vec2[0][0]);

            return aux2;
        }

    vector <vector<long long> > A11((int)vec[0].size());
    vector <vector<long long> > A12((int)vec[0].size());
    vector <vector<long long> > A21((int)vec[0].size());
    vector <vector<long long> > A22((int)vec[0].size());
    vector <vector<long long> > B11((int)vec[0].size());
    vector <vector<long long> > B12((int)vec[0].size());
    vector <vector<long long> > B21((int)vec[0].size());
    vector <vector<long long> > B22((int)vec[0].size());


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

//DEBUG;
    int linha=0;
    for(long long i=vec[0].size()/2;i<vec[0].size();i++){
        for(long long j=0;j<vec[0].size()/2;j++){
            A21[linha].push_back(vec[i][j]);
            B21[linha].push_back(vec2[i][j]);
        }
        linha++;
    }
//DEBUG;

    linha=0;
    long long coluna=0;
    for(long long i=vec[0].size()/2;i<vec[0].size();i++){
        for(long long j=vec[0].size()/2;j<vec[0].size();j++){
            A22[linha].push_back(vec[i][j]);
            B22[linha].push_back(vec2[i][j]);
        }
        linha++;
    }
    //cout << "Passou da conc" << endl;


    vector <vector<long long> > P1(vec[0].size());
    vector <vector<long long> > P2(vec[0].size());
    vector <vector<long long> > P3(vec[0].size());
    vector <vector<long long> > P4(vec[0].size());
    vector <vector<long long> > P5(vec[0].size());
    vector <vector<long long> > P6(vec[0].size());
    vector <vector<long long> > P7(vec[0].size());

    vector <vector<long long> > aux3(vec[0].size());


    P1 = dividir(sumMatrix(A11,A22),sumMatrix(B11,B22));
    P2 = dividir(sumMatrix(A21,A22),B11);
    P3 = dividir(A11,subMatrix(B12,B22));
    P4 = dividir(A22,subMatrix(B21,B11));
    P5 = dividir(sumMatrix(A11,A12),B22);
    P6 = dividir(subMatrix(A21,A11),sumMatrix(B11,B12));
    P7 = dividir(subMatrix(A12,A22),sumMatrix(B21,B22));
    vector <vector <long long> > C11(vec[0].size());
    vector <vector <long long> > C12(vec[0].size());
    vector <vector <long long> > C21(vec[0].size());
    vector <vector <long long> > C22(vec[0].size());
    //cout <<"Passou dos PS"<<endl;
    vector <vector <long long> > aux(vec[0].size());
    C11 = sumMatrix(subMatrix(sumMatrix(P1,P4),P5),P7);
    C12 = sumMatrix(P3,P5);
    C21 = sumMatrix(P2,P4);
    C22 = sumMatrix(subMatrix(P1,P2),sumMatrix(P3,P6));
    //cout << "Passou dos CS" << endl;
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

int verificarMatriz(vector < vector<long long> > vec,long long tamanho){

    long long potencia=2;
    long long contador=1;

    while(potencia<=tamanho){
        potencia*=2;
            if(potencia==tamanho){
                return tamanho;
            } else if (potencia>tamanho){
                long long qt = potencia-tamanho;
               return potencia;
            }
    }

}

vector < vector<long long> > alocarMatriz(vector < vector<long long> > vec, int tamanho1, int tamanho2){
                int qt = tamanho2-tamanho1;

                vector < vector<long long> > aux(tamanho2);
                aux = vec;
                //cout << "aux  size : " << aux[0].size();

                for(long long i=0;i<tamanho1;i++){
                    for(long long j=0;j<qt;j++){
                        aux[i].push_back(0);
                    }
                }

                for(long long i=tamanho1;i<tamanho2;i++){
                    for(long long j=0;j<tamanho2;j++){
                        aux[i].push_back(0);
                    }
                }

                return aux;
}



int main(){ //Strassen algorithm
    //Funciona apenas com matrizes 2^n

    //vector < vector<long long> > vec(10000);
    //vector < vector<long long> > vec2(10000);

    long long count = 0;
    long long tam;

    cout << "Tamanho das matrizes : " << endl;
    long long tamanho;
    cin >> tamanho;

    vector < vector<long long> > vec(tamanho+tamanho);
    vector < vector<long long> > vec2(tamanho+tamanho);

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

    int tamanho2 = verificarMatriz(vec,tamanho);

    vector < vector<long long> > auxiliar(tamanho2+1);
    vector < vector<long long> > auxiliar2(tamanho2+1);

    auxiliar = alocarMatriz(vec,tamanho,tamanho2);
    auxiliar2 = alocarMatriz(vec2,tamanho,tamanho2);

    vector <vector <long long> > resultado(tamanho2);
    resultado = dividir(auxiliar,auxiliar2);


    for(long long i=0;i<tamanho;i++){
        for(long long j=0;j<tamanho;j++){
            cout << resultado[i][j] << " ";
        } cout << endl;
    }

    return 0;
}
