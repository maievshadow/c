#include <iostream>
using namespace std;
class A
{
	public:
		void show();
};

class B:public A
{
	public:
		void show();
};

void A::show()
{
	cout<<"A hello world\n"<<endl;
}

void B::show()
{
	cout<<"B hello world\n"<<endl;
}
int main()
{
	A *a ;
	A a1;
	B b1;

	a = &a1;
	a->show();

	a = &b1;
	a->show();
}
