#ifndef CMy2DObject14_HEADER
#define CMy2DObject14_HEADER
#include "stdafx.h"
#include "2DPoint.h"

class CMy2DObject14
{

protected:

	double m_A, m_A1, m_A2, m_A3, m_Angle;
	CMy2DPoint m_centre;

public:

	CMy2DObject14();
	CMy2DObject14(double, double, double, double, double, CMy2DPoint);
	~CMy2DObject14();

	void Draw(CDC &dc);
	void Move(double dX, double dY, double dAngle = 0);
	void Move(const CMy2DPoint &delta, double dAngle = 0);
	void Rotate(double dAngle);
	bool IsInside(const CMy2DPoint &point);
	bool IsInside(double x, double y);

	void SetA(double size_A);
	void SetA1(double size_A1);
	void SetA2(double size_A2);
	void SetA3(double size_A3);
	void SetAngle(double newAngle);
	void SetCentre(CMy2DPoint &newCentre);
	double GetA() const;
	double GetA1() const;
	double GetA2() const;
	double GetA3() const;
	double GetAngle() const;
	CMy2DPoint GetCentre() const;

};

#endif