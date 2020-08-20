#pragma once

// �����̓N���X����Ȃ��炵��

class Vector2
{
public:
	Vector2();
	Vector2(int x, int y);
	~Vector2();
	
	int x;
	int y;
	// int* z; �|�C���^�[�ϐ�
	// int& p; �Q�ƕϐ�

	// ������Z�q
	Vector2& operator = (const Vector2& vec);

	// �Y�������Z�q
	int& operator[](int no);

	// �P�����Z�q
	Vector2& operator += (const Vector2& vec);
	Vector2& operator -= (const Vector2& vec);

	Vector2& operator *= (int k);
	Vector2& operator /= (int k);

	Vector2 operator + ()const;
	Vector2 operator - ()const;

	Vector2 operator += (int k);

	// ��r���Z�q
	bool operator == (const Vector2& vec) const;
	bool operator != (const Vector2& vec) const;
	bool operator <= (const Vector2& vec) const;
	bool operator >= (const Vector2& vec) const;

	
private:


};


//__________________________________________


// Vector2 + int;
Vector2 operator+(const Vector2& u, int v);

// Vector2 - int;
Vector2 operator-(const Vector2& u, int v);

// Vector2 * int;
Vector2 operator*(const Vector2& u, int v);

// int * Vector2;
Vector2 operator*(int v,const Vector2& u);

// Vector2 / int;
Vector2 operator/(const Vector2& u, int v);

// Vector2 % int;
Vector2 operator%(const Vector2& u, int v);


// Vector2 + Vector2;
Vector2 operator+(const Vector2& u, const Vector2& v);

// Vector2 - Vector2;
Vector2 operator-(const Vector2& u, const Vector2& v);
