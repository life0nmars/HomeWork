#include <iostream>
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
	int i, N, curVal,ostDiv,maxCnt;

	setlocale(LC_ALL, "Rus"); 

	cout << "Введите количество чисел: ";	cin >> N;

	int *valN = new int[N]; 
	rowMas *mNum = new rowMas[10]; 
	for (i = 0; i < 10; i++) { 
		mNum[i].valSort = 0;
		mNum[i].curVal = i;
	}
	for (i = 0; i < N; i++) {
		valN[i] = rand();
	}

	for (i = 0; i < N; i++) { 
		if (valN[i] == 0) { mNum[0].valSort = mNum[0].valSort + 1; } 
		else { 
			curVal = valN[i];
			while (curVal > 0) {
				ostDiv = curVal % 10;
				mNum[ostDiv].valSort = mNum[ostDiv].valSort + 1;
				curVal = curVal / 10;
			}
		}
	}

	MyQuickSort_1(mNum, 10); 

	maxCnt = mNum[9].valSort; 

	cout << endl << "Максимальное число повторений цифры: " << maxCnt << endl;
	cout << "конкретно цифры: " << endl;
	for (i = 9; i >= 0; i--) {
		if (mNum[i].valSort == maxCnt) {
			cout << mNum[i].curVal << endl;
		}
	}

	return 0;
}
