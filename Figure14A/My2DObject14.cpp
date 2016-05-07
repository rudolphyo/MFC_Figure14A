#include "stdafx.h"
#include "My2DObject14.h"
#include <algorithm>
#define PI 3,14159265

CMy2DObject14::CMy2DObject14()
{
	//std::cout << "My Figure was created" << std::endl;
	//construtor without parameters
}


/* The initializer list was not used due to its inconvinient length */
CMy2DObject14::CMy2DObject14(double A, double A1, double A2, double A3, double Angle, CMy2DPoint centre) {
	CMy2DObject14::m_A = A;
	CMy2DObject14::m_A1 = A1;
	CMy2DObject14::m_A2 = A2;
	CMy2DObject14::m_A3 = A3;
	CMy2DObject14::m_Angle = Angle;
	CMy2DObject14::m_centre = centre;
	//std::cout << "My Figure with parameters was created" << std::endl;
}

CMy2DObject14::~CMy2DObject14()
{
	//std::cout << "My Figure was destructed" << std::endl;
}

void CMy2DObject14::Draw(CDC &dc){

	dc.MoveTo(m_centre.m_x + m_A / 2, m_centre.m_y - m_A / 2);
	dc.LineTo(m_centre.m_x - m_A / 2 + m_A2, m_centre.m_y - m_A / 2);
	dc.LineTo(m_centre.m_x - m_A / 2 + m_A2, m_centre.m_y - m_A / 2 + m_A2);
	dc.LineTo(m_centre.m_x - m_A / 2, m_centre.m_y - m_A / 2 + m_A2);
	dc.LineTo(m_centre.m_x - m_A / 2, m_centre.m_y + m_A / 2 - m_A3);
	dc.AngleArc(m_centre.m_x - m_A / 2 + m_A3, m_centre.m_y + m_A / 2 - m_A3, m_A3, 180, 90);
	//dc.LineTo(x_c - A / 2, y_c + A / 2); 
	dc.LineTo(m_centre.m_x + m_A / 2, m_centre.m_y + m_A / 2);
0+	dc.LineTo(m_centre.m_x + m_A / 2, m_centre.m_y + m_A1);
	//dc.LineTo(x_c + A / 2, y_c - A / 2); 
	//dc.MoveTo(x_c + A / 2, y_c); 
	dc.AngleArc(m_centre.m_x + m_A / 2, m_centre.m_y, m_A1, -90, -180);
	dc.LineTo(m_centre.m_x + m_A / 2, m_centre.m_y - m_A / 2);

}

void CMy2DObject14::Move(double dX, double dY, double dAngle) {
	m_centre.m_x += dX;
	m_centre.m_y += dY;
	std::cout << "New centre: " << m_centre << std::endl;
	Rotate(dAngle);
}

void CMy2DObject14::Move(const CMy2DPoint &delta, double dAngle) {
	m_centre += delta;
	std::cout << "New centre: " << m_centre << std::endl;
	Rotate(dAngle);
}
void CMy2DObject14::Rotate(double dAngle) {
	CMy2DObject14::m_Angle += dAngle;
	while (CMy2DObject14::m_Angle >= 360){ /* Analogue with trigonometry Unit circle */
		CMy2DObject14::m_Angle -= 360;
	}

	while (CMy2DObject14::m_Angle < 0){
		CMy2DObject14::m_Angle += 360;
	}
	std::cout << "Figure was rotated on: " << dAngle << ". New angle equals to: " << CMy2DObject14::m_Angle << std::endl;
}

/*
Let`s rotate point on minus angle of figure and check
if it belongs to figure with angle. My figure rotate clock-wise that is the main reason why point should be rotated counterclock-wise
*/

