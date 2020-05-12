#include <iostream>
#include <cmath>
#include<fstream>
#include<sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include<iomanip>
using namespace std;
template <typename T>
class Number {
private:
	T num;
public:
	Number(T n) :num(n) {};
	Number(){
		num = 0;
	}
	//copy constructor
	Number(const Number& i) :num(i.num) {};

	template <class T>
	friend ostream& operator <<(ostream& os, const Number<T> & i) {
		os << i.num;
		return os;
	}
	template<class T>
	friend istream& operator >>(istream& is, Number<T>& i) {

		is >> i.num;
		return is;
	}

	Number operator + (const Number& i) {
		return Number{ num + i.num };
	};
	Number operator - (const Number& i) {
		return Number{ num - i.num };
	};
	Number operator * (const Number& i) {
		return Number{ num * i.num };
	};
	Number operator / (const Number& i) {
		return Number{ num / i.num };
	};
	Number& operator = (const Number& i) {
		num = i.num;
		return *this;
	};

};


int main() {
	//for test
	Number<double>x = 2.0;
	Number <double>y = x;
	Number<double>z;
	z = (x * y) / y;
	cin >> x >> y;
	cout << (x + y) / z << endl;
	system("pause");
	return 0;

}
