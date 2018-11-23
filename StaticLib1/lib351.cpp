
#include "stdafx.h"
#include "lib351.h"
#include <iostream>
using namespace std;
int funk()
{
	int a, b, c, d;
	cout << "vvedite a,b,c" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	d = b * b - 4 * a*c;
	cout << "diskriminant =" << d << endl;
	if (d < 0) {
		cout << "korney net" << endl;
		return 0;
	}
	if (d = 0) {
		cout << "tolko odin koren" << endl;
		return 0;
	}
}
int main() {
	
	funk();
	return 0;
}
