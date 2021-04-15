#pragma once
#include <iostream>
#include <cmath>

template <typename T>
class Vector
{
private:
    T* buffer;
    size_t size;
    size_t capacity;

public:
    Vector();
    Vector(const Vector<T>&); 
    Vector<T>& operator=(const Vector<T>&);
    ~Vector();

    void add(const T&);
    void add(const T&, size_t);
    void copy(const Vector<T>&);
    void clear();
    void resize();

    T getItem(size_t) const;
    void setItem(size_t, const T&);

    bool operator==(const Vector<T>&);

    T& operator[](size_t);
    const T operator[](size_t) const;

    //collinear vectors
    bool operator||(const Vector<T>& );

    //Sum vectors 
    Vector<T>& operator+=(const Vector<T>& );
    Vector<T> operator+(const Vector<T>&) const;

    //diff between vectors
    Vector<T>& operator-=(const Vector<T>&);
    Vector<T> operator-(const Vector<T>&) const;

    //Multiply vector with scalar
    Vector<T>& operator*=(const T );
    Vector<T> operator*(const T ) const;

    //Dividing vector with scalar
    Vector<T>& operator/=(const T);
    Vector<T> operator/(const T) const;

    //Scalar multuply operator
    T operator%(const Vector<T>&)const;


    size_t get_size() const {
        return this->size;
    };
    size_t get_capacity() const {
        return this->capacity;
    }


    template <typename T>
    friend std::ostream& operator<<(std::ostream&, const Vector<T>&); 
};

template <typename T>
void print(const Vector<T>&);
