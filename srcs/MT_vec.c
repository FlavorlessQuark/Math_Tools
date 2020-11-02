#include "MT.h"

static double _convert_180(double angle)
{
	if (angle < 0)
		angle = (angle * -1) + 180;
	return angle;
}

/*Returns a vector */
MT_Vector2 MT_V2FromAngle_Deg(double angle, double magnitude)
{
	MT_Vector2 vec;

	vec.x = cos(to_radf(angle)) * magnitude;
	vec.y = sin(to_radf(angle)) * magnitude;

	return vec;
}

MT_Vector2 MT_V2FromAngle_Rad(double angle, double magnitude)
{
	MT_Vector2 vec;

	vec.x = cos(angle) * magnitude;
	vec.y = sin(angle) * magnitude;

	return vec;
}

/*Returns a vector that is the result og basic math operations*/
MT_Vector2 MT_V2Sub(MT_Vector2 a, MT_Vector2 b)
{
	MT_Vector2 vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;

	return vec;
}

MT_Vector2 MT_V2Add(MT_Vector2 a, MT_Vector2 b)
{
	MT_Vector2 vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;

	return vec;
}

MT_Vector2 MT_V2Mult(MT_Vector2 vec,int scalar)
{
	MT_Vector2 new_vec;

	new_vec.x = vec.x * scalar;
	new_vec.y = vec.y * scalar;

	return new_vec;
}

double MT_V2Dot(MT_Vector2 a, MT_Vector2 b, double angle)
{
	double mag_a, mag_b, result;

	mag_a = sqrt(vec_magnitude(a));
	mag_b = sqrt(vec_magnitude(b));
	result = mag_a * mag_b;
	return (result * cos(angle));
}

/* Returns the angle between two vectors */
double MT_V2Angle_Rad(MT_Vector2 a, MT_Vector2 b)
{
	double angle, m_a, m_b;

	m_a = sqrt(vec_magnitude(a));
	m_b = sqrt(vec_magnitude(b));
	angle = (a.x * a.y) + (b.x * b.y);
	angle /= (m_a * m_b);

	return acos(angle);
}

double MT_V2Angle_Deg(MT_Vector2 a, MT_Vector2 b)
{
	return (MT_ToDegf(MT_V2Angle_Rad(a, b)));
}

/*Returns a Vector that is the result of a rotation by the given angle (in degrees or radians)*/
MT_Vector2 MT_V2Rot_Deg(MT_Vector2 vec, double rot_angle)
{
	MT_Vector2 new_vec;
	double current_angle;

	current_angle = vec_heading360_deg(vec);
	current_angle += rot_angle;
	while (current_angle > 360)
		current_angle -= 360;
	while (current_angle < 0)
		current_angle += 360;

	return MT_V2FromAngle_Deg(current_angle, vec_magnitude(vec));
}

MT_Vector2 vec_rot_rad(MT_Vector2 vec, double rot_angle){
	return MT_V2Rot_Deg(vec, MT_ToDegf(rot_angle));
}

/*Returns a vector that is opposite to the one given*/
MT_Vector2 MT_V2Invert(MT_Vector2 vec)
{
	MT_Vector2 new_vec;

	new_vec.x = vec.x * -1;
	new_vec.y =	vec.y * -1;
	return new_vec;
}

/*Returns the square of the magnitude of a vector*/
double MT_V2Mag(MT_Vector2 vec)
{
	return (MT_GetDistancef(0, vec.x, 0, vec.y));
}

/*Returns the angle of a vector relative to the x axis */
double  MT_V2Heading180_Deg(MT_Vector2 vec){ return MT_ToDegf(atan2(vec.y, vec.x));}
double  MT_V2Heading180_Rad(MT_Vector2 vec){ return atan2(vec.y, vec.x); }


double  MT_V2Heading360_Deg(MT_Vector2 vec)
{
	double angle;

	angle = MT_ToDegf(atan2(vec.y, vec.x));

	return _convert_180(angle);
}

double  MT_V2Heading360_Rad(MT_Vector2 vec)
{
	return MT_ToRadf(MT_V2Heading180_Deg(vec));
}