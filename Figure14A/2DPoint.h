#pragma once
#include "stdafx.h"
#include <assert.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#define eps 1e-10

class CMy2DPoint
{
public:
	CMy2DPoint(void);
	CMy2DPoint(double x, double y);
	CMy2DPoint(const CMy2DPoint &p);
	~CMy2DPoint(void);

	double m_x;
	double m_y;

	CMy2DPoint operator +(const CMy2DPoint& rp);
	CMy2DPoint operator +=(const CMy2DPoint& rp); /* Overriding += operator for Move function */
	CMy2DPoint operator -(const CMy2DPoint& rp);
	CMy2DPoint operator *(double k);
	CMy2DPoint operator /(double k);
	CMy2DPoint operator =(const CMy2DPoint &rp);

	double operator *(const CMy2DPoint& rp);

	bool operator==(const CMy2DPoint& rp);
	bool operator!=(const CMy2DPoint& rp);

	friend std::ostream& operator<<(std::ostream& os, const CMy2DPoint& p);
	friend std::istream& operator>>(std::istream& is, CMy2DPoint& p);

};

CMy2DPoint operator*(double k, const CMy2DPoint& rp);