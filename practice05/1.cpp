/*
本题请注意排序方式。可以调用系统函数库中的排序，也可以自己实现。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Book{
	//请注意规范化，设置成员变量为私有
private:
	string name;
	string author;
	string ISBN;
	string time;
	bool isBorrowed;
public:
	//constructor
	Book(string _name, string _author, string _ISBN, string _time) :name(_name), author(_author), ISBN(_ISBN), time(_time){
		isBorrowed = false;	
	}
	//通过成员函数来获得成员变量
	string getname();
	string getauthor();
	string getISBN();
	string gettime();
	void borrowBook();
	void returnBook();
	
	//自定义比较函数，ISBN从小到大排序
	bool operator < (const Book & b){
		return ISBN < b.ISBN;
	}
	//重载输出函数
	friend ostream & operator << (ostream & os, Book & b);
};
string Book::getname(){
	return name;
}
string Book::getauthor(){
	return author;
}
string Book::getISBN(){
	return ISBN;
}
string Book::gettime(){
	return time;
}
void Book::borrowBook(){
	isBorrowed = true;
}
void Book::returnBook(){
	isBorrowed = false;
}
ostream & operator <<(ostream & os, Book & b){
	os << b.name << " " << b.author << " " << b.ISBN << " " << b.time << endl;
	return os;
}

int main(){
	vector<Book> vec;
	string _name, _author, _ISBN, _time;
	//输入
	while (cin >> _name >> _author >> _ISBN >> _time){
		vec.push_back(Book(_name, _author, _ISBN, _time));
	}
	//排序
	sort(vec.begin(), vec.end());
	for (auto & v : vec){
		cout << v;
	}
	//system("pause");
	return 0;
}