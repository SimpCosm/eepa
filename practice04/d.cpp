/**
 * @file d.cpp
 * @author shiwenhao
 * @brief 最大元素
 * @version 0.1
 * @date 2020-03-11
 *
 * @copyright Copyright (c) 2020
 *
描述
编写一个maxv函数，返回一个vector中的最大元素

你的maxv函数应该形如：

int maxv(const vector<int>& v) {}



输入
一个数组
输出
输出vector中的最大元素
样例输入
1 32 43 23 3222 32 12221 3222
样例输出
12221
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int MaxV(const vector<int>& vec) {
  // return *max_element(vec.begin(), vec.end()); // 其实C++有内置函数
  if (vec.empty()) {
    return -1;
  }
  int max_val = vec[0];
  for (int i = 1; i < (int)vec.size(); ++i) {
    max_val = max(max_val, vec[i]);
  }
  return max_val;
}

int main() {
  vector<int> vec;
  int val;
  while (cin >> val) vec.push_back(val);
  cout << MaxV(vec) << endl;
  return 0;
}