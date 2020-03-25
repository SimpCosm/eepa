/*
本题需注意：
1.罗马数字和阿拉伯数字转换
2.重载输入输出
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;


class RomanInt{
public:
	string romanstr;
	int romanint;
	map<char, int> dict;//罗马数字中字符和阿拉伯数字转换表
	RomanInt(){
		dict.insert(make_pair('I', 1));
		dict.insert(make_pair('V', 5));
		dict.insert(make_pair('X', 10));
		dict.insert(make_pair('L', 50));
		dict.insert(make_pair('C', 100));
		dict.insert(make_pair('D', 500));
		dict.insert(make_pair('M', 1000));
	}
	RomanInt(string _romanstr) :romanstr(_romanstr){
		dict.insert(make_pair('I', 1));
		dict.insert(make_pair('V', 5));
		dict.insert(make_pair('X', 10));
		dict.insert(make_pair('L', 50));
		dict.insert(make_pair('C', 100));
		dict.insert(make_pair('D', 500));
		dict.insert(make_pair('M', 1000));
	}
	int asInt();
	friend istream & operator >>(istream&, RomanInt&);
	friend ostream & operator <<(ostream&, RomanInt&);

};

int RomanInt::asInt(){
	int ret = 0;
	for (int i = 0; i < romanstr.size(); i++){
		//左边字符代表的数字比右边大，则要加和
		if (i >= romanstr.size() - 1 || dict[romanstr[i]] >= dict[romanstr[i + 1]]){
			ret += dict[romanstr[i]];
		}
		//左边字符代表的数字比右边小，则要减
		else{
			ret -= dict[romanstr[i]];
		}
	}
	romanint = ret;
	return ret;
}

istream &operator >>(istream &is, RomanInt &r){
	string str;
	is >> str;
	r.romanstr = str;
	return is;
}
ostream &operator <<(ostream &os, RomanInt &r){
	os << "Roman r equals: " << r.asInt() << endl;
	return os;
}

int main(){
	RomanInt r1, r2;
	cin >> r1 >> r2;
	int ret1 = r1.asInt();
	int ret2 = r2.asInt();
	//重载输出如下所示，作业中请有所体现：
	//cout << r1;
	//cout << r2;
	cout << r1.romanint + r2.romanint << endl;
	//system("pause");
	return 0;
}	