/*
请注意枚举类型输入输出的处理，与枚举类型的使用。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

enum class Genre {      //五种枚举类
	fiction = 1, nonfiction, periodical, biography, children
};
class Book{
private:
	string name;
	string author;
	string ISBN;
	string time;
	Genre type;
	bool isBorrowed;
public:
	//constructor
	Book(string _name, string _author, string _ISBN, string _time, Genre _type) :name(_name), author(_author), ISBN(_ISBN), time(_time), type(_type){
		isBorrowed = false;
	}
	string getname() const;
	string getauthor() const;
	string getISBN() const;
	string gettime() const;
	//add get type of the book
	Genre gettype() const;
	void borrowBook();
	void returnBook();

	//自定义比较函数，ISBN从小到大排序
	bool operator < (const Book & b){
		return ISBN < b.ISBN;
	}
	friend bool operator == (const Book &a, const Book &b);
	friend bool operator != (const Book &a, const Book &b);
	//重载输出函数
	friend ostream & operator << (ostream & os, const Book & b);
};
string Book::getname() const{
	return name;
}
string Book::getauthor() const{
	return author;
}
string Book::getISBN() const{
	return ISBN;
}
string Book::gettime() const{
	return time;
}
Genre Book::gettype() const{
	return type;
}

void Book::borrowBook(){
	isBorrowed = true;
}
void Book::returnBook(){
	isBorrowed = false;
}

bool operator == (const Book &a, const Book &b){
	return a.getISBN() == b.getISBN();
}

bool operator != (const Book &a, const Book &b){
	return a.getISBN() != b.getISBN();
}

ostream & operator <<(ostream & os, const Book & b){
	os << b.name << " " << b.author << " " << b.ISBN << " " << b.time << " ";
	//输出枚举类型
	switch (b.type)
	{
	case Genre::fiction:
		os << "fiction" << endl;
		break;
	case Genre::nonfiction:
		os << "nonfiction" << endl;
		break;
	case Genre::biography:
		os << "biography" << endl;
		break;
	case Genre::children:
		os << "children" << endl;
		break;
	case Genre::periodical:
		os << "periodical" << endl;
		break;
	default:
		break;
	}
	return os;
}

int main(){
	vector<Book> vec;
	string _name, _author, _ISBN, _time, _type;
	Genre enumtype;//枚举类型
	//输入
	while (cin >> _name >> _author >> _ISBN >> _time >> _type){
		switch (_type[0])
		{
		case 'f':
			enumtype = Genre::fiction;
			break;
		case 'n':
			enumtype = Genre::nonfiction;
			break;
		case 'p':
			enumtype = Genre::periodical;
			break;
		case 'b':
			enumtype = Genre::biography;
			break;
		case 'c':
			enumtype = Genre::children;
			break;
		default:
			break;
		}
		vec.push_back(Book(_name, _author, _ISBN, _time, enumtype));
	}
	//排序
	sort(vec.begin(), vec.end());
	for (auto & v : vec){
		cout << v;
	}

	//system("pause");
	return 0;
}