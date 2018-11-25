#include "pch.h"
#include <iostream>
using namespace std;


int arrSimpleDiv(int X, int *mArr) {
	int kDiv=0; 
	int i, tDiv, valX;
	if (X < 0) { X = -X; }
	valX = X;
	tDiv = 1; 
	i = 2;
	while (valX > 1) {
		if (valX%i == 0) { 
			if (i > tDiv) {
				kDiv++;
				tDiv = i; 
				mArr[kDiv - 1] = tDiv;
			}
			valX = valX / i;
		}
		else { 
			i++;
		}
	}

	return kDiv;
}



int main()
{
	int varX, i, i1, i2, cntDivI, cntDivT, eler;
	int *ptrIsx = new int[32]; 
	int *ptrTek = new int[32]; 
	bool naiden;

	setlocale(LC_ALL, "Rus"); 

	eler = 1;
	cout << endl << "Введите число для которого нужно найти функцию Эйлера:"<< endl;
	cin >> varX;

	cntDivI = arrSimpleDiv(varX, ptrIsx); 

	for (i = 2; i < varX; i++) { 
		cntDivT = arrSimpleDiv(i, ptrTek); 
		naiden = false; 
		for (i1 = 0; i1 < cntDivT; i1++) {
			for (i2 = 0; i2 < cntDivI; i2++) { 
				if (ptrTek[i1] == ptrIsx[i2]) { 
					naiden = true;
					break;
				}
				if (naiden == true) { break; }
			}
		}
		if (naiden == false) { eler = eler + 1; }
	}

	cout << endl << "Функция Эйлера: " << eler << endl;

	delete[] ptrIsx;
	delete[] ptrTek;

    return 0; 
}
