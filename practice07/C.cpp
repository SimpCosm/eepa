/*
 * File Name: C.cpp
 * Author: Houmin <houmin.wei@pku.edu.cn>
 * Created: 28/03/2020
 * Description:
 *  Solution for char count. Original
 * problem is [here](http://eepa.openjudge.cn/2020practice07/C).
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	char c;
	int num[11] = { 0 };
	while (cin.get(c))
	{
		if (c == '\n')      continue;
		if (isspace(c))     num[0]++;
		if (isalpha(c))     num[1]++;
		if (isdigit(c))     num[2]++;
		if (isxdigit(c))    num[3]++;
		if (isupper(c))     num[4]++;
		if (islower(c))     num[5]++;
		if (isalnum(c))     num[6]++;
		if (iscntrl(c))     num[7]++;
		if (ispunct(c))     num[8]++;
		if (isprint(c))     num[9]++;
		if (isgraph(c))     num[10]++;
	}
	for (int i = 0; i < 11; i++)
		cout << num[i] << endl;
	return 0;
}
