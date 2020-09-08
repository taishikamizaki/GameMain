
#include <iostream>
#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y)
{
	Vector2::x = x;
	Vector2::y = y;
}

Vector2::~Vector2()
{
	
}

Vector2& Vector2::operator=(const Vector2& vec)
{
	this->x = vec.x;
	this->y = vec.y;

	return (*this);
}

int& Vector2::operator[](int no)
{
	if (no == 0)
	{
		return x;
	}
	else if (no == 1)
	{
		return y;
	}
	else
	{
		return x;
	}
}


// ’P€‰‰Zq
Vector2& Vector2::operator += (const Vector2& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return (*this);
}

Vector2& Vector2::operator -= (const Vector2& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;

	return (*this);
}

Vector2& Vector2::operator *= (int k)
{
	this->x *= k;
	this->y *= k;

	return (*this);
}

Vector2& Vector2::operator /= (int k)
{
	this->x /= k;
	this->y /= k;

	return (*this);
}

Vector2 Vector2::operator + () const
{
	return (*this);
}

Vector2 Vector2::operator - () const
{
	return Vector2(-this->x,-this->y);
}

Vector2 Vector2::operator+=(int k)
{
	this->x += k;
	this->y += k;

	return (*this);
}


// ”äŠr‰‰Zq
bool Vector2::operator == (const Vector2& vec) const
{
	return ((this->x == vec.x)&&(this->y == vec.y));
}

bool Vector2::operator != (const Vector2& vec) const
{
	return ((this->x != vec.x) && (this->y != vec.y));
}

bool Vector2::operator <= (const Vector2& vec) const
{
	return ((this->x <= vec.x) && (this->y <= vec.y));
}

bool Vector2::operator >= (const Vector2& vec) const
{
	return ((this->x >= vec.x) && (this->y >= vec.y));
}


// ===ƒNƒ‰ƒXŠO===

// ‰ÁZ
Vector2 operator+(const Vector2& u, int v)
{
	return Vector2(u.x + v, u.y + v);
}

// Œ¸Z
Vector2 operator-(const Vector2& u, int v)
{
	return Vector2(u.x - v, u.y - v);
}

// æZ
Vector2 operator*(const Vector2& u, int v)
{
	return Vector2(u.x * v, u.y * v);
}

// æZ(‹t)
Vector2 operator*(int v, const Vector2& u)
{
	return Vector2(v * u.x , v * u.y);
}

// Š„‚èZ
Vector2 operator/(const Vector2& u, int v)
{
	return Vector2(u.x / v, u.y / v);
}

// “
Vector2 operator%(const Vector2& u, int v)
{
	return Vector2(u.x % v, u.y % v);
}

// ƒxƒNƒgƒ‹“¯m‚Ì‰ÁZ
Vector2 operator+(const Vector2& u, const Vector2& v)
{
	return Vector2(u.x + v.x, u.y + v.y);
}

// ƒxƒNƒgƒ‹“¯m‚ÌŒ¸Z
Vector2 operator-(const Vector2& u, const Vector2& v)
{
	return Vector2(u.x - v.y, u.y - v.y);
}
