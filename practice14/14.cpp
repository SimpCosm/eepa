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
template<class Elem>
struct Link
{
	Link* prev; 
	Link* next; 
	Elem val; 
	Link(Elem v) :val(v){
		prev = NULL;
		next = NULL;
	}
};

template<class Elem> class List {
	Link<Elem>* first; 
	Link<Elem>* last; 
public:
	List() : first(new Link<Elem>(0)), last(first) {}
	Link<Elem>* begin() { return first; }
	Link<Elem>* end() { return last; }

	void push_front(const Elem& v); 
	void pop_front(); 
	void print();
};

template<class Elem>
void List<Elem>::push_front(const Elem& v) {
	Link<Elem>* p = new Link<Elem>(v);
	
	p->next = first;
	p->prev = NULL;
	p->val = v;
	first->prev = p;
	//DO NOT FORGET THIS
	first = p;
}

template<class Elem>
void List<Elem>::pop_front() {
	if (first != last)
	{
		Link<Elem>* p = first->next;
		p->prev = NULL;
		
		delete[]first;
		first = p;
	}
}
template<class Elem>
void List<Elem>::print(){
	Link<Elem> *cur = first;
	while (cur != NULL){
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	return;
}
int main() {
	// for test
	
	// test push_front()
	List<int> ll;
	ll.push_front(1);
	ll.push_front(2);
	ll.push_front(3);
	ll.print();
	//test pop_front()
	ll.pop_front();
	ll.pop_front();
	ll.print();
	system("pause");
	return 0;
}
