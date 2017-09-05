int N, M, v[MAXN], st[5*MAXN], lazy[5*MAXN];
int left(int p){
    return (p << 1);
}
int right(int p){
    return (p << 1) + 1;
}
void build_tree(int p, int L, int R){
    lazy[p] = -1;
    if(L == R){
        st[p] = v[L];
        return;
    }
    int mid = (L + R) >> 1;
    build_tree(left(p), L, mid);
    build_tree(right(p), mid+1, R);
    st[p] = st[left(p)] ^ st[right(p)];
}

void propagate(int p, int L, int R){
    if(lazy[p] != -1){
        if((R-L+1) & 1)st[p] = lazy[p];
        else st[p] = 0;
        if(L != R)lazy[left(p)] = lazy[right(p)] = lazy[p];
    }
    lazy[p] = -1;
}
void update(int p, int L, int R, int i, int j, int val){
    propagate(p, L, R); 
    if(L > j or R < i)return;
    if(L >= i and R <= j){
        lazy[p] = val;
        propagate(p, L, R);
        return;
    }
    int mid = (L + R) >> 1;
    update(left(p), L, mid, i, j, val);
    update(right(p), mid+1, R, i, j, val);
    st[p] = st[left(p)] ^ st[right(p)];
}

void update(int i, int j, int val){
    update(1, 0, N-1, i, j, val);
}
int main(){        
    while(scanf("%d%d", &N, &M) > 0){
        for(int i=0; i<N; i++){
            scanf("%d", &v[i]);
        }
        build_tree(1, 0, N-1);   
        while(M--){
            int X, Y, V;
            scanf("%d%d%d", &X, &Y, &V);
            update(X-1, Y-1, V);
            printf("%s\n", st[1] ? "Possivel" : "Impossivel");
        }
    }
}
