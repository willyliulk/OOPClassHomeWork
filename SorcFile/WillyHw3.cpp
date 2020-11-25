#include "WillyHw3.h"


using namespace std;

WillyHw3::WillyHw3() {

}

void WillyHw3::fun1() {
	cout << "�@�~ 3 �{�� 1 �A���g�ɶ�120min" << endl;
	int n = 0;
	int *a, *b;
	cout << "�п�J���r�𰪫סG";
	cin >> n;
	cout << "�z��J���r�𰪫סG" << n << endl;
	n = n + 2;
	a = new int[n];
	b = new int[n];
	for (int i = 0; i < n; i++) {
		*(a + i) = 0;
		*(b + i) = 0;
	}
	for (int i = 0; i < n; i++) {
		cout << setw((n - i) * 3) << " ";
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				*(b + j) = 1;
			}
			else if (j == i) {
				*(b + j) = 1;
			}
			else {
				*(b + j) = *(a + j - 1) + *(a + j);
			}
			cout << setw(6) << *(b + j);
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			*(a + i) = *(b + i);
			//cout << *(a + i);
		}
		//cout << "   :a" << endl;
	}
}

void WillyHw3::fun2() {
	cout << "�@�~ 3 �{�� 2 �A���g�ɶ�100min" << endl;
	int math = 0, english = 0;
	int mathRank = 0, englishRank = 0;
	double mathAvg = 0, englishAvg = 0;
	bool mathFound = false, englishFound = false;
	vector<int> mathSheet, englishSheet;
	random_device rd;
	default_random_engine gen = default_random_engine(rd());
	uniform_int_distribution<int> nor(0, 100);
	auto randfun = bind(nor, gen);
	for (int i = 0; i < 200; i++) {
		mathSheet.push_back(randfun());
		englishSheet.push_back(randfun());
	}
	sort(mathSheet.begin(), mathSheet.end(), greater<int>());
	sort(englishSheet.begin(), englishSheet.end(), greater<int>());
	cout << "�п�J�A���ƾǦ��Z �^�妨�Z:" << endl;
	cin >> math >> english;
	cout << "�A���ƾǦ��Z�O" << math << "�A�A���^�妨�Z�O" << english << endl;
	for (int i : mathSheet) {
		mathAvg += i;
	}
	mathAvg = mathAvg / 200;
	for (int i : englishSheet) {
		englishAvg += i;
	}
	englishAvg = englishAvg / 200;
	cout << "�ƾǪ��������Z�O" << mathAvg << "�A�^�媺�������Z�O" << englishAvg << endl;
	for (int i = 0; i < 200; i++) {
		if (math == mathSheet.at(i) && !mathFound) {
			cout << "1�A���ƾǦ��Z�O��" << i << "�W" << endl;
			mathFound = true;
			mathRank = i;
		}
	}
	for (int i = 0; i < 200; i++) {
		if (english == englishSheet.at(i) && !englishFound) {
			cout << "2�A���^�妨�Z�O��" << i << "�W" << endl;
			englishFound = true;
			englishRank = i;
		}
	}
	for (int i = 0, min = 100; i < 200 && !mathFound; i++) {
		if (min > mathSheet.at(i)) {
			min = mathSheet.at(i);
			mathRank = i;
		}
		else {
			mathFound = true;
			cout << "3�A���ƾǦ��Z�b" << i << "��" << i + 1 << "�W����" << endl;
		}
	}
	for (int i = 0, min = 100; i < 200 && !englishFound; i++) {
		if (min > englishSheet.at(i)) {
			min = englishSheet.at(i);
			englishRank = i;
		}
		else {
			englishFound = true;
			cout << "4�A���^�妨�Z�b" << i << "��" << i + 1 << "�W����" << endl;
		}
	}
	if (mathRank < 50) {
		cout << "�ƾǼЪ��O����" << endl;
	}
	else if (mathRank < 100) {
		cout << "�ƾǼЪ��O����" << endl;
	}
	else if (math > mathAvg) {
		cout << "�ƾǼЪ��O����" << endl;
	}
	else if (mathRank < 150) {
		cout << "�ƾǼЪ��O�C��" << endl;
	}
	else {
		cout << "�ƾǼЪ��O����" << endl;
	}
	//----------------------------------------
	if (englishRank < 50) {
		cout << "�^��Ъ��O����" << endl;
	}
	else if (englishRank < 100) {
		cout << "�^��Ъ��O����" << endl;
	}
	else if (english > englishAvg) {
		cout << "�^��Ъ��O����" << endl;
	}
	else if (englishRank < 150) {
		cout << "�^��Ъ��O�C��" << endl;
	}
	else {
		cout << "�^��Ъ��O����" << endl;
	}

	/*cout << "mathSHEET" << endl;
	int R = 0;
	for (int i : mathSheet) {
		cout << R << ":" << i << endl;
		R++;

	}
	cout << "englishSHEET" << endl;
	R = 0;
	for (int i : englishSheet) {
		cout << R << ":" << i << endl;
		R++;
	}*/
}

double f(double x) {
	return (pow(x, 3) - (2.9*pow(x, 2)) - (100 * x) + 290);
}
double df(double x) {
	return ((3 * pow(x, 2)) - (3.8*x) - 100);
}
void WillyHw3::fun3() {
	cout << "�@�~ 3 �{�� 3 �A���g�ɶ�80min" << endl;
	double x = 0;
	double ini_val = 0.0, err = 0.0;
	cout << "�ХX�J�q�ȻP�~�t" << endl;
	cin >> ini_val >> err;
	cout << "�q��=" << ini_val << " �~�t��=" << err;
	x = ini_val;
	int i = 0;
	double d = (f(x) / df(x));
	while (fabs(d) >= err) {
		i++;
		d = (f(x) / df(x));
		x = x - d;
		//cout << x << endl;
		if (i > 10000) {
			cout << "After10000 iteration, the solution is updated to" << x << ", f(x) is " << f(x) << endl;
			break;
		}
	}
	cout << "  ======>" << x;
}

void WillyHw3::fun4() {
	cout << "�@�~ 3 �{�� 4 �A���g�ɶ�30min" << endl;
	int n = 0;
	int *a;
	cout << "�п�J�}�C���� : ";
	do {
		cin >> n;
		if (n <= 100)cout << "��J��ƿ��~�A�Э��s��J";
	} while (n <= 100);
	a = new int[n];
	random_device rd;
	default_random_engine gen = default_random_engine(rd());
	uniform_int_distribution<int> uni(-100, 100);
	auto randfun = bind(uni, gen);
	for (int i = 0; i < n;i++) {
		*(a + i) = randfun();
	}
	sort(a, a + n);
	for (int i = 0, lastNum = 0, times = 0; i < n; i++) {
		if (i == 0) {
			lastNum = *(a);
		}
		else if (lastNum == *(a + i)) {
			times++;
		}
		else {
			cout << lastNum << "����" << times << "��" << endl;
			lastNum = *(a + i);
			times = 1;
		}
	}
	/*for (int i = 0; i < n; i++)
		cout << *(a + i) << endl;*/
}

void WillyHw3::selector(int num) {
	cout << "�п��1~4�D" << endl;
	cin >> num;
	switch (num) {
	case 1:
		fun1();
		break;
	case 2:
		fun2();
		break;
	case 3:
		fun3();
		break;
	case 4:
		fun4();
		break;
	default:
		cout << "�D�ؿ�ܿ��~" << endl;
	}
}