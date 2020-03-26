/*
 * File Name: D.cpp
 * Author: Houmin <houmin.wei@pku.edu.cn>
 * Created: 28/03/2020
 * Description:
 *  Solution for word search. Original
 * problem is [here](http://eepa.openjudge.cn/2020practice07/D).
 */
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string target;
    getline(cin, target);
    int cnt = 0;
    string line;
    while (getline(cin, line))
    {
        cnt++;
        if (line.find(target)!=line.npos)
            cout << cnt << " " << line << endl;
    }
    return 0;
}

