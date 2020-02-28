/*
 * File Name: C.cpp
 * Author: Houmin <houmin.wei@pku.edu.cn>
 * Created: 22/02/2020
 * Description:
 *  Solution for [the king's reward](http://eepa.openjudge.cn/2020practice01/C)
 */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
 * It's simple, just pay attention to number arrange of int/long
 */
int grids(long long grains) {
    int grid = 1;
    long long current = 1;
    while (grains > current) {
        grid++;
        current = pow(2, grid) - 1;
    }
    return grid;
}

int main() {
    long long grains;
    cin >> grains;
    cout << grids(grains) << endl;
    return 0;
}

