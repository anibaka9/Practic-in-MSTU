#include <iostream>
using namespace std;

class A
{
public:
	A(int b = 0) {x = b; };
	int x;
	A operator+(const A& a) {return A(a.x + x); };	
};

int main(int argc, char const *argv[])
{
	char (*(*x())[])();
    A a;
    cout << 5/2;
    getchar();
	return 0;
}