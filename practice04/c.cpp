/**
 * @file c.cpp
 * @author shiwenhao
 * @brief 计算价格
 * @version 0.1
 * @date 2020-03-11
 *
 * @copyright Copyright (c) 2020
 *
描述
输入是两行，分别是price和weight，计算出对应的总价格(所有的price[i]*weight[i]之和)

输入
两行，分别是price和weight，测试样例保证两行的数目一致
输出
输出总价格
样例输入
13 12 22
1 2 3
样例输出
103

 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;  //慎用

vector<int> GetNumbers(const string& str) {
  vector<int> nums;
  istringstream is(str);
  int num;
  while (is >> num) nums.push_back(num);
  return nums;
}

int main() {
  string price_str, weight_str;
  // 严谨的做法应当按行读入并对读入的数据做处理。取巧的做法可以读入所有输入，前一半是价格，后一半是重量
  getline(cin, price_str);
  getline(cin, weight_str);
  vector<int> prices = GetNumbers(price_str);
  vector<int> weights = GetNumbers(weight_str);
  if (prices.size() != weights.size()) {
    throw runtime_error("number of prices and weights not equal");
  }
  int cost = 0;
  for (int i = 0; i < (int)prices.size(); ++i) cost += weights[i] * prices[i];
  cout << cost << endl;
  return 0;
}