#include "WillyHw1.h"
#include "WillyHw2.h"
#include "WillyHw3.h"
using namespace std;
int main() {
	int x=0, y=0;
	WillyHw1 HW1;
	WillyHw2 HW2;
	WillyHw3 HW3;
	cout << "由機械二408420010劉朝崴製作" << endl;
	do {
		cout << "請輸入第幾份作業或輸入99離開：";
		cin >> x;
		switch (x) {
		case 1:
			HW1.selector(y);
			break;
		case 2:
			HW2.selector(y);
			break;
		case 3:	
			HW3.selector(y);
			break;
		case 99:
			break;
		default:
			cout << "輸入錯誤，請再次輸入或輸入99離開" << endl;
		}
	} while (x != 99);
	system("pause");
 }