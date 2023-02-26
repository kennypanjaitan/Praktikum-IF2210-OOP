#include <iostream>
#include "A.hpp"
using namespace std;

int main()
{
	A *x = new A('1');
	A *y = new A('2');
	A *xy = new A(*x);
	*xy = *y;
	xy->show();
	delete xy;
	delete y;
	delete x;
	return 0;
}