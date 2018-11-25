#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int X, valX, i, j, cntSimple, cntChen;
	bool isSimpl;

	setlocale(LC_ALL, "Rus");
	cout << "Введите число N: " << endl;
	cin >> X;
	if (X <= 2) { 
		cout << "Чисел Ченя: 0" << endl;
		return 0;
	}
	
	int *ptrSm = new int[(X / 2)+2]; 
	ptrSm[0] = 2;
	cntSimple = 1;
	for (i = 3; i < X; i += 2) {
		isSimpl = true;
		for (int j = 2; j < i; j++) { 
			if (i%j == 0) {
				isSimpl = false;
				break;
			}
		}
		if (isSimpl) {
			cntSimple++;
			ptrSm[cntSimple - 1] = i;
		}
	}
	i = X;
	while (true) {
		isSimpl = true;
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				isSimpl = false;
				break;
			}
		}
		if (isSimpl) {
			ptrSm[cntSimple] = i;
			break;
		}
		i++;
	}

	cout << endl;
	cntChen = 0;
	for (i = 0; i < cntSimple; i++) {
		if ((ptrSm[i] + 2) == ptrSm[i + 1]) { 
			cntChen = cntChen + 1;
			cout << "Число Ченя " << cntChen << ": " << ptrSm[i] << endl; 
		} 
		else { 
			valX = ptrSm[i] + 2;
			for (j = 0; j <= i; j++) { 
				if ((valX % ptrSm[j]) == 0) {
					valX = valX / ptrSm[j];
					break;
				}
			}
			for (j = 0; j <= i; j++) { 
				if ((valX % ptrSm[j]) == 0) {
					valX = valX / ptrSm[j];
					break;
				}
			}
			if (valX == 1) { 
				cntChen = cntChen + 1;
				cout << "Число Ченя " << cntChen << ": " << ptrSm[i] << endl;
			}

		}
	}

	delete[] ptrSm;
	return 0;
}
