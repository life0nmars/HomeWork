#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int c;
	int d;
	int max = 0;               
	int*a = new int[10];
	for (int i = 0; i < 10; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> c;
		d = 0;
		while (c != 0) {
			d++;
			c = c / 10;
		}
		a[d]++;
	}
	for (int i = 0; i < 10; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (max == a[i]) {
			cout << i << " " << a[i];
			system("pause");
			return 0;
		}
	}
	return 0;
}
