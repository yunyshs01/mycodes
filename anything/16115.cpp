#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define pi  acos(-1);

double DEGof(double radian) {
	return radian * 180 / pi;
}


double angleof(pair<int, int> p) {
	if (p.first == 0) {
		return p.second > 0 ? 90 : 270;
	}
	else if (p.second == 0) {
		return p.first > 0 ? 0 : 180;
	}
	else
	{
		return DEGof(atan2(p.second, p.first));
	}
}

int main() {
	vector<pair<int, int>> vec;
	vector<int> rad;
	vector<double> angle;
	int n;
	cin >> n;

	int maxRad = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int curRad = a*a + b*b;
		if (maxRad < curRad)maxRad = curRad;
		pair<int, int> p(a, b);
		rad.push_back(curRad);
		vec.push_back(p);
	}

	for (auto it = vec.begin(); it != vec.end();) {
		int curRad = (it->first)*(it->first) + (it->second)*(it->second);
		if (curRad < maxRad) {
			it = vec.erase(it);
		}
		else {
			rad.push_back(curRad);
			it++;
		}

	}
	for (int i = 0; i < vec.size(); i++) {
		angle.push_back(angleof(vec[i]));
	}
	angle.push_back(angle[0]);


	//for (int i = 0; i < angle.size(); i++) {
	//	cout << angle[i] << ' ';
	//}
	//cout << endl;
	//
	double max = 0.0;
	for (int i = 0; i < angle.size() - 1; i++) {
		double curdif = angle[i + 1] - angle[i];
		if (curdif < 0)curdif += 360;
		if (max < curdif)max = curdif;
	}

	cout.precision(6);

	cout << fixed << max << endl;


}
