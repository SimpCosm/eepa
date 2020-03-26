/*
 * File Name: A.cpp
 * Author: Houmin <houmin.wei@pku.edu.cn>
 * Created: 28/03/2020
 * Description:
 *  Solution for positional notation change. Original
 * problem is [here](http://eepa.openjudge.cn/2020practice07/A).
 */
#include <iostream>
using namespace std;

#define __HEX 0
#define __OCT 1
#define __DEC 2
#define __ERR 10

int format(istream & is)
{
	while (is.peek() == ' ' || is.peek() == '\n')
	{
		is.get();
	}
	char temp;
	if (is.peek() == '0')
	{
		temp = is.get();
		if (is.peek() == 'x')
		{
			is.putback(temp);
			return __HEX;
		}
		else
		{
			is.putback(temp);
			return __OCT;
		}
	}
	else if (isdigit(is.peek()))
	{
		return __DEC;
	}
	else
	{
		return __ERR;
	}
}

int main()
{
	int t;
	while (cin)
	{
		switch (format(cin))
		{
		case __HEX:cin >> hex >> t; break;
		case __OCT:cin >> oct >> t; break;
		case __DEC:cin >> dec >> t; break;
		case __ERR:return 0;
		default:
			cerr << "undefined format!\n";
		}
		cout << dec << t << endl;
	}
	return 0;
}
