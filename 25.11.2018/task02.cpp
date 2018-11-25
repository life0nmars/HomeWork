#include "pch.h"
#include <iostream>
using namespace std;
 int main()
{	int lenN, halfLen, noEven, i, dopoln, dopCentr, leftHalf, rightHalf;
	int lowInd, highInd, cntPalindrom, Palindrom, valX, j, xx;
 	setlocale(LC_ALL, "Rus");
 	cout << "Введите длину числа (больше 1,но не больше 9): " << endl;
	cin >> lenN;
	if (lenN <= 1) { 
		cout << "Некорректная длина. Стоп программа..." << endl;
		return 0;
	}
	
	if (lenN > 9) { lenN = 9; }
	halfLen = lenN / 2;
	noEven = lenN % 2; 
	int *ptrZ = new int[halfLen]; 
 	dopoln = 1;
	dopCentr = 0; 
	for (i = 1; i <= halfLen; i++) { dopoln = dopoln * 10; }
 	lowInd = dopoln / 10; 
	highInd = lowInd * 10 - 1;
 	if (noEven > 0) { 
		dopCentr = dopoln;
		dopoln = dopoln * 10;
	}
 	cout << endl;
	cntPalindrom = 0;
	for (i = lowInd; i <= highInd; i++) { 
		leftHalf = i;
		valX = i;
		for (j = 1; j <= halfLen; j++) { 
			ptrZ[halfLen - j] = valX % 10;
			valX = valX / 10;
		}
		
		rightHalf = 0;
		for (j = 1; j <= halfLen; j++) { 
			rightHalf = rightHalf * 10 + ptrZ[halfLen - j];
		}
 		if (noEven == 0) {
			cntPalindrom++;
			Palindrom = leftHalf * dopoln + rightHalf;
//			cout << "Палиндром " << cntPalindrom << ": " << Palindrom << endl; 
		}
		else { 
			for (j = 0; j <= 9; j++) { 
				cntPalindrom++;
				Palindrom = leftHalf * dopoln + dopCentr*j + rightHalf;
//				cout << "Палиндром " << cntPalindrom << ": " << Palindrom << endl;
			}
		}
	}
 	cout << endl << "Всего палиндромов: " << cntPalindrom << endl;
 	delete[] ptrZ;
    return 0; 
}
