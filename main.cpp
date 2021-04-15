#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Vector.cpp"
#include <iostream>

TEST_CASE("Testing Add Mthod") {
	Vector<int> v;
	Vector<double> v1;

	v.add(5);
	v.add(6);
	v.add(10,1);

	v1.add(0.5);

	CHECK(v1[0] == 0.5);
	CHECK(v[0] == 5);
	CHECK(v[1] == 10);
	CHECK(v.get_size() == 3);

}

TEST_CASE("Testing copy Mthod") {
	Vector<int> v;
	Vector<int> v1;

	v.add(5);
	v.add(10);

	v1.copy(v);

	CHECK(v1[0] == v[0]);
	CHECK(v1[1] == v[1]);
}

TEST_CASE("Testing clear Mthod") {
	Vector<int> v;
	Vector<int> v1 = Vector<int>();

	v.add(5);
	v.add(10);
	v.clear();

	Vector<int> v2 = Vector<int>();
	v2.add(10);
	v2.add(1);

	bool result = (v == v1);
	bool result1 = (v == v2);

	CHECK(v.get_size() == 0);
	CHECK(result);
	CHECK(!result1);
}

TEST_CASE("Testing resize method") {
	Vector<double> v;

	v.add(1);
	v.add(1);
	
	v.resize();

	CHECK(v.get_capacity() == 16);

}

TEST_CASE("Testing getItem Method") {
	Vector<double> v;
	v.add(0.5);
	v.add(0.6);
	v.add(0.7);

	double elem = v.getItem(1);

	CHECK(elem == v[1]);
}

TEST_CASE("Testing setItem method") {
	Vector<double> v;

	v.setItem(0,5.6);
	v.add(6.5);
	v.setItem(1, 10.55);

	CHECK(v.get_size() == 2);
	CHECK(v[0] == 5.6);
}

TEST_CASE("Test operator== method") {
	Vector<double> v;
	Vector<double> v1;
	Vector<double> v2;


	v.add(1);
	v.add(2);

	v1.add(1);
	v1.add(2);

	v2.add(1);
	v2.add(7);

	bool result = v == v1;
	bool result1 = v2 == v;

	CHECK(result);
	CHECK(!result1);
}

TEST_CASE("Test operator[] method") {
	Vector<double> v;
	v.add(1);
	v.add(2);

	CHECK(v[1] == 2);
}

TEST_CASE("Test operator|| method") {
	Vector<int> v;
	v.add(1.2);
	v.add(2.2);

	Vector<int> v1;
	v1.add(2.2);
	v1.add(3.2);

	bool result = v || v1;

	CHECK(result);
}

TEST_CASE("Test operator+= method") {
	Vector<double> v;
	v.add(1);
	v.add(2);

	Vector<double> v1;
	v1.add(1);
	v1.add(2);

	Vector<double> v2;
	v2.add(2);
	v2.add(4);

	bool result = v2 == (v1 + v);

	CHECK(result);
}

TEST_CASE("Test operator-= method") {
	Vector<double> v;
	v.add(1);
	v.add(2);

	Vector<double> v1;
	v1.add(2);
	v1.add(3);

	Vector<double> v2;
	v2.add(1);
	v2.add(1);

	bool result = v2 == (v1 - v);

	CHECK(result);
}

TEST_CASE("Test operator% method") {
	Vector<int> v;
	v.add(1);
	v.add(2);

	Vector<int> v1;
	v1.add(2);
	v1.add(3);


	bool result = 8 == (v1 % v);

	CHECK(result);
}

TEST_CASE("Test operator* method") {
	Vector<int> v;
	v.add(1);
	v.add(2);

	Vector<int> v1;
	v1.add(10);
	v1.add(20);

	bool result = v1 == (v * 10);

	CHECK(result);
}

TEST_CASE("Test operator/ method") {
	Vector<int> v;
	v.add(1);
	v.add(2);

	Vector<int> v1;
	v1.add(10);
	v1.add(20);

	bool result = v == (v1 / 10);

	CHECK(result);
}

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

	doctest::Context().run();

	return 0;
}
