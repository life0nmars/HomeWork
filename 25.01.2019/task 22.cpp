#include <iostream>
using namespace std;
int main() {
	int a = 0, b = 0, sum = 0, N, z = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {                                        
		cin >> a;
		if ((a % 6 != 0) && (b == 0)) {
            z = a;
            b = 1;
		}
		sum = sum + a;
	}
	if ((sum % 6 == 0) && (z == 0)) {
		cout << "n = 0, sum = 0";
		return 0;
	}
	if ((sum % 6 == 0) && (z != 0)) {
	    sum = sum - z;
		cout << "n = " << N - 1 << ", sum = " << sum;
		return 0;
	}
	if (a % 6 != 0) {
	cout << "n = "<< N << ", sum = " << sum;
	}
	return 0;
}
