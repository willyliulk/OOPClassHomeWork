#include "WillyHw1.h"
#include "WillyHw2.h"
#include "WillyHw3.h"
using namespace std;
int main() {
	int x=0, y=0;
	WillyHw1 HW1;
	WillyHw2 HW2;
	WillyHw3 HW3;
	cout << "�Ѿ���G408420010�B�´Q�s�@" << endl;
	do {
		cout << "�п�J�ĴX���@�~�ο�J99���}�G";
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
			cout << "��J���~�A�ЦA����J�ο�J99���}" << endl;
		}
	} while (x != 99);
	system("pause");
 }