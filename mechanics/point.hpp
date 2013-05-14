#pragma once
#include "../math/vector.hpp"

template<class T, unsigned int n>
class Point
{
private:
	Vector<T,n> m_vPosition;
public:
	Point();
	Point(Vector<T,n> pos);
	Point(T, ...);
	~Point(void);

	Vector<T,n> position();
	void setPosition(Vector<T,n>);
};

/////////////////////////////////////////////
// Constructors
////////////////////////////////////////////

template<class T, unsigned int n>
Point<T,n>::Point()
{
}

template<class T, unsigned int n>
Point<T,n>::Point(Vector<T,n> pos) : m_vPosition(pos)
{
}

template<class T, unsigned int n>
Point<T,n>::Point(T x, ...)
{
	auto x0 = x;
	m_vPosition.coeff(x0,0);
	va_list args;
	va_start(args, x);
		for(int i=1; i<n; i++)	
			m_vPosition.coeff(va_arg(args, T),i);
	va_end(args);
}

template<class T, unsigned int n>
Point<T,n>::~Point()
{
}

///////////////////////////////////////////////
// Accessors
//////////////////////////////////////////////

template<class T, unsigned int n>
Vector<T,n> Point<T,n>::position()
{
	return m_vPosition;
}

template<class T, unsigned int n>
void Point<T,n>::setPosition(Vector<T,n> v)
{
	m_vPosition = v;
}

/////////////////////////////////////////////
// Typedefs
////////////////////////////////////////////

typedef Point<double,2> Point2d;
typedef Point<double,3> Point3d;