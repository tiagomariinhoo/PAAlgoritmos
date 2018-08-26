typedef vector<point> polygon;

double signedArea(polygon & P) {
	double result = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		result += cross(P[i], P[(i+1)%n]);
	}
	return result / 2.0;
}

int leftmostIndex(vector<point> & P) {
	int ans = 0;
	for(int i=1; i<(int)P.size(); i++) {
		if (P[i] < P[ans]) ans = i;
	}
	return ans;
}

polygon make_polygon(vector<point> P) {
	if (signedArea(P) < 0.0) reverse(P.begin(), P.end());
	int li = leftmostIndex(P);
	rotate(P.begin(), P.begin()+li, P.end());
	return P;
}

double perimeter(polygon & P) {
	double result = 0.0;
	for (int i = 0; i < (int)P.size()-1; i++) result += dist(P[i], P[i+1]);
	return result;
}

double area(polygon & P) {
	return fabs(signedArea(P));
}

bool isConvex(polygon & P) {
	int n = (int)P.size();
	if (n < 3) return false;
	bool left = ccw(P[0], P[1], P[2]);
	for (int i = 1; i < n; i++) {
		if (ccw(P[i], P[(i+1)%n], P[(i+2)%n]) != left)
			return false;
	}
	return true;
}

bool inPolygon(polygon & P, point p) { //Colocar pontos em sentido anti horário
	if (P.size() == 0u) return false;
	double sum = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		//if(P[i] == p or between(P[i], p, P[(i+1)%n])) return true; Para incluir borda descomenta
		if (ccw(p, P[i], P[(i+1)%n])) sum += angle(P[i], p, P[(i+1)%n]);
		else sum -= angle(P[i], p, P[(i+1)%n]);
	}
	return fabs(fabs(sum) - 2*acos(-1.0)) < EPS;
}

polygon cutPolygon(polygon & P, point a, point b) {
	vector<point> R;
	double left1, left2;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		left1 = cross(b-a, P[i]-a);
		left2 = cross(b-a, P[(i+1)%n]-a);
		if (left1 > -EPS) R.push_back(P[i]);
		if (left1 * left2 < -EPS) 
			R.push_back(lineIntersectSeg(P[i], P[(i+1)%n], a, b));
	}
	return make_polygon(R);
}