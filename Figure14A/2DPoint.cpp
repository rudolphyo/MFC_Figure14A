#include "stdafx.h"
#include "2DPoint.h"

CMy2DPoint::CMy2DPoint(void) : m_x(0), m_y(0){/* std::cout << "Point was created!" << std::endl; */ }

CMy2DPoint::CMy2DPoint(double x, double y) : m_x(x), m_y(y){}

CMy2DPoint::CMy2DPoint(const CMy2DPoint &p) : m_x(p.m_x), m_y(p.m_y){}


CMy2DPoint::~CMy2DPoint(void)
{
	//std::cout << "Point was destructed!" << std::endl;
}

CMy2DPoint CMy2DPoint::operator +(const CMy2DPoint& rp) {
	return CMy2DPoint((*this).m_x + rp.m_x, (*this).m_y + rp.m_y);
}

CMy2DPoint CMy2DPoint::operator +=(const CMy2DPoint& rp) { /* Overriding += operator for Move function */
	m_x += rp.m_x;
	m_y += rp.m_y;
	return *this;
}

CMy2DPoint CMy2DPoint::operator -(const CMy2DPoint& rp) {
	return CMy2DPoint((*this).m_x - rp.m_x, (*this).m_y - rp.m_y);
}

CMy2DPoint CMy2DPoint::operator *(double k) {
	return CMy2DPoint(m_x * k, m_y*k);
}

double CMy2DPoint::operator *(const CMy2DPoint& rp) {
	return ((*this).m_x * rp.m_x + (*this).m_y * rp.m_y);
}

CMy2DPoint CMy2DPoint::operator /(double k) {
	assert(k == 0);
	if (k != 0) return (*this).operator*(1 / k);
}

CMy2DPoint CMy2DPoint::operator =(const CMy2DPoint &rp){
	if (this == &rp) return *this; /* It is important to check self-assignment */
	m_x = rp.m_x;
	m_y = rp.m_y;
	return *this;
}

CMy2DPoint operator*(double k, const CMy2DPoint& rp) {
	return CMy2DPoint(k * rp.m_x, k * rp.m_y);
}

bool CMy2DPoint::operator==(const CMy2DPoint& rp) {
	return (abs(rp.m_x - m_x) < eps && abs(rp.m_y - m_y) < eps);
}

bool CMy2DPoint::operator!=(const CMy2DPoint& rp) {
	return(!operator == (rp));
}

std::ostream& operator<<(std::ostream& os, const CMy2DPoint& p) {
	os << "{" << p.m_x << ", " << p.m_y << "} ";
	return os;
}

std::istream& operator>>(std::istream& is, CMy2DPoint& p) {
	is >> p.m_x >> p.m_y;
	return is;
}
