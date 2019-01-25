#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int*a = new int[N];
	int*b = new int[N];
	int res = 1;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((a[i] % 2 != 0) && (a[i] % 3 == 0)) {
				a[i] = b[j];
			}
		}
	}
	delete[] a;
	for (int j = 0; j < N; j++) {
		res *= b[j];
	}
	cout << res;
	system("pause");
	return 0;
}
