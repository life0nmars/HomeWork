#include <iostream>
#include <ctime> 
using namespace std;
int main()
{
	int N; 
	int i,j,iMax,jMax,maxVal,multVar,startTime,endTime;
  setlocale(LC_ALL, "Rus"); 

	cout << "Введите размер последовательности (не менее 6): " << endl;
	cin >> N;

	if (N < 6) {
		cout << endl << "Неправильно задан размер последовательности! Обработка прервана..." << endl;
		return 0;
	}

	int *masVal = new int[N];
	for (i = 0; i < N; i++) {
		masVal[i] = rand();
	}
  startTime=time(NULL);
	iMax = 0;
	jMax = 5;
	maxVal = masVal[0] * masVal[5];
	for (i = 0; (i + 5) < N; i++) { 
		for (j = (i + 5); j < N; j++) { 
			multVar = masVal[i] * masVal[j];
			if (multVar > maxVal) {
				iMax = i;
				jMax = j;
				maxVal = multVar;
			}
		}
	}
	endTime = time(NULL); 
	cout << endl << "Выполнение заняло (с): " << endTime-startTime << endl;
	cout << endl << "Искомые номера последовательности: " << iMax+1 << " и " << jMax+1 << endl;
	cout << endl << "Максимальное произведение: " << maxVal << endl;

	cout << endl << "Исходные данные: " << endl;
	for (i = 0; i < N; i++) {
		cout << masVal[i] << endl;
	}
	*/
	//
	return 0;
}
