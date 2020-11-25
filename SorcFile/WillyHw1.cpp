#include "WillyHw1.h"

using namespace std;

WillyHw1::WillyHw1() {

}

void WillyHw1::fun1() {
	cout << "作業 1 程式 1 ，撰寫時間30min" << endl;
	int x = 3, y = 5, z = 7;
	cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
	int ans1 = (int)(pow(x, 2) + 2 * x*y + pow(y, 2));
	cout << "pow(x, 2) + 2 * x*y + pow(y, 2)" << endl;
	cout << "ans = " << ans1 << endl;
	int ans2 = (x + y)*(x + x * y + y);
	cout << "(x + y)*(x + x * y + y)" << endl;
	cout << "ans = " << ans2 << endl;
	bool ans3 = (x > (y + 3 * x*y - 4));
	cout << "(x > (y + 3 * x*y - 4))" << endl;
	cout << "ans = " << ans3 << endl;
	float ans4 = (powf((float)x, (float)3) + 3 * x*y*z*(y + z)) / (float)(x + y);
	cout << "(pow(x, 3) + 3 * x*y*z*(y + z)) / (float)(x + y)" << endl;
	cout << "ans = " << ans4 << endl;
}

void WillyHw1::fun2() {
	cout << "作業 1 程式 2 ，撰寫時間15min" << endl;
	float a = 3, b = 8, c = 2;
	float ans = (-b + sqrt(powf(b, 2) - 4 * a*c)) / (2 * a);
	cout << "ans = " << ans << endl;
}

void WillyHw1::fun3() {
	cout << "作業 1 程式 3 ，撰寫時間100min" << endl;
	float a = 0, b = 0, c = 0, D = 0;
	cout << "請輸入 a,b,c" << endl;
	cin >> a >> b >> c;
	D = powf(b, 2) - 4 * a * c;
	if (D > 0) {
		cout << "有二解" << endl;
		std::cout << "X1=" << (-b + sqrt(D)) / (2 * a) << std::endl;
		std::cout << "X2=" << (-b - sqrt(D)) / (2 * a) << std::endl;
	}
	else if (D == 0) {
		cout << "有重根" << endl;
		std::cout << "X2=" << (-b - sqrt(D)) / (2 * a) << std::endl;
	}
	else {
		cout << "無實解" << endl;
	}
}

void WillyHw1::fun4() {
	cout << "作業 1 程式 4 ，撰寫時間100min" << endl;
	float x = 0;
	int n = 0;
	float ans1 = 0, ans2 = 0, ans3 = 0;
	cout << "請輸入x, n" << endl;
	cin >> x >> n;
	//(a)
	cout << "(a)" << endl;
	for (int i = 0; i <= n; i++) {
		ans1 += powf(-x, (float)i);
	}
	cout << ans1 << endl;
	//(b)
	cout << "(b)" << endl;
	for (int i = 0; i <= n; i++) {
		float fab = 1;
		for (int p = 1; p <= i; p++) fab *= p;
		ans2 += powf(x, (float)i) / fab;
	}
	cout << ans2 << endl;
	//(c)
	cout << "(c)" << endl;
	for (int i = 0; i <= n; i++) {
		float fab = 1;
		for (int p = 1; p <= 2 * i + 1; p++) fab *= p;
		ans3 += (powf(-1.0, (float)i) * powf(x, (float)2 * i + 1)) / fab;
	}
	cout << ans3 << endl;
}

struct carCoor {
	float x = 0;
	float y = 0;
};
void WillyHw1::fun5() {
	cout << "作業 1 程式 5 ，撰寫時間120min" << endl;
	float a = 0, v0 = 0, ti = 0;
	float tMax = 0, tFall = 0;
	carCoor rTi, vTi, rMax, vMax, rFall, vFall;
	cout << "輸入 角度 初速 時間" << endl;
	cin >> a >> v0 >> ti;
	a = (float)(a / 180 * acos(-1));
	rTi.x = (v0 * cos(a))*ti;
	rTi.y = (float)((v0 * sin(a))*ti - 0.5*9.8*ti*ti);
	printf("(a)Ti時座標：\t %f i \t%s\t %f j\n", rTi.x, ((rTi.y > 0) ? "+" : "-"), fabs(rTi.y));
	vTi.x = (v0 * cos(a));
	vTi.y = (float)((v0 * sin(a)) - (9.8*ti));
	printf("   Ti時速度：\t %f i \t%s\t %f j\n", vTi.x, ((vTi.y > 0) ? "+" : "-"), fabs(vTi.y));
	tFall = (float)((2 * v0*sin(a)) / 9.8);
	tMax = (float)(tFall / 2.0);
	rMax.x = (v0 * cos(a))*tMax;
	rMax.y = (float)((v0 * sin(a))*tMax - 0.5*9.8*tMax*tMax);
	printf("(b)最高點時座標：%f i \t%s\t %f j\n", rMax.x, ((rMax.y > 0) ? "+" : "-"), fabs(rMax.y));
	vMax.x = (v0 * cos(a));
	vMax.y = (float)((v0 * sin(a)) - (9.8*tMax));
	printf("   最高點時速度：%f i \t%s\t %f j\n", vMax.x, ((vMax.y > 0) ? "+" : "-"), fabs(vMax.y));
	printf("   最高點時間：\t %f\n", tMax);
	rFall.x = (v0 * cos(a))*tFall;
	rFall.y = (float)((v0 * sin(a))*tFall - 0.5*9.8*tFall*tFall);
	printf("(c)落地時座標：\t %f i \t%s\t %f j\n", rFall.x, ((rFall.y > 0) ? "+" : "-"), fabs(rFall.y));
	vFall.x = (v0 * cos(a));
	vFall.y = (float)((v0 * sin(a)) - (9.8*tFall));
	printf("   落地時速度：\t %f i \t%s\t %f j\n", vFall.x, ((vFall.y > 0) ? "+" : "-"), fabs(vFall.y));
	printf("   落地時間：\t %f\n", tFall);
}

void WillyHw1::selector(int num) {
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