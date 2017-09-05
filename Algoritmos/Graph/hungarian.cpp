#define hungType double
hungType mcost[MAX][MAX]; // cost matrix
hungType hung(const int &n, const int &m) { // idx start 1 ( n <= m)
    vector<hungType> u(n+1), v(m+1), minv;
    vector<int> par(m+1), next(m+1);
    vector<char>vstd;
    repn(i, 1, n) {
        par[0] = i;
        int idj = 0;
        minv.assign(m+1, linf);
        vstd.assign(m+1, false);
        do {
            vstd[idj] = true;
            int idi = par[idj], temp;
            hungType det = linf;
            repn(j, 1, m) if (!vstd[j]) {
                hungType cur = mcost[idi][j]-u[idi]-v[j];
                if (cur < minv[j])minv[j] = cur,  next[j] = idj;
                if (minv[j] < det)det = minv[j],  temp = j;
            }
            repn(j, 0, m){
                if (vstd[j])u[par[j]]+=det, v[j]-=det;
                else minv[j]-=det;
            }
            idj = temp;
        } while (par[idj]);
        do {
            int temp = next[idj];
            par[idj] = par[temp];
            idj = temp;
        } while (idj);
    }
    return abs(v[0])+eps;
}
