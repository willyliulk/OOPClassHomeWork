#include "WillyHw2.h"
using namespace std;

WillyHw2::WillyHw2() {

}

void WillyHw2::fun1() {
	cout << "�@�~ 2 �{�� 1 �A���g�ɶ�90min" << endl;
	int M = 0, N = 0, X = 0, sum = 0, L = 0;
	cout << "�@���}M ���AN ���G�ȥi�H���@���}�A�p���aX ���̦h�i�R�h��\n M  N  X" << endl;
	cin >> M >> N >> X;
	sum += X / M;
	do {
		L = X / N;
		X = X % N + L;
		sum += X;
	} while (L >= N);
	cout << sum << endl;
}

void WillyHw2::fun2() {
	cout << "�@�~ 2 �{�� 2 �A���g�ɶ�240min" << endl;
	int matA[4][4] = { 0 }, matB[4][4] = { 0 };
	int matC[4][4] = { 0 };
	int sum = 0;
	cout << "�п�J matA:" << endl;
	for (int i = 0;i < 4;i++)
		for (int p = 0; p < 4;p++)
			cin >> matA[i][p];
	cout << "�п�J matB:" << endl;
	for (int i = 0;i < 4;i++)
		for (int p = 0; p < 4;p++)
			cin >> matB[i][p];
	cout << "����:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int p = 0; p < 4;p++) {
			for (int t = 0; t < 4; t++) {
				sum += matA[i][t] * matB[t][p];
				//cout << matA[i][t] << "x" << matB[t][p];
			}
			matC[i][p] = sum;
			cout << sum << "\t";
			sum = 0;
		}
		cout << endl;
	}
	for (int i = 0;i < 4;i++)
		for (int p = 0; p < 4;p++)
			cout << setw(5) << matC[i][p];
	cout << endl;
}

void WillyHw2::fun3() {
	cout << "�@�~ 2 �{�� 3 �A���g�ɶ�300min" << endl;
	cout << "fun3" << endl;
	struct info
	{
		string sunbject = "none";
		int score = 0;
		int Weighted = 1;
	};
	vector<info> student;

	vector<info> EXstudent = {
{"���q���z����]�G�^", 80, 1},
{"�L�n���]�G�^", 45, 3},
{"��|�]�G�^", 89, 0},
{"���ΤO�ǡ]�G�^", 60, 3},
{"���W���P�ͬ�", 82, 2},
{"�u����ߡ]�G�^", 85, 1},
{"����X�@�M�D��s�]�G�^", 92, 2},
{"�Ǽ���޻P���|", 67, 2},
{"�ͲP����", 88, 2},
{"���q��Ƥ��R�P����", 81, 2},
{"�u�{�Ͼǡ]�G�^", 86, 1},
{"����\Ū�P�ͩR�Ѽg�]�G�^", 84, 2},
{"���q���z�]�G�^", 38, 3},
{"��|�]�@�^", 84, 0},
{"���q���z����]�@�^", 75, 1},
{"����\Ū�P�ͩR�Ѽg�]�@�^", 88, 2},
{"�������y�ЦV��d�ǲߡ]�Q���^", 86, 2},
{"�u�{�Ͼǡ]�@�^", 78, 1},
{"�u����ߡ]�@�^", 95, 1},
{"�{���y��", 87, 3},
{"�L�n���]�@�^", 52, 3},
{"�ʬ���ĳ�D�����Q�P���", 91, 2},
{"�N�ѭ��ǻP���", 92, 2},
{"���ΤO�ǡ]�@�^", 55, 2},
	};
	char x = 0, finish = 1;
	double sum = 0, sumi = 0;

	cout << "��J���O�P�޼�" << endl
		<< "���O �޼�1 �޼�2" << endl
		<< "N name score weight <- �s�W���" << endl
		<< "L <- �C�X�{����ƨõ����{��" << endl
		<< "E <- �C�X�d�Ҹ�T�õ����{��(�N�O�ڪ����Z�ի���)" << endl;
	cin >> x;
	do {
		info a;
		switch (x) {
		case 'N':
			cin >> a.sunbject >> a.score >> a.Weighted;
			student.push_back(a);
			break;
		case 'L':
			cout << setw(30) << "���:\t" << "����:\t" << "�[�v:" << endl;
			for (auto i : student) {
				cout << setw(30) << i.sunbject << "\t" << i.score << "\t" << i.Weighted << endl;
				sum += i.score*i.Weighted;
			}
			cout << "����: " << (sum / student.size()) << endl;
			finish = 0;
			break;
		case 'E':
			cout << setw(30) << "���:\t" << "����:\t" << "�[�v:" << endl;
			for (auto i : EXstudent) {
				cout << setw(30) << i.sunbject << "\t" << i.score << "\t" << i.Weighted << endl;
				sum += i.score*i.Weighted;
				sumi += i.Weighted;
			}
			cout << "����: ";
			printf("%.2f\n", (sum / sumi));
			finish = 0;
			break;
		default:
			finish = 0;
		}

		if (finish) {
			cout << "-------------------\n"
				<< "��J���O�P�޼�" << endl
				<< "���O �޼�1 �޼�2" << endl
				<< "N name score weight <- �s�W���" << endl
				<< "L <- �C�X�{����ƨõ����{��" << endl
				<< "LEX <- �C�X�d�Ҹ�T�õ����{��(�N�O�ڪ����Z�ի���)" << endl;
		}
		else break;
	} while (cin >> x && finish);
}

