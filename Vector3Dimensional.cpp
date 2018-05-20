#include "Vector3D.h"
#include<iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int maxLength = 5;

Vector3D::Vector3D()
{
    x=0;
    y=0;
    z=0;
}

Vector3D::Vector3D(double x, double y, double z): x(x), y(y), z(z)
{
}

Vector3D::~Vector3D()
{
}


Vector3D& Vector3D::operator=(const Vector3D &other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}
	return *this;
}

double Vector3D::getX() const
{
	return x;
}

double Vector3D::getY() const
{
	return y;
}

double Vector3D::getZ() const
{
	return z;
}

Vector3D Vector3D::operator+(const Vector3D & secondVector) const
{
	Vector3D aVector;

	aVector.x = x + secondVector.x;
	aVector.y = y + secondVector.y;
	aVector.z = z + secondVector.z;

	return aVector;
}

Vector3D Vector3D::operator-(const Vector3D & secondVector) const
{
	Vector3D aVector;

	aVector.x = x -secondVector.x;
    aVector.y = y - secondVector.y;
	aVector.z = z-secondVector.z;


	return aVector;
}

Vector3D Vector3D::operator-() const
{
	Vector3D aVector;

	aVector.x = -x;
	aVector.y = -y;
	aVector.z = -z;

	return aVector;
}

Vector3D Vector3D::operator*(double number) const
{
	Vector3D aVector;

	aVector.x = number * x;
	aVector.y = number * y;
	aVector.z = number * z;

	return aVector;
}


void sumVectors(int numVect, Vector3D* workVec)
{
    Vector3D result=workVec[0];

        for (int i =1; i < numVect; i++)
        {
            result = result+workVec[i];
        }
        cout<<result<<" ";

}

void subtractVectors(int numVect, Vector3D* workVec)
{
    Vector3D result=workVec[0];

        for (int i =1; i < numVect; i++)
        {
            result = result-workVec[i];
        }
        cout<<result<<" ";

}

void negateVectors(int numVect, Vector3D* workVec)
{
    for (int i = 0; i<numVect; i++)
        {
           cout<< -workVec[i] ;
        }
}

void multiplyVectWithNum (int numVect, Vector3D* workVect, int numToMult)
{

            for (int i = 0; i<numVect; i++)
            {
               cout<< workVect[i] * numToMult ;
            }
}

void multiplyNumWithVect (int numVect, Vector3D* workVect, int numToMult)
{

            for (int i = 0; i<numVect; i++)
            {
               cout<< workVect[i] * numToMult ;
            }

}

std::istream & operator >> (std::istream & iStream, Vector3D & vec)
{
	char bracket1,bracket2, comma1, comma2;

	iStream >> bracket1 >> vec.x >> comma1 >> vec.y >> comma2 >> vec.z >> bracket2;                //checks if the input is correct

	if (bracket1 == '(' && bracket2 == ')' && comma1 == ',' && comma2 == ',')
		return iStream;

}

std::ostream & operator<<(std::ostream & oStream, const Vector3D & vec)
{
		oStream << "(" << vec.x << "," << vec.y << "," << vec.z << ")";
		return oStream;
}



void test()
{
    string options;
	cin >> options;


    int numOfVectors;

    cin>>numOfVectors;


    Vector3D* inputVectors = new Vector3D [numOfVectors];

    for (int i = 0; i < numOfVectors; i++)
            cin >> inputVectors[i];



	if (options[0] == '+')
    {
        sumVectors(numOfVectors, inputVectors);
	}


	 if (options[0] == '-')
    {
		subtractVectors(numOfVectors, inputVectors);
	}


	if (options[0]=='N')
    {

    negateVectors (numOfVectors,inputVectors);

	}


	if (options[0]=='*')
    {
       if (options[1]=='0')
    {
        for (int i=0; i<numOfVectors; i++)
            cout<<Vector3D();
    }
       else
        {
            int i=0;
            int numToMult=0;
            int power=0;


            while (options[i+1] != '\0')
                ++i;

            for (int counter=i; i>0; --i)
            {
                numToMult+=(int)options[counter]-48*pow(10,power);
                ++power;
            }


            multiplyVectWithNum(numOfVectors, inputVectors , numToMult);
        }


	}


	 if (options[0]>='0' && options[0]<='9')
    {
        if (options[0]=='0')
    {
        for (int i=0; i<numOfVectors; i++)
            cout<<Vector3D();
    }
           else
           {
                int i=0;
                double numToMult=0;
                int power=0;


                while (options[i] != '*')
                    ++i;


                for (int counter=i; i>0; --i)
                {
                    numToMult+=(int)options[counter-1]-48*pow(10,power);
                    power++;
                }


               multiplyNumWithVect(numOfVectors, inputVectors,numToMult);

            }
	}

	 delete[] inputVectors;
}

int main()
{
	test();
	return 0;


}



