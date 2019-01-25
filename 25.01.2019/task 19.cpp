#include <iostream>
using namespace std;
int main () {
int N;
cin >> N;
int t;
cin >> t;
int A;
int B;
int v = 0;
int tmin = t;        
for (int i = 0; i < N; i++) {
	cin >> A;
	cin >> B;
	v = v + A;
	if (tmin + B > v + t) {
		tmin = v + t;
	}
	else tmin = tmin + B;
}
cout << tmin;
return 0;
}
