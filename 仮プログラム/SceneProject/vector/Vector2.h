#pragma once

// こいつはクラスじゃないらしい

class Vector2
{
public:
	Vector2();
	Vector2(int x, int y);
	~Vector2();
	
	int x;
	int y;
	// int* z; ポインター変数
	// int& p; 参照変数

	// 代入演算子
	Vector2& operator = (const Vector2& vec);

	// 添え字演算子
	int& operator[](int no);

	// 単項演算子
	Vector2& operator += (const Vector2& vec);
	Vector2& operator -= (const Vector2& vec);

	Vector2& operator *= (int k);
	Vector2& operator /= (int k);

	Vector2 operator + ()const;
	Vector2 operator - ()const;

	Vector2 operator += (int k);

	// 比較演算子
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
