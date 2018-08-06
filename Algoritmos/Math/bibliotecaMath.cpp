/*

    3.24 Aritmetica Modular

    Funcoes

        invMod(a,m)

            Devolve o inverso modular (a^(-1))%n do numero a

        powMod(x,k,m)

            Devolve a exponenciacao modular (x^k)%m

        sqrtMod(n,p)

            Devolve a raiz modular (sqrt(n))%p do numero n

        addMod(a,b,m)

            Devolve a soma modular (a+b)%m

        subMod(a,b,m)

            Devolve a subtracao modular (a+b)%m

        mulMod(a,b,m)

            Devolve a multiplicacao modular (a+b)%m

        divMod(a,b,m)

            Devolve a divisao modular (a+b)%m

*/

int extgcd(int a, int b, int &x, int &y)
{
    int g = a; x = 1; y = 0;
    if(b!=0) g = extgcd(b,a%b,y,x), y -= (a/b)*x;
    return g;
}



long long int invMod(long long int a, long long int m)
{
    int x, y;
    if (extgcd(a, m, x, y) == 1) return (x + m) % m;
    else return 0; //Nao Resolvivel
}

long long int powMod(long long int x,long long int k,long long int m)
{
    if(k==0) return 1;
    if(k%2==0) return powMod(x*x%m,k/2,m);
    else return x*powMod(x,k-1,m)%m;
}

int sqrtMod(int n, int p)
{
    int S, Q, W, i, m = invMod(n, p);

    for(Q=p-1,S=0;Q%2==0;Q/=2,++S);

    do{ W=rand()%p; } while(W== 0||jacobi(W,p)!=-1);

    for(int R = powMod(n,(Q+1)/2,p), V=powMod(W,Q,p);;)
    {
        int z=R*R*m%p;
        for(i=0;i<S&&z%p!=1;z*=z,++i);
        if(i==0) return R;
        R=(R*powMod(V,1<<(S-i-1),p))%p;
    }
}

long long int addMod(long long int x, long long int y,long long int n)
{
    return ((x % n) + (y % n)) % n;
}

int subMod(int x, int y, int n)
{
    return ((x % n) - (y % n)) % n;
}

long long int mulMod(long long int x,long long  int y,long long int n)
{
    return ((x % n)*(y % n)) % n;
}

long long int divMod(long long int x,long long int y,long long int n)
{
    return mulMod(x,invMod(y,n),n);
}