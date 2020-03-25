/*
请注意分数计算时候的约分操作。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

class Fraction{
	//分子和分母
	int numerator;
	int denominator;
public:
	Fraction(){}
	Fraction(int _numberator, int _denominator) :numerator(_numberator), denominator(_denominator){}
	//重载四种运算
	Fraction operator +(Fraction &f);
	Fraction operator -(Fraction &f);
	Fraction operator *(Fraction &f);
	Fraction operator /(Fraction &f);
	int getnumerator() const{ return numerator; }
	int getdenominator() const{ return denominator; }
	//分数化简
	void simplify();
	int gcd(int _numerator, int _denominator);//辗转相除得到分子分母最大公约数

};

Fraction Fraction::operator +(Fraction &f){
	int num1 = getnumerator() * f.getdenominator() + getdenominator() * f.getnumerator();
	int num2 = getdenominator() * f.getdenominator();
	Fraction ret(num1, num2);
	ret.simplify();
	return ret;
}

Fraction Fraction::operator -(Fraction &f){
	int num1 = getnumerator() * f.getdenominator() - getdenominator() * f.getnumerator();
	int num2 = getdenominator() * f.getdenominator();
	Fraction ret(num1, num2);
	ret.simplify();
	return ret;
}

Fraction Fraction::operator *(Fraction &f){
	int num1 = getnumerator() *  f.getnumerator();
	int num2 = getdenominator() * f.getdenominator();
	Fraction ret(num1, num2);
	ret.simplify();
	return ret;
}

Fraction Fraction::operator /(Fraction &f){
	int num1 = getnumerator() *  f.getdenominator();
	int num2 = getdenominator() * f.getnumerator();
	Fraction ret(num1, num2);
	ret.simplify();
	return ret;
}

//化简函数，分子分母约分
void Fraction::simplify(){
	int num = gcd(numerator, denominator);
	//防止分母出现负数
	if (num < 0) num = abs(num);
	numerator = numerator / num;
	denominator = denominator / num;
}

//辗转相除法求分子分母最大公约数
int Fraction::gcd(int _numerator, int _denominator){
	if (_denominator == 0) return _numerator;
	else return gcd(_denominator, _numerator % _denominator);
}

int main(){

	int num1, num2, num3, num4;//两个分数分子分母
	char ch1, ch2; // 两个/
	char op; //操作符
	cin >> num1 >> ch1 >> num2 >> op >> num3 >> ch2 >> num4;
	Fraction f1(num1, num2);
	Fraction f2(num3, num4);
	Fraction ret;
	switch (op)
	{
	case '+':
		ret = f1 + f2;
		break;
	case '-':
		ret = f1 - f2;
		break;
	case '*':
		ret = f1 * f2;
		break;
	case '/':
		ret = f1 / f2;
		break;
	default:
		break;
	}
	double ans = (double)ret.getnumerator() / ret.getdenominator();
	cout << ret.getnumerator() << '/' << ret.getdenominator() << '(' << fixed << setprecision(6) << ans << ')' << endl;
	//system("pause");
	return 0;
}