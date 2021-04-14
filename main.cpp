#include "Vector.cpp"
#include <iostream>

int main()
{
	Vector<int> v1;
	v1.add(1);
	v1.add(2);
	v1.add(3);

	Vector<int> v2;
	v2.add(10);
	v2.add(20);
	v2.add(30);

	Vector<int> v3(v1);

	print(v1);
	print(v3*=(5));
	print(v2 / 2);
	print(v1 + v2);
	std::cout << (v2 % v1) << std::endl;

	

	return 0;
}
