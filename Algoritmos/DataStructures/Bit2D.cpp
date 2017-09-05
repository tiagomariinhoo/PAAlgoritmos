int bit[MAX][MAX], n, m;
int query( int x, int y ){
    int ret = 0;
    while( x > 0 ){
        int yy = y;
        while( yy > 0 )
            ret += bit[x][yy], yy -= yy & -yy;
        x -= (x & -x);
    }
    return ret;
}
void update(int x , int y , int val){
    int y1;
    while (x <= n){
        y1 = y;
        while (y1 <= m) {
            bit[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}
int querySq(int x, int xx, int y, int yy){
    return  query(xx, yy)+query(x-1, y-1)-query(x-1, yy)-query(xx, y-1);;
}