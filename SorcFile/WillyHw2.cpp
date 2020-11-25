#include "WillyHw2.h"
using namespace std;

WillyHw2::WillyHw2() {

}

void WillyHw2::fun1() {
	cout << "作業 2 程式 1 ，撰寫時間90min" << endl;
	int M = 0, N = 0, X = 0, sum = 0, L = 0;
	cout << "一顆糖M 元，N 顆果紙可以換一顆糖，小明帶X 元最多可買多少\n M  N  X" << endl;
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
	cout << "作業 2 程式 2 ，撰寫時間240min" << endl;
	int matA[4][4] = { 0 }, matB[4][4] = { 0 };
	int matC[4][4] = { 0 };
	int sum = 0;
	cout << "請輸入 matA:" << endl;
	for (int i = 0;i < 4;i++)
		for (int p = 0; p < 4;p++)
			cin >> matA[i][p];
	cout << "請輸入 matB:" << endl;
	for (int i = 0;i < 4;i++)
		for (int p = 0; p < 4;p++)
			cin >> matB[i][p];
	cout << "答案:" << endl;
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
	cout << "作業 2 程式 3 ，撰寫時間300min" << endl;
	cout << "fun3" << endl;
	struct info
	{
		string sunbject = "none";
		int score = 0;
		int Weighted = 1;
	};
	vector<info> student;

	vector<info> EXstudent = {
{"普通物理實驗（二）", 80, 1},
{"微積分（二）", 45, 3},
{"體育（二）", 89, 0},
{"應用力學（二）", 60, 3},
{"投資規劃與生活", 82, 2},
{"工場實習（二）", 85, 1},
{"跨領域合作專題研究（二）", 92, 2},
{"傳播科技與社會", 67, 2},
{"生涯知能", 88, 2},
{"巨量資料分析與應用", 81, 2},
{"工程圖學（二）", 86, 1},
{"中文閱讀與生命書寫（二）", 84, 2},
{"普通物理（二）", 38, 3},
{"體育（一）", 84, 0},
{"普通物理實驗（一）", 75, 1},
{"中文閱讀與生命書寫（一）", 88, 2},
{"中正講座－向典範學習（十五）", 86, 2},
{"工程圖學（一）", 78, 1},
{"工場實習（一）", 95, 1},
{"程式語言", 87, 3},
{"微積分（一）", 52, 3},
{"性相關議題的探討與思辨", 91, 2},
{"意識哲學與科學", 92, 2},
{"應用力學（一）", 55, 2},
	};
	char x = 0, finish = 1;
	double sum = 0, sumi = 0;

	cout << "輸入指令與引數" << endl
		<< "指令 引數1 引數2" << endl
		<< "N name score weight <- 新增資料" << endl
		<< "L <- 列出現有資料並結束程式" << endl
		<< "E <- 列出範例資訊並結束程式(就是我的成績啦哈哈)" << endl;
	cin >> x;
	do {
		info a;
		switch (x) {
		case 'N':
			cin >> a.sunbject >> a.score >> a.Weighted;
			student.push_back(a);
			break;
		case 'L':
			cout << setw(30) << "科目:\t" << "分數:\t" << "加權:" << endl;
			for (auto i : student) {
				cout << setw(30) << i.sunbject << "\t" << i.score << "\t" << i.Weighted << endl;
				sum += i.score*i.Weighted;
			}
			cout << "平均: " << (sum / student.size()) << endl;
			finish = 0;
			break;
		case 'E':
			cout << setw(30) << "科目:\t" << "分數:\t" << "加權:" << endl;
			for (auto i : EXstudent) {
				cout << setw(30) << i.sunbject << "\t" << i.score << "\t" << i.Weighted << endl;
				sum += i.score*i.Weighted;
				sumi += i.Weighted;
			}
			cout << "平均: ";
			printf("%.2f\n", (sum / sumi));
			finish = 0;
			break;
		default:
			finish = 0;
		}

		if (finish) {
			cout << "-------------------\n"
				<< "輸入指令與引數" << endl
				<< "指令 引數1 引數2" << endl
				<< "N name score weight <- 新增資料" << endl
				<< "L <- 列出現有資料並結束程式" << endl
				<< "LEX <- 列出範例資訊並結束程式(就是我的成績啦哈哈)" << endl;
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
	cout << "輸入 r N:" << endl;
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
	cout << "請選擇1~5題" << endl;
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
		cout << "題目選擇錯誤" << endl;
	}
}