bool CMy2DObject14::IsInside(const CMy2DPoint& p) {

	CMy2DPoint RotatedPoint(p.m_x * cos(-m_Angle) - p.m_y * sin(-m_Angle), p.m_x * sin(-m_Angle) + p.m_y * cos(-m_Angle)); // 

	// check whether point is inside square A
	if (m_centre.m_x - m_A / 2 <= RotatedPoint.m_x && m_centre.m_x + m_A / 2 >= RotatedPoint.m_x &&
		m_centre.m_y - m_A / 2 <= RotatedPoint.m_y && m_centre.m_y + m_A / 2 >= RotatedPoint.m_y) {

		// check whether point is outside circle with radius A1
		if (pow(RotatedPoint.m_x - (m_centre.m_x + m_A / 2), 2) + pow(RotatedPoint.m_y - m_centre.m_y, 2) >= pow(m_A1, 2)) {

			// check whether point is outside square A2(left top corner)
			if (!((RotatedPoint.m_x <= m_centre.m_x - (m_A / 2) + m_A2) &&
				(m_centre.m_x - (m_A / 2) <= RotatedPoint.m_x) &&
				(RotatedPoint.m_y >= m_centre.m_y - (m_A / 2)) &&
				(m_centre.m_y - (m_A / 2) + m_A2 >= RotatedPoint.m_y))){

				// check whether point is inside circle A3
				if ((m_centre.m_x - (m_A / 2) <= RotatedPoint.m_x) && (RotatedPoint.m_x <= m_centre.m_x - (m_A / 2) + m_A3) &&
					 (m_centre.m_y + (m_A / 2) >= RotatedPoint.m_y ) && (RotatedPoint.m_y >= m_centre.m_y + (m_A / 2) - m_A3) &&
					 (pow(RotatedPoint.m_x - (m_centre.m_x - (m_A / 2) + m_A3), 2) + pow(RotatedPoint.m_y - (m_centre.m_y + (m_A / 2) - m_A3), 2) >= pow(m_A3, 2))) { 
					std::cout << "Point " << p << "doesn`t belong to my figure" << std::endl;
					return false;
				}
				else {
					std::cout << "Point " << p << "belongs to my figure" << std::endl;
					return true;
				}
			}
		}
	}

	std::cout << "Point " << p << "doesn`t belong to my figure" << std::endl;
	return false;
}

bool CMy2DObject14::IsInside(double x, double y) {
	CMy2DPoint point(x, y);
	return IsInside(point); /* New CMy2Dpoint object point was created and IsInside(const CMy2DPoint&) used */
}

/*  Set methods. Border checks in set functions are based on common sense.
Our figure 14A shouldn`t be transformed inappropriately.
Figures A1, A2, A3 shouldn`t "take" more than half of square A
*/
void CMy2DObject14::SetA(double size_A) {
	if (size_A / 2 < m_A1 || size_A < (m_A3 + m_A1) || size_A < m_A2 + m_A1 || size_A < m_A2 + m_A3 || size_A <= 0) {
		std::cout << "New side of square A is not valid.\n" << "Value of A wasn`t changed and equals to: " << m_A << std::endl;
	}
	else {
		m_A = size_A;
		std::cout << "New sise of square A equals to: " << m_A << std::endl;
	}
}

void CMy2DObject14::SetA1(double size_A1) {
	if (size_A1 <= 0 || size_A1 > m_A / 2 || m_A < m_A1 + m_A2) {
		std::cout << "Diameter of A1 shouldn`t be greater or equal to side of square A.\n"
			<< "Radius of A1 wasn`t changed and equals to: " << m_A1 << std::endl;
	}
	else {
		m_A1 = size_A1;
		std::cout << "New radius of A1 equals to: " << m_A1 << std::endl;
	}
}

void CMy2DObject14::SetA2(double size_A2) {
	if (size_A2 <= 0 || m_A < m_A1 + m_A2 || m_A < m_A3 + m_A2) {
		std::cout << "Side of square A2 should be positeve and less than side of square A.\n"
			<< "Side of A2 wasn`t changed and equals to: " << m_A2 << std::endl;
	}
	else {
		m_A2 = size_A2;
		std::cout << "New side of square A2 equals to: " << m_A2 << std::endl;
	}
}

void CMy2DObject14::SetA3(double size_A3) {
	if (size_A3 <= 0 || size_A3 + m_A2 > m_A) {
		std::cout << "Radius of A3 should be positeve and less or equal to side of square A2.\n"
			<< "Value of A3 wasn`t changed and equals to: " << m_A3 << std::endl;
	}
	else {
		m_A3 = size_A3;
		std::cout << "New radius of A3 equals to: " << m_A3 << std::endl;
	}
}

void CMy2DObject14::SetAngle(double newAngle) {
	m_Angle = 0;
	Rotate(newAngle);
}

void CMy2DObject14::SetCentre(CMy2DPoint &newCentre) {
	CMy2DObject14::m_centre.m_x = newCentre.m_x;
	CMy2DObject14::m_centre.m_y = newCentre.m_y;
	std::cout << "New centre of a figure: " << newCentre << std::endl;
}

/*Get methods*/
double CMy2DObject14::GetA() const {
	return CMy2DObject14::m_A;
}

double CMy2DObject14::GetA1() const {
	return CMy2DObject14::m_A1;
}

double CMy2DObject14::GetA2() const {
	return CMy2DObject14::m_A2;
}

double CMy2DObject14::GetA3() const {
	return CMy2DObject14::m_A3;
}

double CMy2DObject14::GetAngle() const {
	return CMy2DObject14::m_Angle;
}

CMy2DPoint CMy2DObject14::GetCentre() const {
	return CMy2DObject14::m_centre;
}
