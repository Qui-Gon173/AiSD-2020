#include <iostream>
using namespace std;

int main() {
	int a, c, b;
	int  *ca, *cb;
	int *sa, *sb, *sc;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	c = a + b;

	sb = &b;
	sa = &a;
	sc = &c;
	*sc = c + a - b;
	ca = sa;
	cb = sb;
	*sa = 12;

	cout << "\n*ca = " << *ca;
	cout << "\n*sa = " << *sa;
	cout << "\n*cb = " << *cb;
	cout << "\n*sb = " << *sb;
	cout << "\n*sc = " << *sc;

	cout << "\nca = " << ca;
	cout << "\ncb = " << cb;
	cout << "\nsc = " << sc;

	cout << "\na = " << a;
	cout << "\nb = " << b;
	cout << "\nc = " << c;

	cout << "\n&a = " << &a;
	cout << "\n&b = " << &b;
	cout << "\n&c = " << &c;

	cout << "\n*&a = " << *&a;

	cout << "\n*cb-*ca = " << *cb - *ca;
	cout << "\n*cb+*ca = " << *cb + *ca;
	*cb += 2;
	cout << "\ncb = " << cb;
	cb++;
	cout << "\ncb = " << cb;
	ca--; //
	cout << "\nc� = " << ca;
	cout << "\ncb-ca = " << cb - ca;
	system("pause");
	return 0;
}
