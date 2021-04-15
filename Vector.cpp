#include "Vector.h"

template <typename T>
Vector<T>::Vector() : buffer(nullptr), size(0), capacity(8) {}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copy(other);
}

template <typename T>
Vector<T>::~Vector()
{
	clear();
}


template <typename T>
void Vector<T>::add(const T& elem)
{
	if (size == capacity)
	{
		T* temp = new T[capacity * 2];

		for (size_t i = 0; i < capacity; i++)
		{
			temp[i] = buffer[i];
		}

		for (size_t i = capacity; i < capacity * 2; i++)
		{
			temp[i] = 0;
		}

		this->capacity *= 2;
		delete[] this->buffer;
		this->buffer = temp;

		this->buffer[this->size++] = elem;
	}

	if (this->buffer == nullptr)
	{
		this->buffer = new T[capacity];
	}

	this->buffer[this->size++] = elem;

}

template <typename T>
void Vector<T>::add(const T& elem, size_t pos) {
	if (pos == this->get_capacity())
	{
		add(elem);
	}
	else {
		this->buffer[pos] = elem;
		this->size++;
	}
}

template<typename T>
void Vector<T>::copy(const Vector<T>& entity)
{
	this->size = entity.size;
	this->capacity = entity.capacity;
	this->buffer = new T[entity.size];
	for (size_t i = 0; i < entity.size; i++)
	{
		buffer[i] = entity.buffer[i];
	}
}

template<typename T>
void Vector<T>::clear()
{
	if (!buffer) {
		return;
	}

	delete[] buffer;
	buffer = nullptr;
	size = 0;
	capacity = 8;
}

template<typename T>
void Vector<T>::resize()
{
	size_t new_capacity = 8;

	if (!buffer)
	{
		this->buffer = new T[new_capacity];
		for (size_t i = 0; i < new_capacity; i++)
		{
			this->buffer[i] = 0;
		}

		this->capacity = new_capacity;
		return;
	}

	/*if (new_capacity < capacity)
	{
		std::cout << "Invalid index input!" << std::endl;
		return;
	}*/

	T* temp = new T[new_capacity*2+1];
	for (size_t i = 0; i < capacity; i++)
	{
		temp[i] = this->buffer[i];
	}

	for (size_t i = capacity; i < new_capacity; i++)
	{
		temp[i] = 0;
	}

	delete[] buffer;
	buffer = temp;

	this->capacity = new_capacity * 2;
}

template <typename T>
T Vector<T>::getItem(size_t i) const
{
	if (i < size)
	{
		return buffer[i];
	}

	std::cout << "Invalid index!";
	return 0;
}

template <typename T>
void Vector<T>::setItem(size_t i, const T& x)
{
	if (i == 0)
	{
		add(x);
		return;
	}

	if (i < size)
	{
		buffer[i] = x;
		//size++;
		return;
	}
	std::cout << "Invalid index!";
}

template<typename T>
bool Vector<T>::operator==(const Vector<T>& entity) {
	if (size != entity.size)
	{
		return false;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (buffer[i] != entity.buffer[i])
		{
			return false;
		}
	}

	return true;
}


template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{

	if (this != &other)
	{
		delete[]buffer;

		copy(other);
	}

	return *this;
}

template<typename T>
bool Vector<T>::operator||(const Vector<T>& other) {
	if (this->size != other.size) {
		return false;
	}

	T coeff = this->buffer[0] / other.buffer[0];
	const double eps = 0.00000001;

	for (int i = 1; i < this->size; ++i) {
		double current = this->buffer[i] / other.buffer[i];
		if (abs(coeff - current) > 0) {
			return false;
		}
	}
	return true;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other) {
	
	for (int i = 0; i < other.size; ++i) {
		this->buffer[i] += other.buffer[i];
	}

	return *this;

}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
	Vector<T> vector(*this);
	vector += other;
	return vector;
}

template<typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& other) {
	
	for (int i = 0; i < other.size; ++i) {
		this->buffer[i] -= other.buffer[i];
	}
	return *this;

}

template<typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const {
	Vector<T> vector(*this);
	vector -= other;
	return vector;
}


template<typename T>
Vector<T>& Vector<T>::operator*=(const T scalar) {
	for (size_t i = 0; i < size; i++)
	{
		this->buffer[i] *= scalar;
	}

	return *this;
}

template<typename T>
Vector<T> Vector<T>::operator*(const T scalar) const {
	Vector<T> vector(*this);
	vector *= scalar;
	return vector;
}

template<typename T>
Vector<T>& Vector<T>::operator/=(const T scalar) {
	if (scalar == 0) {
		std::cout << "Invalid operation!\n";
		return *this;
	}

	for (int i = 0; i < size; ++i) {
		buffer[i] /= scalar;
	}
	return *this;
}

template<typename T>
Vector<T> Vector<T>::operator/(const T scalar) const {
	Vector<T> vector(*this);
	vector /= scalar;
	return vector;
}

template<typename T>
T Vector<T>::operator%(const Vector<T>& other)const {
	if (size != other.size)
	{
		std::cout << "Invalid operation!";
		return 0;
	}

	T product = 0;
	for (int i = 0; i < size; ++i) {
		product += this->buffer[i] * other.buffer[i];
	}
	return product;
}


template <typename T>
T& Vector<T>::operator[](size_t i)
{
	if (i < size) {
		return buffer[i];
	}

	std::cout << "Invalid index!";
	T elem = 0;
	return elem;
}

template <typename T>
const T Vector<T>::operator[](size_t i) const
{
	if (i < size) {
		return buffer[i];
	}

	std::cout << "Invalid index!";
	T elem = 0;
	return elem;
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v)
{

	out << v.capacity << std::endl;
	out << v.size << std::endl;
	out << "(";
	for (size_t i = 0; i < v.size; ++i)
	{
		out << v.buffer[i] << " ";
	}
	out << ")";
	return out;
}


template<typename T>
void print(const Vector<T>& v) {
	std::cout << v;
	std::cout << std::endl;

}
