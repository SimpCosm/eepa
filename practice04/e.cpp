/**
 * @file e.cpp
 * @author shiwenhao
 * @brief 字符串长度
 * @version 0.1
 * @date 2020-03-11
 *
 * @copyright Copyright (c) 2020
 *
描述
编写一个函数，接受一个vector的参数，返回一个vector，其中每个元素值是对应字符串长度

此外，还需要找出最长和最短的字符串，以及字典序第一个和最后一个字符串

输入
输入的vector
输出
输出有两行
第一行是vector
第二行是最长和最短的字符串，以及字典序第一个和最后一个字符串，以空格分隔
样例输入
beautiful gorgeous nice great happy
样例输出
9 8 4 5 5
beautiful nice beautiful nice

PS: 注意读题目要求
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> GetLength(const vector<string>& str_vec) {
  vector<int> length_vec(str_vec.size());  // 建议提前分配内存，以提高运行效率
  for (int i = 0; i < (int)str_vec.size(); ++i)
    length_vec[i] = (int)str_vec[i].size();
  return length_vec;
}

int main() {
  vector<string> vec_str;
  string str;
  while (cin >> str) vec_str.push_back(str);
  vector<int> vec_length = GetLength(vec_str);
  for (int i = 0; i < (int)vec_length.size(); ++i) {
    cout << vec_length[i] << (i == vec_length.size() - 1 ? "" : " ");
  }
  cout << endl;
  int longgest_index = 0;
  int shortest_index = 0;
  int smallest_index = 0;
  int largest_index = 0;
  for (int i = 1; i < vec_str.size(); ++i) {
    if (vec_length[i] > vec_length[longgest_index]) longgest_index = i;
    if (vec_length[i] < vec_length[shortest_index]) shortest_index = i;
    if (vec_str[i] < vec_str[smallest_index]) smallest_index = i;
    if (vec_str[i] > vec_str[largest_index]) largest_index = i;
  }
  cout << vec_str[longgest_index] << ' ' << vec_str[shortest_index] << ' '
       << vec_str[smallest_index] << ' ' << vec_str[largest_index] << endl;
  return 0;
}