#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <math.h>

class Fraction
{
private:
	int num;
	int denom;
public:
	Fraction();
	Fraction(int);
	Fraction(int, int);
	void normalize();
	double value();
	Fraction& inverse();
	friend std::ostream& operator<< (std::ostream& os, const Fraction& newFraction);
	friend std::istream& operator>> (std::istream& is, Fraction& newFraction);
	friend Fraction operator+(const Fraction& F1, const Fraction& F2);
	friend Fraction operator-(const Fraction& F1, const Fraction& F2);
	friend Fraction operator*(const Fraction& F1, const Fraction& F2);
	friend Fraction operator/(const Fraction& F1, const Fraction& F2);

};
int main()
{
	Fraction myfraction1;
	Fraction myfraction2;
	std::cout << "First fraction is: ";
	std::cin >> myfraction1;
	std::cout << "Second Fraction is: ";
	std::cin >>  myfraction2;
	Fraction sum = myfraction1 + myfraction2;
	std::cout << myfraction1 << " + " << myfraction2 << " = " << sum << std::endl;
	Fraction sub = myfraction1 - myfraction2;
	std::cout << myfraction1 << " - " << myfraction2 << " = " << sub << std::endl;
	Fraction mult = myfraction1 * myfraction2;
	std::cout << myfraction1 << " * " << myfraction2 << " = " << mult << std::endl;
	Fraction div = myfraction1 / myfraction2;
	std::cout << myfraction1 << " / " << myfraction2 << " = " << div << std::endl;
	std::cout << myfraction1 << " = " << myfraction1.value() << std::endl;
	std::cout << myfraction2 << " = " << myfraction2.value() << std::endl;
	std::cout << "Normalized fraction of " << myfraction1 << " is ";
	myfraction1.normalize();
	std::cout << myfraction1 << std::endl;
	return 0;
}
Fraction::Fraction()
{
	num = 0;
	denom = 1;
}
Fraction::Fraction(int newNum)
{
	num = newNum;
	denom = 1;
}
Fraction::Fraction(int newNum, int newDenom)
{
	num = newNum;
	denom = newDenom;
}
void Fraction::normalize()
{
	int &e = (num < denom) ? num : denom;
	for (int i = 2; i <= abs(e); i++)
		while ((num % i == 0) && (denom % i == 0))
		{
			num /= i;
			denom /= i;
		}
	if (num == 0)
	{
		denom = 1;
	}
	if (denom < 0)
	{
		num *= (-1);
		denom *= (-1);
	}
}
double Fraction::value()
{
	double result = double(num) / double(denom);
	return result;
}
Fraction& Fraction::inverse()
{
	int temp;
	temp = num;
	num = denom;
	denom = temp;
	return *this;
}
Fraction operator+(const Fraction& F1, const Fraction& F2)
{
	int top = (F1.num * F2.denom) + (F2.num * F1.denom);
	int bottom = F1.denom * F2.denom;
	Fraction sum(top, bottom);
	return sum;
}
Fraction operator-(const Fraction& F1, const Fraction& F2)
{
	int top = (F1.num * F2.denom) - (F2.num * F1.denom);
	int bottom = F1.denom * F2.denom;
	Fraction sub(top, bottom);
	return sub;
}
Fraction operator*(const Fraction& F1, const Fraction& F2)
{
	int top = F1.num * F2.num;
	int bottom = F1.denom * F2.denom;
	Fraction mult(top, bottom);
	return mult;
}
Fraction operator/(const Fraction& F1, const Fraction& F2)
{
	int top = F1.num * F2.denom;
	int bottom = F1.denom * F2.num;
	Fraction div(top, bottom);
	return div;

}
std::ostream& operator<< (std::ostream& os, const Fraction& newFraction)
{
	if (newFraction.denom == 1)
	{
		os << newFraction.num;
	}
	else
	{
		os << newFraction.num << '/' << newFraction.denom;
	}
	return os;
}
std::istream& operator>> (std::istream& is, Fraction& newFraction)
{
	int top;
	int bottom = 1;
	int slash;
	is >> top;
	slash = is.peek();
	if (is && slash == '/')
	{
		is.get();
		is >> bottom;
		newFraction = Fraction(top, bottom);
	}
	else
	{
		is.putback(is && slash);
		newFraction = Fraction(top);
	}
	return is;
}
