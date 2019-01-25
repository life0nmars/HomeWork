#include <iostream>
#include <ctime> 
using namespace std;

struct rowMas { int valSort; int curVal; };

void MyQuickSort_2(rowMas *vMas, int maxN) { 
	int cntL = 0, cntC = 0, cntR = 0; 
	int halfR = maxN / 2;
	int basis = vMas[halfR].curVal; 
	rowMas *masL = new rowMas[maxN];
	rowMas *masC = new rowMas[maxN];
	rowMas *masR = new rowMas[maxN];
	if (maxN > 1) {
		for (int i = 0; i < maxN; i++) {
			if (vMas[i].curVal < basis) {
				cntL++; 
				masL[cntL - 1] = vMas[i];
			}
			else if (vMas[i].curVal > basis) {
				cntR++;
				masR[cntR - 1] = vMas[i];
			}
			else {
				cntC++;	
				masC[cntC - 1] = vMas[i];
			}
		}
		MyQuickSort_2(masL, cntL); 
		MyQuickSort_2(masR, cntR); 
	}

	int iPos = -1;
	for (int i = 0; i < cntL; i++) { 
		iPos++;
		vMas[iPos] = masL[i];
	}
	for (int i = 0; i < cntC; i++) { 
		iPos++;
		vMas[iPos] = masC[i];
	}
	for (int i = 0; i < cntR; i++) { 
		iPos++;
		vMas[iPos] = masR[i];
	}
}

void MyQuickSort_1(rowMas *vMas, int maxN) {
	int cntL = 0, cntC = 0, cntR = 0; 
	int halfR = maxN / 2;
	int basis = vMas[halfR].valSort; 
	rowMas *masL = new rowMas[maxN]; 
	rowMas *masC = new rowMas[maxN];
	rowMas *masR = new rowMas[maxN];
	if (maxN > 1) {
		for (int i = 0; i < maxN; i++) {
			if (vMas[i].valSort < basis) {
				cntL++; 
				masL[cntL - 1] = vMas[i];
			}
			else if (vMas[i].valSort > basis) {
				cntR++; 
				masR[cntR - 1] = vMas[i];
			}
			else {
				cntC++;	 
				masC[cntC - 1] = vMas[i];
			}
		}
		if (cntC > 0) {
			MyQuickSort_2(masC, cntC);
		}
		MyQuickSort_1(masL, cntL); 
		MyQuickSort_1(masR, cntR); 
	}

	int iPos = -1;
	for (int i = 0; i < cntL; i++) { 
		iPos++;
		vMas[iPos] = masL[i];
	}
	for (int i = 0; i < cntC; i++) {
		iPos++;
		vMas[iPos] = masC[i];
	}
	for (int i = 0; i < cntR; i++) { 
		iPos++;
		vMas[iPos] = masR[i];
	}
}

int main()
{

	int N; 
	int i, j, maxVal, sumVar, startTime, endTime;

	setlocale(LC_ALL, "Rus"); 

	cout << "Введите размер последовательности (не менее 7): " << endl;
	cin >> N;

	if (N < 7) {
		cout << endl << "Неправильно задан размер последовательности! Обработка прервана..." << endl;
		return 0;
	}

	rowMas *masVal = new rowMas[N]; 
	for (i = 0; i < N; i++) {
		masVal[i].valSort = rand();
	}

	startTime = time(NULL);

	MyQuickSort_1(masVal, N); 
	i = N - 1;
	maxVal = -1;
	for (j = i - 1; j >= 0; j--) {
		if (abs(masVal[i].curVal - masVal[j].curVal) >= 6) { 
			sumVar = masVal[i].valSort * masVal[j].valSort;
			if ((sumVar % 2) == 0) { 
				maxVal = sumVar;
				break;
			}
		}
	}

	if (maxVal == -1) { 
		cout << endl << "Бета-значение: " << maxVal << endl;
		return 0;
	}
	for (i = N - 2; i >= 0; i--) {
		sumVar = -1;
		for (j = i - 1; j >= 0; j--) { 
			if (abs(masVal[i].curVal - masVal[j].curVal) >= 6) { 
				sumVar = masVal[i].valSort * masVal[j].valSort;
				if ((sumVar % 2) == 0) { 
					break;
				}
			}
		}
		if ((sumVar % 2) == 0) { 
			if (sumVar <= maxVal) { 
				break;
			}
			maxVal = sumVar;
		}
	}

	endTime = time(NULL); 
	cout << endl << "Выполнение заняло (с): " << endTime - startTime << endl;
	cout << endl << "Бета-значение: " << maxVal << endl;
	cout << endl << "Исходные данные: " << endl;
	for (i = 0; i < 30; i++) {
		cout << masVal[i].valSort << " " << masVal[i].curVal << endl;
	}
	for (i = N - 30; i < N; i++) {
		cout << masVal[i].valSort << " " << masVal[i].curVal << endl;
	}
	

	return 0;
}
