#include<iostream>

class Vector3D
{
private:
	double x;
	double y;
	double z;


public:
	Vector3D();


	/**
	* Създава вектор със стойности 0
	*/

	/**
	* Създава вектор по зададените стойности за компонентите x, y и z, където
	* x, y и z са зададени спрямо правоъгълна координатна система
	* @param x
	* @param y
	* @param z
	*/
	Vector3D(double x, double y, double z);
	~Vector3D();

	Vector3D& operator=(const Vector3D &other);

	/**
	* Връща стойността за x
	* @return x
	*/
	double getX() const;
	/**
	* Връща стойността за y
	* @return y
	*/
	double getY() const;
	/**
	* Връща стойността за z
	* @return z
	*/
	double getZ() const;
	/**
	* Предоставя възможност за събиране на вектори
	* @param secondVector вектор
	* @return Нов вектор
	*/
	Vector3D operator+(const Vector3D & secondVector) const;
	/**
	* Предоставя възможност за изваждане на вектори
	* @param secondVector вектор
	* @return Нов вектор
	*/
	Vector3D operator-(const Vector3D & secondVector) const;
	/**
	* Връща нов вектор с променен знак
	* @return Нов вектор с променен знак
	*/
	Vector3D operator-() const;
	/**

	* Умножава векторът с числото number
	* @param number - число с което се умножава векторът
	* @return Нов вектор
	*/
	Vector3D operator*(double number) const;
	/**
	* Умножава число с вектор
	* @param number - число
	* @param vector - вектор
	* @return Нов вектор
	*/
	friend Vector3D operator*(double number, const Vector3D & vector);
	/**
	* Предоставя възможност за въвеждане на данни за вектор от стандартния вход, като
	трябва
	* да бъде спазен следния формат:
	* (x, y, z)
	*/
	friend std::istream & operator >> (std::istream & iStream, Vector3D & vector);
	/**
	* Предоставя възможност за визуализиране (извеждане) на стойностите в следния
	формат:
	* (x, y, z)
	*/
	friend std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector);

	void sumVectors(int, Vector3D*);
	void subtractVectors(int, Vector3D*);
	void negateVectors(int, Vector3D*);
	void multiplyVectWithNum (int, Vector3D*, int);
	void multiplyNumWithVect (int, Vector3D*, int);


};
