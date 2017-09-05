const int MAX = 1e6+10;
int SZ = 500;
long long sum, ans[MAX];
ii query[MAX];
bool comp_q(const int &a, const int &b){
    if(query[a].fi/SZ != query[b].fi/SZ)return query[a].fi/SZ < query[b].fi/SZ;
    return query[a].se < query[b].se;
}
int a[MAX], place[MAX], cnt[MAX], n, m;
void add(int id){
    sum += (long long)id*(2ll*cnt[id]+1);
    ++cnt[id];
}
void rem(int id){
    sum += (long long)id*(-2ll*cnt[id]+1);
    --cnt[id];
}
int main(){
    sc2(n, m);
    SZ = sqrt(n);
    if(sqr(SZ) < n)++SZ;
    repn(i, 1, n)sc(a[i]);
    rep(i, 0, m)sc2(query[i].fi, query[i].se), place[i] = i;
    sort(place, place+m, comp_q);
    int L = 1, R = 1;
    add(a[1]);
    rep(i, 0, m){
        int lf = query[place[i]].fi;
        int rg = query[place[i]].se;
        while(lf < L)add(a[--L]);
        while(lf > L)rem(a[L++]);
        while(rg < R)rem(a[R--]);
        while(rg > R)add(a[++R]);
        ans[place[i]] = sum;
    }   
    rep(i, 0, m)printf("%lld\n", ans[i]);
    return 0;
}