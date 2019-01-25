#include <iostream>
using namespace std;
int main() {
	int lift = 0;
	int length = 0;
	int* x = new int[2];
	int n = 1;
	cin >> x[0];
	while (x[0] != 0) {
		cin >> x[1];             
		n++;
		if ((x[0] < x[1])) {
			length = length + x[1] - x[0];
		}
		else {
			if (length > lift) {
				lift = length;
				length = 0;
			}
			else {
				length = 0;
			}
		}
		x[0] = x[1];
	}
	cout << n << " numbers have received ";
	cout << "Highest lift height is " << lift;
	return 0;
}
