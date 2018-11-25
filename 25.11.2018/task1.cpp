int i, vI, maxStep, sum2000, cntAnsw, valX, valY;

	setlocale(LC_ALL, "Rus");

	sum2000 = 2018 + 2019;
	maxStep = 78487894 / sum2000;
	cntAnsw = 0;

	for (i = 0; i <= maxStep; i++) {
		vI = 78487894 - sum2000 * i;
		if (vI % 2018 == 0) { 
			if ((vI / 2018) > 0) {
				cntAnsw++;
				valY = i;
				valX = valY + vI / 2018;
				cout << "Решение " << cntAnsw << ":  X = " << valX << "  Y = " << valY << endl;
			}
		}
		if (vI % 2019 == 0) { 
			cntAnsw++;
			valX = i;
			valY = valX + vI / 2019;
			cout << "Решение " << cntAnsw << ":  X = " << valX << "  Y = " << valY << endl;
		}
	}

	return 0;
}
