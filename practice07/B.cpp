/*
 * File Name: B.cpp
 * Author: Houmin <houmin.wei@pku.edu.cn>
 * Created: 28/03/2020
 * Description:
 *  Solution for blank change. Original
 * problem is [here](http://eepa.openjudge.cn/2020practice07/B).
 */
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void replace(string &s, string src, string dst)
{
	int p;
	while ( (p = s.find(src))  != -1)
	{
		s.replace(p, src.size(), dst);
	}
}
void punclear(string &s)
{
	for (int i=1;i<s.size()-1;i++)
	{
		if (s[i] == '-' && isalpha(s[i - 1]) && isalpha(s[i + 1])) continue;
		if (ispunct(s[i])) s[i] = ' ';
	}
}

int main()
{
	string s;
	getline(cin, s);
	replace(s, "don't", "do not");
	replace(s, "can't", "can not");
	punclear(s);
	cout << s;;
}
