const int N = 100001;
int l[N], r[N], p[N], rev[N]; 
bool rt[N];
int n;
#define lx l[x]
#define rx r[x]
inline void Release(int x){
    if (x == 0) return;  
    if (rev[x]){
        swap(lx, rx);
        rev[lx] ^= 1, rev[rx] ^= 1;
        rev[x] = 0;
    }
}
inline void Set(int l[], int y, int x){
    l[y] = x, p[x] = y;
}
#define z p[y]
inline void Rotate(int x){
    int y = p[x];
    if (!rt[y]) Release(z), Set(y == l[z] ? l : r, z, x);
    else p[x] = z;  
    Release(y), Release(x);    
    if (x == l[y]) Set(l, y, rx), Set(r, x, y);
    else Set(r, y, lx), Set(l, x, y); 
    if (rt[y]) rt[y] = false, rt[x] = true;
}
inline void Splay(int x){
    while (!rt[x]) Rotate(x);
}
int Access(int x){
    int y = 0; do{
        Splay(x), Release(x);
        rt[rx] = true, rt[rx = y] = false;
        x = p[y = x];
    } while (x);
    return y;
}
inline int Root(int x){
    for (x = Access(x); Release(x), lx ; x = lx);
    return x;
}
inline void Evert(int x){
    rev[Access(x)] ^= 1;
}
bool Query(int x, int y){
    return Root(x) == Root(y);
}
void Link(int x, int y){   
    if (Root(x) == Root(y)) return; 
    Evert(x), Splay(x), p[x] = y, Access(x);
}
void Cut(int x, int y){ 
    Evert(y), Splay(y), Access(x), Splay(x);   
    if (lx != y) return;  
    p[lx] = p[x], rt[lx] = true, p[x] = lx = 0;
}
void startLCT(int n){
	for(int i = 1; i <=n; ++i)rt[i] = true;
}