double f2(double x) {
	if (x < 1) return x;
	else return (x * (2 - x));
}
void WillyHw2::fun4() {
	double dx = 0.001, sum = 0.0, steps = 2.0 / dx;
	//cout << "step:" << steps << endl;
	for (double i = 0; i < steps; i++) {
		sum += (f2(dx*i)*dx);
		//cout << (f(dx*i)*dx) << endl;
	}
	cout << sum << endl;
}

void WillyHw2::fun5() {
	double r = 0.0, CL = 0.0, SL = 0.0, phi = 0.0, side = 0.0;
	int N = 0;
	bool first = 1, second = 1, third = 1;
	cout << "��J r N:" << endl;
	cin >> r >> N;
	CL = 2 * pi * r;
	side = 2 * r * sin(pi / N);
	cout << r << " " << N << endl;
	cout << "side:" << side << endl;
	for (int i = 0; i < N; i++) {
		SL += side;
	}
	phi = CL - SL;
	cout << "CL:  " << CL << endl;
	cout << "SL:  " << SL << endl;
	cout << "phi: " << phi << "\n-----------------" << endl;
	phi = 9999.99;
	for (N = 4; phi > 0.001; N++) {
		SL = 0.0;
		side = 2 * r * sin(pi / N);
		//cout << r << " " << N << endl;
		//cout << "side:" << side << endl;
		for (int i = 0; i < N; i++) {
			SL += side;
		}
		phi = CL - SL;
		if ((phi < (2.0 * r)) && first) {
			cout << "phi < 2r when N:" << N << endl;
			cout << "CL:  " << CL << endl;
			cout << "SL:  " << SL << endl;
			cout << "phi: " << phi << "\n-----------------" << endl;
			first = 0;
		}
		if ((phi < (r)) && second) {
			cout << "phi < 1r when N:" << N << endl;
			cout << "CL:  " << CL << endl;
			cout << "SL:  " << SL << endl;
			cout << "phi: " << phi << "\n-----------------" << endl;
			second = 0;
		}
		if ((phi < (0.1 * r)) && third) {
			cout << "phi < 0.1r when N:" << N << endl;
			cout << "CL:  " << CL << endl;
			cout << "SL:  " << SL << endl;
			cout << "phi: " << phi << "\n-----------------" << endl;
			third = 0;
		}
	}
	cout << "phi < 0.001r when N:" << N << endl;
	cout << "CL:  " << CL << endl;
	cout << "SL:  " << SL << endl;
	cout << "phi: " << phi << "\n-----------------" << endl;
}

void WillyHw2::selector(int num) {
	cout << "�п��1~5�D" << endl;
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
	case 5:
		fun5();
		break;
	default:
		cout << "�D�ؿ�ܿ��~" << endl;
	}
}