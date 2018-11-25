#include "pch.h"
#include <iostream>
using namespace std;


void findElement(int *ptrN,int lenN, int k)
{	/*
	Эффективная, потому что работает
	*/
	int i, j, cntZifr, cntElem, valX, multiZ;

	int *ptrZ = new int[10]; 

	cntElem = 0;
	for (i = 0; i < lenN; i++) { 
		valX = ptrN[i];
		if (valX < 0) { valX = -valX; }
		cntZifr = 0;
		if (valX == 0) { 
			cntZifr++;
			ptrZ[cntZifr - 1] = 0;
		}

		while (valX >= 1) {
			cntZifr++;
			ptrZ[cntZifr - 1] = valX % 10;
			valX = valX / 10;
		}
		
		multiZ = 0;
		for (j = 0; j < cntZifr; j++) {
			if (ptrZ[j] > 0) {
				if (multiZ == 0) { 
					multiZ = ptrZ[j];
				}
				else { 
					multiZ = multiZ * ptrZ[j];
				}
			}
		}
		
		if (multiZ > k) {
			cntElem++;
			cout << "Элемент " << i+1 << " (" << ptrN[i] << ") произведение цифр: " << multiZ << endl;
		}
	}

	cout << endl << "Всего найдено элементов по условию: " << cntElem << endl;

	delete[] ptrZ;
}



int main()
{	
	int i, lenNM, kM;

	setlocale(LC_ALL, "Rus");

	cout << "Введите длину массива N и число K (произведение цифр элемента больше него) через пробел: " << endl;
	cin >> lenNM >> kM;
	if (lenNM < 1) {
		cout << "Некорректная длина массива. Стоп программа..." << endl;
		return 0;
	}

	int *ptrNM = new int[lenNM]; 
	for (i = 0; i < lenNM; i++) {
		cout << "Введите " << i + 1 << " число массива: ";
		cin >> ptrNM[i];
	}

	cout << endl;

	findElement(ptrNM, lenNM, kM);

	delete[] ptrNM;
	return 0;
}
