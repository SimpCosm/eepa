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
//define Int
class Int {
private:

	int num;
public:
	//constructor
	Int(int n) :num(n) {}; 
	Int(){
		num = 0;
	}
	//copy constructor
	Int(const Int& i) :num(i.num) {};
	
	friend ostream& operator <<(ostream& os, Int& a){
		os << a.num;
		return os;
	}
	friend istream& operator >>(istream& is, Int& a){
		is >> a.num;
		return is;
	}


	Int operator + (const Int& i) { 
		return Int{ num + i.num };
	}; 
	Int operator - (const Int& i) { 
		return Int{ num - i.num };
	};
	Int operator * (const Int& i) { 
		return Int{ num * i.num };
	};
	Int operator / (const Int& i) { 
		return Int{ num / i.num };
	};
	Int& operator = (const Int& i) {
		num = i.num;
		return *this;
	};
	

};


int main() {
	//for test
	Int a = 1;
	Int b = a;
	Int c;
	c = a + b;
	cin >> a >> b;
	cout << a + b << endl;
	cout << c << endl;
	//system("pause");
	return 0;
}
